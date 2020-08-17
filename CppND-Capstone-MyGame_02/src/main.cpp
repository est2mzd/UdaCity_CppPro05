#include <iostream>
#include <algorithm>
// #include "controller.h"
#include "renderer.h"

#include "BaseObject.h"

#include <thread>
#include <chrono>
#include <vector>
#include "collision_check.h"
#include "Block.h"
#include "ball.h"
#include "racket.h"

void createBlocks(std::vector<std::shared_ptr<Block>> &blocks, 
                  int window_width, int window_height, 
                  int num_row, int num_col);

void createBalls(std::vector<std::shared_ptr<Ball>> &balls, 
                 int window_width, int window_height, 
                 int num_ball, float velocity,
                 std::vector<std::shared_ptr<Collision_Check>> &checkers);

// void createBlocks(std::vector<std::shared_ptr<Block>> &, int, int, int, int);
// void createBalls(std::vector<std::shared_ptr<Ball>> &, int, int, int, float);

int main() 
{
  // user input parameters < Start >
  int frames_per_sec = 60;
  int window_width   = 640;
  int window_height  = 640;

  int num_row_blocks  =  2;
  int num_col_blocks  = 10;
  int num_ball        = 5;
  float velocity_ball = 1.0;
  // user input parameters < End >
  
  int milli_sec_per_frame = 1000 / frames_per_sec;

  // set widow size (static variable)
  BaseObject::setMsPerFrame(milli_sec_per_frame);
  BaseObject::setWindowSize(window_width, window_height);
  BaseObject::printWindowSize();

  // create objects
  std::vector<std::shared_ptr<Block>> blocks;
  std::vector<std::shared_ptr<Ball>>  balls;
  std::vector<std::shared_ptr<Collision_Check>> checkers;
  std::shared_ptr<Racket> racket (new Racket);
  std::shared_ptr<Renderer> renderer (new Renderer);
  std::this_thread::sleep_for(std::chrono::milliseconds(5));

  std::cout << "Step - 1" << std::endl;

  // create objects
  createBlocks(blocks, window_width, window_height, num_row_blocks, num_col_blocks);
  
  std::cout << "Step - 2" << std::endl;

  createBalls(  balls, window_width, window_height, num_ball, velocity_ball, checkers);

  std::cout << "Step - 3" << std::endl;

  // simulate ball
  for_each( balls.begin(), 
            balls.end(),
            [&blocks, &racket, &milli_sec_per_frame] (std::shared_ptr<Ball> &b) { b->simulate(blocks, racket, milli_sec_per_frame); }
           );         

  std::cout << "Step - 4" << std::endl;

  renderer->createWindow(window_width, window_height);
  renderer->simulate(blocks, balls, racket, milli_sec_per_frame);
  racket->simulate();

  std::cout << "Step - 5" << std::endl;

  for(int i=0; i < checkers.size(); i++)
  {
    checkers.at(i)->simulateBallvsRacket(balls.at(i), racket);
    checkers.at(i)->simulateBallvsBlocks(balls.at(i), blocks);
  }



  // for(int i=0; i < checkers.size(); i++)
  // {
  //   checkers.at(i)->simulateBallvsRacket(balls.at(i), racket);
  // }

  // for()


  // Renderer renderer(window_width, window_height);
  // Controller controller;
  // Game game;
  // game.Run(controller, renderer, milli_sec_per_frame);
  // std::cout << "Game has terminated successfully!\n";
  // std::cout << "Score: " << game.GetScore() << "\n";
  
  

  // return 0;
}

//**************************************************************************//

void createBlocks(std::vector<std::shared_ptr<Block>> &blocks, int window_width, int window_height, int num_row, int num_col)
{
  int num_blocks = num_row * num_col;
  float single_space_x = (float)window_width / (float)num_col; 
  float single_space_y = (float)window_height * (3.0/10.0)  / (float)num_col;  
  float block_width    = single_space_x * 0.9;
  float block_height   = single_space_y * 0.9;

  // init block objects
  for (int i = 0; i < num_blocks; i++)
  {
    blocks.emplace_back(std::make_shared<Block>());
  }

  // set property : position and size
  int block_counter = 0;
  for (int row = 0; row < num_row; row++)
  {
    float tmp_y = (float)row * single_space_y;

    for (int col = 0; col < num_col; col++)
    {
        float tmp_x = (float)col * single_space_x;
        blocks.at(block_counter)->setProperty(tmp_x, tmp_y, block_width, block_height);
        block_counter++;
    }
  }
}

//**************************************************************************//

void createBalls(std::vector<std::shared_ptr<Ball>> &balls, int window_width, int window_height, int num_ball, float velocity,
                 std::vector<std::shared_ptr<Collision_Check>> &checkers)
{
  // init ball objects
  for (int i = 0; i < num_ball; i++)
  {
    balls.emplace_back(std::make_shared<Ball>());
    checkers.emplace_back(std::make_shared<Collision_Check>());
  }

  // set property : position and size  
  float ball_x = 0.0;
  float ball_y = (float)window_height * (6.0/10.0);
  float single_space_x = (float)window_height * 0.8 / (float)num_ball;
  float vel_x =   velocity / 3.0;
  float vel_y = - velocity;

  for (int i = 0; i < num_ball; i++)
  {
    ball_x = (float)window_height * 0.2 + single_space_x * (float)i;

    if (i % 2 != 0)
    {
      vel_x = - vel_x;
    }

    balls.at(i)->setProperty(ball_x, ball_y, vel_x, vel_y);
  }  
}
