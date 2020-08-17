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
  ~Racket();
  void init();
  RacketDirection direction;    

  void simulate();
  void calc();

private:
  void updatePosition();
  void checkCollisionToWall();
  void HandleInput();
};

#endif