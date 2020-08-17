#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

#include "BaseObject.h"

#include <thread>
#include <vector>
#include "Block.h"
#include "ball.h"

void createBlocks(std::vector<std::shared_ptr<Block>> &blocks, 
                  int window_width, int window_height, 
                  int num_row, int num_col);

void createBalls(std::vector<std::shared_ptr<Ball>> &balls, 
                 int window_width, int window_height, 
                 int num_ball, float velocity);

// void createBlocks(std::vector<std::shared_ptr<Block>> &, int, int, int, int);
// void createBalls(std::vector<std::shared_ptr<Ball>> &, int, int, int, float);

int main() 
{
  
  constexpr std::size_t frames_per_sec{60};
  constexpr std::size_t milli_sec_per_frame{1000 / frames_per_sec};
  constexpr std::size_t window_width{640};
  constexpr std::size_t window_height{640};
  
  // set widow size (static variable)
  BaseObject::setWindowSize(window_width, window_height);
  BaseObject::printWindowSize();



  
  Renderer renderer(window_width, window_height);
  Controller controller;
  Game game;
  game.Run(controller, renderer, milli_sec_per_frame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  
  

  return 0;
}



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
  for (int row = 2; row >= 0; row--)
  {
    float tmp_y = row * single_space_y;

    for (int col = 0; col < 12; col++)
    {
        float tmp_x = col * single_space_x;
        blocks.at(block_counter)->setProperty(tmp_x, tmp_y, block_width, block_height);
    }
  }
}


void createBalls(std::vector<std::shared_ptr<Ball>> &balls, int window_width, int window_height, int num_ball, float velocity)
{
  // init ball objects
  for (int i = 0; i < num_ball; i++)
  {
    balls.emplace_back(std::make_shared<Ball>());
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
