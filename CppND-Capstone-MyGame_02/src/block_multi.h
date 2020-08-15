#ifndef BLOCK_MULTI_H
#define BLOCK_MULTI_H
#include "block_single.h"
#include <vector>
#include <memory>
#include "SDL.h"

class Block_Multi 
{
public:
    Block_Multi();
    void init();
    void render(SDL_Renderer *sdl_renderer, SDL_Rect &block);
    
    void addBlock(float x, float y, float w, float h);
    std::vector<std::shared_ptr<Block_Single>> list;
    void createDefaultBlocks();
    
private:
    int _id_counter;
};

#endif