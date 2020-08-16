#include "game.h"
#include <iostream>
#include "SDL.h"

Game::Game(std::size_t grid_width, std::size_t grid_height) 
{
  std::cout << "Game : Initializing" << std::endl;
}

void Game::Run(Controller const &controller, Renderer &renderer, std::size_t target_frame_duration) 
{
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;

  while (running) 
  {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, racket);
    Update();
    renderer.Render(ball, racket, blocks);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) 
    {
      renderer.UpdateWindowTitle(score, frame_count);
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
  }
}

#include <future>

void Game::Update() {

  // std::promise<void> prms;
  // std::future<void> ftr = prms.get_future();
  // std::thread t_1(xxx,xxx,xxx,xxx,);
  // checkResult(std::move(ftr));
  // t_1.join();

  // std::future<void> ftr = std::async(xxx,xxx,xxx);
  // ftr.get();

  ball.update();
  racket.update();
  checker.checkBallvsRacket(ball, racket);

  if (checker.checkBallvsBlocks(ball, blocks))
    score++;
}

int Game::GetScore() const { return score; }