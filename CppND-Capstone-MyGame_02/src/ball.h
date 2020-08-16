#ifndef BALL_H
#define BALL_H

#include "BaseObject.h"
#include "SDL.h"
#include "racket.h"

class Racket;
class Block;

class Ball : public BaseObject 
{
public:
  Ball();
  void init();
  void update(Racket& racket);

private:
  bool checkCollisionX();
  bool checkCollisionY();
  void checkCollisionToWall();  
};

#endif