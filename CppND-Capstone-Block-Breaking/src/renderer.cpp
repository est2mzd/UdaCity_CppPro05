#include "renderer.h"
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

// void createWindow(int window_width, int window_height);

Renderer::Renderer() : _window_width{300}, _window_height{300}
{
  std::cout << "Renderer::Renderer()" << std::endl;
}

// destructor
Renderer::~Renderer() {

  std::cout << "Renderer::~Renderer()" <<std::endl;
  
  // set up thread barrier before this object is destroyed
  std::for_each( threads.begin(), 
                 threads.end(),
                 [](std::thread &t){ t.join(); } 
              );

  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}


void Renderer::createWindow(int screen_width, int screen_height)
{
  std::cout << "0. Renderer::createWindow()" << std::endl;
  this->_window_width  = screen_width;
  this->_window_height = screen_height;

  // Initialize SDL
  std::cout << "1. Initialize SDL" << std::endl;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  std::cout << "2. Create Window" << std::endl;
  sdl_window = SDL_CreateWindow("Block Breaking Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  std::cout << "3. Create renderer" << std::endl;
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  std::cout << "4. Created Window & renderer" << std::endl;
}



void Renderer::UpdateWindowTitle(int score, int fps) 
{
  std::string title{"Block Breaking Game Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}


void Renderer::simulate(std::vector<std::shared_ptr<Block>> blocks, 
                        std::vector<std::shared_ptr<Ball>> balls,
                        std::shared_ptr<Racket> racket,
                        std::size_t target_frame_duration)
{
    std::cout << "Renderer::simulate" << std::endl;
    // launch render function in a thread
    threads.emplace_back(std::thread(&Renderer::render, this, 
                         blocks, 
                         balls,
                         racket,
                         target_frame_duration
                         ));
}



void Renderer::render(   std::vector<std::shared_ptr<Block>> blocks, 
                         std::vector<std::shared_ptr<Ball>> balls,
                         std::shared_ptr<Racket> racket,
                         std::size_t target_frame_duration ) 
{
  std::cout << "Renderer::render" << std::endl;
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) 
  {
    //---------------------------------------------------------
    // pre - procedure
    frame_start = SDL_GetTicks();

    //---------------------------------------------------------
    // Rendering <Start>
    SDL_Rect draw_obj;

    // Clear screen
    SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF); // set color
    SDL_RenderClear(sdl_renderer);

    // Ball
    for( auto ball : balls){
      ball->render(sdl_renderer, draw_obj);
    }

    // Racket
    racket->render(sdl_renderer, draw_obj);

    // Blocks
    for( auto block : blocks){
      block->render(sdl_renderer, draw_obj);
    }
    
    // Update Screen
    SDL_RenderPresent(sdl_renderer);
    
    // Rendering <End>



    //---------------------------------------------------------
    // post - procedure
    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) 
    {
      UpdateWindowTitle(blocks.at(0)->score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) 
    {
      SDL_Delay(target_frame_duration - frame_duration);
    }


    // Finish procedure
    running = racket->running;
    // if (blocks.size() == blocks.at(0)->score)
    //   running = false;

  }
}