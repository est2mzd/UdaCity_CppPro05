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
    pos_x  = _window_width  / 3.0;
    pos_y  = _window_height / 2.0;
    vel_x  = -3.0 * vel_coef;
    vel_y  = -1.0 * vel_coef;
    width  = 5.0;
    height = 5.0;
}


void Ball::update()
{
    // update position
    BaseObject::updatePosition();

    // Wall : update velocity for next simulation
    checkCollisionToWall();

}


bool Ball::checkCollisionX()
{
    float pos_center = pos_x + width;

    if ( (pos_center > (_window_width - width)) || (pos_center < width) ) 
        return true;

    return false;
}

bool Ball::checkCollisionY()
{
    float pos_center = pos_y + height;

    if ( (pos_center > (_window_height - height)) || (pos_center < height) )
        return true;

    return false;
}

void Ball::checkCollisionToWall()
{
    // refrect at the wall
    if (checkCollisionX())
    {
        vel_x = vel_x * (-1.0);
    }

    if (checkCollisionY())
    {
        vel_y = vel_y * (-1.0);
    }    

}