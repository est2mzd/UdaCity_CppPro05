#include <algorithm>
#include <iostream>
#include <chrono>
#include "BaseObject.h"

// init static variable
int BaseObject::_id_counter_all = 0;

std::mutex BaseObject::_mtx;
bool BaseObject::running;

int BaseObject::_milli_sec_per_frame = (int)(1000/60);
int BaseObject::_window_width  = 300;
int BaseObject::_window_height = 300;

// constructor
BaseObject::BaseObject()
{
    _type = ObjectType::none;
    _id   = _id_counter_all++;
    _is_active = true;
    running = true;
}


// destructor
BaseObject::~BaseObject()
{
    std::cout << "BaseObject::~BaseObject" << std::endl;
    // set up thread barrier before this object is destroyed
    std::for_each( threads.begin(), 
                   threads.end(),
                   [](std::thread &t){ t.join(); } 
                );
    
}


void BaseObject::setWindowSize(int width, int height)
{
    _window_width  = width;
    _window_height = height;
}

void BaseObject::render(SDL_Renderer *sdl_renderer, SDL_Rect &block)
{
    if (_is_active)
    {
        SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        block.w = width;  // set block width
        block.h = height;           // set block height
        block.x = pos_x;
        block.y = pos_y;
        SDL_RenderFillRect(sdl_renderer, &block);    
    }
}


void BaseObject::updatePosition()
{
    pos_x += vel_x;
    pos_y += vel_y;
}    

void BaseObject::printWindowSize()
{
    std::cout << "Window : width = " << _window_width << " / height = " << _window_height << std::endl;
}