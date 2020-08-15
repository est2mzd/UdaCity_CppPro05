#ifndef BLOCK_MULTI_H
#define BLOCK_MULTI_H
#include "block_single.h"
#include <vector>
#include <memory>

class Block_Multi {
    public:
        Block_Multi();
        void init();
        void addBlock(float x, float y, float w, float h);

        std::vector<std::shared_ptr<Block_Single>> list;
        
        
    private:
        int _id_counter;
};

#endif