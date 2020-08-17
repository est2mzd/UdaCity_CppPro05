#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "racket.h"
#include <memory>

class Controller 
{
 public:
  void HandleInput(bool &running, std::shared_ptr<Racket> racket) const;
};

#endif