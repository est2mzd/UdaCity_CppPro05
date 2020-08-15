#include "block_single.h"

// constructor
Block_Single::Block_Single()
{
    init();
}

// initilizer
void Block_Single::init()
{
    is_active    = true;
    is_colliding = false;

    id    = -1;
    pos_x = 0.0;
    pos_y = 0.0;

    width  = 100.0;
    height = 5.0;
}