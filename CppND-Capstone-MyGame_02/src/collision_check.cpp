#include "collision_check.h"
#include <memory>
#include <iostream>
#include <cmath>
#include <string>

// constructor
Collision_Check::Collision_Check()
{

}

// initilizer
void Collision_Check::init()
{

}


bool Collision_Check::checkBallvsBlocks(Ball& ball, Block_Multi& blocks)
{
    float ball_center_x = ball.pos_x + ball.width / 2.0;
    float ball_center_y = ball.pos_y + ball.height / 2.0;

    for(auto b : blocks.list)
    {
        if (b->is_active)
        {
            float block_center_x = b->pos_x + b->width/2.0;
            float block_center_y = b->pos_y + b->height/2.0;
            float diff_x = ball_center_x - block_center_x;
            float diff_y = ball_center_y - block_center_y;

            if ( checkSub(ball, diff_x, diff_y, b->width, b->height) )
            {
                //  deactivate block
                b->is_active = false;
                return true;
            }
        }  
    }

    return false;
}


bool Collision_Check::checkBallvsRacket(Ball& ball, Racket& racket)
{
    float ball_center_x = ball.pos_x + ball.width / 2.0;
    float ball_center_y = ball.pos_y + ball.height / 2.0;

    float block_center_x = racket.pos_x + racket.width/2.0;
    float block_center_y = racket.pos_y + racket.height/2.0;
    float diff_x = ball_center_x - block_center_x;
    float diff_y = ball_center_y - block_center_y;

    if ( checkSub(ball, diff_x, diff_y, racket.width, racket.height) )
        return true;

    return false;
}



bool Collision_Check::checkSub(Ball& ball, float diff_x, float diff_y, float obj_w, float obj_h)
{
    if ( fabs(diff_x) <= (ball.width + obj_w/2.0)  )
    {
        if ( fabs(diff_y) <= (ball.height + obj_h/2.0)  )
        {
            // check which surface does the ball collide to.
            float length    = powf( (powf(diff_x, 2.0) + powf(diff_y, 2.0)), 0.5 ) + 1e-6;
            float angle_deg =  atanf(diff_x / length) / 3.141592 * 180.0; // return is 0 to 180 deg
            
            // upper or bottom
            if (fabs(diff_x) <= obj_w/2.0)
            {
                if (diff_y >= 0)
                {
                    ball.vel_y =  fabs(ball.vel_y);
                }
                else
                {
                    ball.vel_y = - fabs(ball.vel_y);
                }
                
            }
            else // left of right
            {
                if (diff_x >= 0)
                {
                    ball.vel_x = fabs(ball.vel_x);
                }
                else
                {
                    ball.vel_x = - fabs(ball.vel_x);
                }
            }

            return true;
        }
    }

    return false;
}


