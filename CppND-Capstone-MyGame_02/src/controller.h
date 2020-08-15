#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "racket.h"

class Controller {
 public:
  void HandleInput(bool &running, Racket &racket) const;
};

#endif