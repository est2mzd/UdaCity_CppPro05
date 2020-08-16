#ifndef BALL_H
#define BALL_H

#include "BaseObject.h"
#include "SDL.h"

class Ball : public BaseObject 
{
public:
  Ball();
  void init();
  void update();

private:
  bool checkCollisionX();
  bool checkCollisionY();
  void checkCollisionToWall();  
};

#endif