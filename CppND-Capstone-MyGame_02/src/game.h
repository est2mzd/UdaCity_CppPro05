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
  Game();
  void Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration);
  int GetScore() const;

 private:
  int score{0};
  void Update();
};

#endif