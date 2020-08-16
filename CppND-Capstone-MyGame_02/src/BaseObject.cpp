#include <algorithm>
#include <iostream>
#include <chrono>
#include "BaseObject.h"

// init static variable
int BaseObject::_id_counter = 0;

std::mutex BaseObject::_mtx;

int BaseObject::_window_width  = 640;
int BaseObject::_window_height = 640;

// constructor
BaseObject::BaseObject()
{
    _type = ObjectType::none;
    _id   = _id_counter++;
    setWindowSize(640, 640);
}


// destructor
BaseObject::~BaseObject()
{
    
    // set up thread barrier before this object is destroyed
    // std::for_each( threads.begin(), 
    //                threads.end(),
    //                [](std::thread &t){ t.join(); } 
    //             );
    
}

void BaseObject::setWindowSize(int width, int height)
{
    _window_width  = width;
    _window_height = height;
}

void BaseObject::render(SDL_Renderer *sdl_renderer, SDL_Rect &block)
{
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  block.w = width;  // set block width
  block.h = height;           // set block height
  block.x = pos_x;
  block.y = pos_y;
  SDL_RenderFillRect(sdl_renderer, &block);    
}

void BaseObject::updatePosition()
{
    pos_x += vel_x;
    pos_y += vel_y;
}    