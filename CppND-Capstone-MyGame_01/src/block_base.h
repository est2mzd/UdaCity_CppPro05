#ifndef BLOCK_BASE_H
#define BLOCK_BASE_H

#include "ball.h"
enum class CollisionPositionList { Up, Down, Left, Right, None };

class Block_Base {
    public:
        int   id;
        bool  is_active;
        bool  is_colliding;
        CollisionPositionList collision_postion;
        float pos_x;
        float pos_y;

        static float width;
        static float height;

        void checkCollision(Ball const &ball);

    private:

};

#endif