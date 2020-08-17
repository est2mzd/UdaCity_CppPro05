#ifndef BLOCK_H
#define BLOCK_H

#include "BaseObject.h"
#include "SDL.h"

class Block : public BaseObject 
{
public:
    Block();
    void setProperty(float x, float y, float w, float h);
    void update();

private:
    static int _id_counter;
};

#endif