#include "block_multi.h"
#include <memory>
#include <iostream>

// constructor
Block_Multi::Block_Multi()
{
    std::cout << "Blocks : Initializing" << std::endl;
    init();
    createDefaultBlocks();
}

// initilizer
void Block_Multi::init()
{
    list.clear();
    _id_counter = 0;
}


void Block_Multi::render(SDL_Renderer *sdl_renderer, SDL_Rect &block)
{
    //---------------------------------------------------------
    // Racket
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    for(auto b : list)
    {
        if (b->is_active)
        {
            block.w = b->width;  // set block width
            block.h = b->height;           // set block height
            block.x = b->pos_x;
            block.y = b->pos_y;
            SDL_RenderFillRect(sdl_renderer, &block); 
        }  
    }
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

// create default block lilst
void Block_Multi::createDefaultBlocks()
{
    float x,y,w,h;
    w = 50.0;
    h = 50.0;

    for (int row = 2; row >= 0; row--)
    {
        float tmp_y = row * (h*1.1);

        for (int col = 0; col < 12; col++)
        {
            float tmp_x = col * (w*1.1);
            addBlock(tmp_x, tmp_y, w, h);
        }
    }

}