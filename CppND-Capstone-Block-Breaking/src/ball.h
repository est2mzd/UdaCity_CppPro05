#ifndef BALL_H
#define BALL_H

#include "BaseObject.h"
#include "SDL.h"
#include "racket.h"
#include "Block.h"
#include <memory>

class Ball : public BaseObject, public std::enable_shared_from_this<Ball>
{
public:
  Ball();
  void setProperty(float x, float y, float vel_x, float vel_y);
  void simulate();
  void calc();
  void calc2(int milli_sec_per_frame);

private:
  static int _id_counter;
  bool checkCollisionX();
  bool checkCollisionY();
  void checkCollisionToWall();
};

#endif