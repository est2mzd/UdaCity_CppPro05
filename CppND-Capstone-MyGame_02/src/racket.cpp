#include "racket.h"
#include <cmath>
#include <iostream>

Racket::Racket()
{
    setWindowSize(640, 640);

    // initial condition
    direction = RacketDirection::kNone;
    pos_x  = _window_width  / 4.0;
    pos_y  = _window_height / 2.0;
    vel_x  = 0.1*10*10;
    vel_y  = 0.0;
    width  = 100.0;
    height = 4.0;
}

void Racket::checkCollideToWall()
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


void Racket::UpdatePosition()
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

    // refrect at the wall
    checkCollideToWall();
}


void Racket::setWindowSize(int width, int height)
{
    _window_width  = width;
    _window_height = height;
}

void Racket::render(SDL_Renderer *sdl_renderer, SDL_Rect &block)
{
  //---------------------------------------------------------
  // Racket
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  block.w = width;  // set block width
  block.h = height;           // set block height
  block.x = pos_x;
  block.y = pos_y;
  SDL_RenderFillRect(sdl_renderer, &block);    
}