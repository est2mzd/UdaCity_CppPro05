#ifndef BLOCK_H
#define BLOCK_H

#include "BaseObject.h"
#include "SDL.h"

class Block : public BaseObject, public std::enable_shared_from_this<Block>
{
public:
    Block();
    void setProperty(float x, float y, float w, float h);
private:
    static int _id_counter;
    
};

#endif