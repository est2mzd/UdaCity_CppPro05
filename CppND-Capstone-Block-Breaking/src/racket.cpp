#include "racket.h"
#include <cmath>
#include <iostream>
#include <algorithm>

Racket::Racket()
{
    init();
}

Racket::~Racket()
{
  std::cout << "Racket::~Racket()" <<std::endl;
}

void Racket::init()
{
    std::cout << "Racket : Initializing" << std::endl;

    // initial condition
    direction = RacketDirection::kNone;
    pos_x  = _window_width  / 4.0;
    pos_y  = _window_height / 2.0;
    vel_x  = 10.0;
    vel_y  = 0.0;
    width  = 200.0;
    height = 20.0;

    running = true;
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

void Racket::simulate()
{
    std::cout << "Racket::simulate" << std::endl;
    // launch render function in a thread
    threads.emplace_back(std::thread(&Racket::calc, this));
}


void Racket::calc()
{
    std::cout << "Racket::calc()" << std::endl;
    
    while(running)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        // get key input 
        HandleInput(); 

        // update position
        updatePosition();

        // Wall : update velocity for next simulation
        checkCollisionToWall();
    }
}


void Racket::HandleInput()
{
  SDL_Event e;

  while (SDL_PollEvent(&e)) 
  {
    if (e.type == SDL_QUIT) 
    {
      running = false;
    } 
    else if (e.type == SDL_KEYDOWN) 
    {
      switch (e.key.keysym.sym) {
        case SDLK_LEFT:
          this->direction = RacketDirection::kLeft;
          break;

        case SDLK_RIGHT:
          this->direction = RacketDirection::kRight;
          break;

        default:
          this->width = RacketDirection::kNone;
          break;
      }
    }
  }
}