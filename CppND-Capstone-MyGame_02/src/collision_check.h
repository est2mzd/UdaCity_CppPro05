#ifndef COLLISION_CHECK_H
#define COLLISION_CHECK_H
#include "block_multi.h"
#include "ball.h"
#include "racket.h"
#include <vector>
#include <memory>
#include "SDL.h"

class Collision_Check 
{
public:
    Collision_Check();
    void init();
    
    bool checkBallvsWall(Ball& ball);
    bool checkBallvsBlocks(Ball& ball, Block_Multi& blocks);
    bool checkBallvsRacket(Ball& ball, Racket& racket);
    bool checkSub(Ball& ball, float diff_x, float diff_y, float obj_w, float obj_h);
private:
    
};

#endif