#include <algorithm>
#include <iostream>
#include <chrono>
#include "BaseObject.h"

// init static variable
int BaseObject::_id_counter = 0;

// std::mutex BaseObject::_mtx;

int BaseObject::_window_width;
int BaseObject::_window_height;

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

// getter / setter
void BaseObject::setPosition(float  x, float  y)
{
    _pos_x = x;
    _pos_y = y;
}

void BaseObject::getPosition(float &x, float &y)
{
    x = _pos_x;
    y = _pos_y;
}

void BaseObject::setVelocity(float  vx, float  vy)
{
    _vel_x = vx;
    _vel_y = vy;
}

void BaseObject::getVelocity(float &vx, float &vy)
{
    vx = _vel_x;
    vy = _vel_y;
}

void BaseObject::setSize(float  w, float  h)
{
    _width  = w;
    _height = h;
}

void BaseObject::getSize(float &w, float &h)
{
    w = _width;
    h = _height;
}

void BaseObject::setWindowSize(int width, int height)
{
    _window_width  = width;
    _window_height = height;
}

void BaseObject::render(SDL_Renderer *sdl_renderer, SDL_Rect &block)
{
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

  block.w = _width;  // set block width
  block.h = _height;           // set block height
  block.x = _pos_x;
  block.y = _pos_y;
  SDL_RenderFillRect(sdl_renderer, &block);    
}

template <class SPHEHE, class OTHEROBJ>
bool BaseObject::checkCollision(SPHEHE& ball, OTHEROBJ& other_obj)
{
    float ball_center_x  = ball._pos_x + ball._width;
    float ball_center_y  = ball._pos_y + ball._height;
    float obj_center_x   = other_obj._pos_x + other_obj._width/2.0;
    float obj_center_y   = other_obj._pos_y + other_obj._height/2.0;
    float diff_x         = ball_center_x - obj_center_x;
    float diff_y         = ball_center_y - obj_center_y;

    if ( fabs(diff_x) <= (ball._width + other_obj._width/2.0)  )
    {
        if ( fabs(diff_y) <= (ball._height + other_obj._height/2.0)  )
        {            
            // upper or bottom
            if (fabs(diff_x) <= other_obj._width/2.0)
            {
                if (diff_y >= 0)
                {
                    ball._vel_y =  fabs(ball._vel_y);
                }
                else
                {
                    ball._vel_y = - fabs(ball._vel_y);
                }
                
            }
            else // left of right
            {
                if (diff_x >= 0)
                {
                    ball._vel_x = fabs(ball._vel_x);
                }
                else
                {
                    ball._vel_x = - fabs(ball._vel_x);
                }
            }

            return true;
        }
    }

    return false;
}


void BaseObject::updatePosition()
{
    _pos_x += _vel_x;
    _pos_y += _vel_y;
}    