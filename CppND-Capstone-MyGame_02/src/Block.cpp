#include "Block.h"
#include <iostream>

// initialize static variable
int Block::_id_counter = 0;

Block::Block()
{
    // type & id
    _type = ObjectType::block;
    _id   = _id_counter++;

    // common initial condition
    vel_x  = 0.0;
    vel_y  = 0.0;

    std::cout << "Block ID : " << _id << " Initializing" << std::endl;
}

void Block::setProperty(float x, float y, float w, float h)
{
    pos_x  = x;
    pos_y  = y;
    width  = w;
    height = h;

    // std::cout << x << "," << y << "," << w << "," << h << std::endl;
    // std::cout << pos_x << "," << pos_y << "," << width << "," << height << std::endl;
}


void Block::update()
{


}
