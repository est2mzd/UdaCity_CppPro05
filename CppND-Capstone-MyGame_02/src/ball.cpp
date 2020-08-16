#include "ball.h"
#include <cmath>
#include <iostream>

Ball::Ball()
{
    init();
}

void Ball::init()
{
    std::cout << "Ball : Initializing" << std::endl;

    float vel_coef = 1/1.0;

    // initial condition
    _pos_x  = _window_width  / 3.0;
    _pos_y  = _window_height / 2.0;
    _vel_x  = -3.0 * vel_coef;
    _vel_y  = -1.0 * vel_coef;
    _width  = 5.0;
    _height = 5.0;
}


void Ball::update(Racket& racket)
{
    // update position
    BaseObject::updatePosition();

    // Wall : update velocity for next simulation
    checkCollisionToWall();

    // Racket : update velocity for next simulation
    BaseObject::checkCollision<Ball, Racket>(*this, racket);
}

// template bool BaseObject::checkCollision<Ball, Racket>(Ball&, Racket&);


bool Ball::checkCollisionX()
{
    float pos_center = _pos_x + _width;

    if ( (pos_center > (_window_width - _width)) || (pos_center < _width) ) 
        return true;

    return false;
}

bool Ball::checkCollisionY()
{
    float pos_center = _pos_y + _height;

    if ( (pos_center > (_window_height - _height)) || (pos_center < _height) )
        return true;

    return false;
}

void Ball::checkCollisionToWall()
{
    // refrect at the wall
    if (checkCollisionX())
    {
        _vel_x = _vel_x * (-1.0);
    }

    if (checkCollisionY())
    {
        _vel_y = _vel_y * (-1.0);
    }    

}


