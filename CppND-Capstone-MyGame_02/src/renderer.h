#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "ball.h"
#include "racket.h"
#include "block_multi.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, 
           const std::size_t screen_height,
           const std::size_t grid_width, 
           const std::size_t grid_height);
  ~Renderer();

  void Render(Ball ball, Racket racket,  Block_Multi blocks);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window   *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif