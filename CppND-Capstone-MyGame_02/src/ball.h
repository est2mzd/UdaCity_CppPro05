#ifndef BALL_H
#define BALL_H

#include <vector>
#include "SDL.h"

class Ball {
 public:
   Ball();
   void init();
   void render(SDL_Renderer *sdl_renderer, SDL_Rect &block);

   float pos_x;
   float pos_y;
   float vel_x;
   float vel_y;
   float radius;
   void UpdatePosition();
   void setWindowSize(int width, int height);
   bool checkCollisionX();
   bool checkCollisionY();
 private:
   int   _window_width;
   int   _window_height;
};

#endif