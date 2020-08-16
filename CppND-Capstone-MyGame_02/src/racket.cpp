#include "racket.h"
#include <cmath>
#include <iostream>

Racket::Racket()
{
    init();
}


void Racket::init()
{
    std::cout << "Racket : Initializing" << std::endl;

    // initial condition
    direction = RacketDirection::kNone;
    pos_x  = _window_width  / 4.0;
    pos_y  = _window_height / 2.0;
    vel_x  = 0.1*10*10;
    vel_y  = 0.0;
    width  = 200.0;
    height = 20.0;
}


void Racket::update()
{
    // update position
    this->updatePosition();

    // stop positoin
    checkCollisionToWall();
}


void Racket::updatePosition()
{
    // check key input
    switch (direction) {
        case RacketDirection::kLeft:
            pos_x -= vel_x;
            break;

        case RacketDirection::kRight:
            pos_x += vel_x;
            break;

        case RacketDirection::kNone:
            pos_x = pos_x;
            break;            
    }
}


void Racket::checkCollisionToWall()
{
    if ( pos_x < 0 )
    {
        pos_x = 0;
    }
    else if( (pos_x + width) > _window_width)
    {
        pos_x = _window_width - width;
    }
}