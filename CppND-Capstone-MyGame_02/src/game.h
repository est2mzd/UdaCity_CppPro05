#ifndef GAME_H
#define GAME_H

// #include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "ball.h"
#include "racket.h"
#include "block_multi.h"
#include "collision_check.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;

 private:

  Ball  ball;
  Racket racket;
  Block_Multi blocks;
  Collision_Check checker;

  int score{0};

  void Update();
};

#endif