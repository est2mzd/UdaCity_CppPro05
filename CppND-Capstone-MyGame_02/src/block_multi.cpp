#include "block_multi.h"
#include <memory>

// constructor
Block_Multi::Block_Multi()
{
    init();
}

// initilizer
void Block_Multi::init()
{
    list.clear();
    _id_counter = 0;
}

// add blcok
void Block_Multi::addBlock(float x, float y, float w, float h)
{
    std::shared_ptr<Block_Single> block(new Block_Single());

    block->id = _id_counter;
    ++_id_counter;
    
    block->pos_x  = x;
    block->pos_y  = y;
    block->width  = w;
    block->height = h;

    list.emplace_back(std::move(block));
}

