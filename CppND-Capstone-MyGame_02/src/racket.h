#ifndef RACKET_H
#define RACKET_H

#include "BaseObject.h"
#include "SDL.h"

enum RacketDirection 
{ 
  kLeft, kRight, kNone 
};

class Racket : public BaseObject, public std::enable_shared_from_this<Racket>
{
public:
  Racket();
  void init();
  void update();
  RacketDirection direction;    

private:
  void updatePosition();
  void checkCollisionToWall();
};

#endif