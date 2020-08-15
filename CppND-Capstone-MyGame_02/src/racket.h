#ifndef RACKET_H
#define RACKET_H

#include <vector>
#include "SDL.h"
enum class RacketDirection { kLeft, kRight, kNone };

class Racket {
 public:
    Racket();

    RacketDirection direction;    
    float pos_x;
    float pos_y;
    float vel_x;
    float vel_y;
    float radius;
    float width;
    float height;

    void UpdatePosition();
    void setWindowSize(int width, int height);
    void checkCollideToWall();
    void render(SDL_Renderer *sdl_renderer, SDL_Rect &block);
 private:
    int   _window_width;
    int   _window_height;
};

#endif