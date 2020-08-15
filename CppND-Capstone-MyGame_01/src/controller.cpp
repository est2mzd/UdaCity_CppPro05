#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"


// this is the controller of key-input 
// so, I want to use this, to move racket
// this class does not controll the ball movement

void Controller::ChangeDirection(Snake &snake, Snake::Direction input, Snake::Direction opposite) const 
{
  if (snake.direction != opposite || snake.size == 1) 
    snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake &snake, Racket &racket) const 
{
  SDL_Event e;

  // init 
  racket.direction = RacketDirection::kNone;

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
          racket.direction = RacketDirection::kLeft;
          break;

        case SDLK_RIGHT:
          racket.direction = RacketDirection::kRight;
          break;

        default:
          racket.direction = RacketDirection::kNone;
          break;
      }
    }
  }
}