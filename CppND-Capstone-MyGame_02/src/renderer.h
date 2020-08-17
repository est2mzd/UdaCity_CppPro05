#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
// #include "controller.h"
#include "ball.h"
#include "racket.h"
#include "Block.h"

class Renderer : public std::enable_shared_from_this<Renderer>
{
 public:
  Renderer();
  ~Renderer();

  void createWindow(int window_width, int window_height);

  
  void UpdateWindowTitle(int score, int fps);


  void simulate(std::vector<std::shared_ptr<Block>> blocks, 
                std::vector<std::shared_ptr<Ball>> balls,
                std::shared_ptr<Racket> racket,
                std::size_t target_frame_duration
                );

  void render(  std::vector<std::shared_ptr<Block>> blocks, 
                std::vector<std::shared_ptr<Ball>> balls,
                std::shared_ptr<Racket> racket,
                std::size_t target_frame_duration
                );

 private:
  SDL_Window   *sdl_window;
  SDL_Renderer *sdl_renderer;

  // const std::size_t screen_width;
  // const std::size_t screen_height;

  int _window_width;
  int _window_height;

  std::vector<std::thread> threads;

};

#endif