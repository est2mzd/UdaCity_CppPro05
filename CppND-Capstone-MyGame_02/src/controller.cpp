#include "controller.h"
#include <iostream>
#include "SDL.h"


// This is the controller of key-input, so I want to use this to move racket.
// This class does not controll the ball movement.

void Controller::HandleInput(bool &running,  std::shared_ptr<Racket> racket) const 
{
  SDL_Event e;

  // init 
  racket->direction = RacketDirection::kNone;

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
          racket->direction = RacketDirection::kLeft;
          break;

        case SDLK_RIGHT:
          racket->direction = RacketDirection::kRight;
          break;

        default:
          racket->direction = RacketDirection::kNone;
          break;
      }
    }
  }
}