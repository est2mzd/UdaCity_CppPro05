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
    _pos_x  = _window_width  / 4.0;
    _pos_y  = _window_height / 2.0;
    _vel_x  = 0.1*10*10;
    _vel_y  = 0.0;
    _width  = 200.0;
    _height = 20.0;
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
            _pos_x -= _vel_x;
            break;

        case RacketDirection::kRight:
            _pos_x += _vel_x;
            break;

        case RacketDirection::kNone:
            _pos_x = _pos_x;
            break;            
    }
}


void Racket::checkCollisionToWall()
{
    if ( _pos_x < 0 )
    {
        _pos_x = 0;
    }
    else if( (_pos_x + _width) > _window_width)
    {
        _pos_x = _window_width - _width;
    }
}