#ifndef COLLISION_CHECK_H
#define COLLISION_CHECK_H
#include "ball.h"
#include "racket.h"
#include <vector>
#include <memory>
#include "SDL.h"

class Collision_Check 
{
public:
    Collision_Check();
    ~Collision_Check();
    void init();
    
    bool checkBallvsBlocks(std::shared_ptr<Ball>  ball, std::vector<std::shared_ptr<Block>> blocks);
    bool checkBallvsRacket(std::shared_ptr<Ball>  ball, std::shared_ptr<Racket> racket);
    bool checkSub(std::shared_ptr<Ball>  ball, float diff_x, float diff_y, float obj_w, float obj_h);

    void simulateBallvsBlocks(std::shared_ptr<Ball>  ball, std::vector<std::shared_ptr<Block>> blocks);
    void simulateBallvsRacket(std::shared_ptr<Ball>  ball, std::shared_ptr<Racket> racket);

    void calcBallvsBlocks(std::shared_ptr<Ball>  ball, std::vector<std::shared_ptr<Block>> blocks);
    void calcBallvsRacket(std::shared_ptr<Ball>  ball, std::shared_ptr<Racket> racket);

private:
    std::vector<std::thread> threads;    
};

#endif