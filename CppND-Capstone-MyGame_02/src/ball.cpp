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

    setWindowSize(640, 640);

    // initial condition
    pos_x  = _window_width  / 3.0;
    pos_y  = _window_height / 2.0;
    vel_x  = -0.1*10*3;
    vel_y  = -0.1*10*3;
    radius = 5.0;
}

void Ball::render(SDL_Renderer *sdl_renderer, SDL_Rect &block)
{
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  block.w = radius*2.0;  // set block width
  block.h = radius*2.0;  // set block height
  block.x = pos_x;
  block.y = pos_y;
  SDL_RenderFillRect(sdl_renderer, &block);  
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

