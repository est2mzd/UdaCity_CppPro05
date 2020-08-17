#ifndef BALL_H
#define BALL_H

#include "BaseObject.h"
#include "SDL.h"
#include "racket.h"

class Ball : public BaseObject 
{
public:
  Ball();
  void setProperty(float x, float y, float vel_x, float vel_y);
  void init();
  void update();
  

private:
  static int _id_counter;
  bool checkCollisionX();
  bool checkCollisionY();
  void checkCollisionToWall();
};

#endif