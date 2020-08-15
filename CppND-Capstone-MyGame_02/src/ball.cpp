#include "ball.h"
#include <cmath>
#include <iostream>

Ball::Ball()
{
    setWindowSize(640, 640);

    // initial condition
    pos_x  = _window_width  / 4.0;
    pos_y  = _window_height / 2.0;
    vel_x  = -0.1*10*3;
    vel_y  = -0.1*10*3;
    radius = 4.0;
}

bool Ball::checkCollisionX()
{
    float pos_center = pos_x + radius;

    if ( (pos_center > (_window_width - radius)) || (pos_center < radius) ) 
        return true;

    return false;
}

bool Ball::checkCollisionY()
{
    float pos_center = pos_y + radius;

    if ( (pos_center > (_window_height - radius)) || (pos_center < radius) )
        return true;

    return false;
}

void Ball::UpdatePosition()
{
    pos_x += vel_x;
    pos_y += vel_y;

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


void Ball::setWindowSize(int width, int height)
{
    _window_width  = width;
    _window_height = height;
}