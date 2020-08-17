#include "ball.h"
#include <cmath>
#include <iostream>
#include <thread>
#include <chrono>

// initialize static variable
int Ball::_id_counter = 0;

Ball::Ball()
{
    // type & id
    _type = ObjectType::ball;
    _id   = _id_counter++;

    // common initial condition
    width  = 5.0;
    height = 5.0;

    std::cout << "Ball ID : " << _id << " Initializing" << std::endl;
}

void Ball::setProperty(float x, float y, float vx, float vy)
{
    pos_x  = x;
    pos_y  = y;
    vel_x  = vx;
    vel_y  = vy;
}


void Ball::init()
{

}


void Ball::update()
{
    // // update position
    // BaseObject::updatePosition();

    // // Wall : update velocity for next simulation
    // checkCollisionToWall();

}


bool Ball::checkCollisionX()
{
    float pos_center = pos_x + width;

    if ( (pos_center > (_window_width - width)) || (pos_center < width) ) 
        return true;

    return false;
}

bool Ball::checkCollisionY()
{
    float pos_center = pos_y + height;

    if ( (pos_center > (_window_height - height)) || (pos_center < height) )
        return true;

    return false;
}

void Ball::checkCollisionToWall()
{
    // refrect at the wall
    if (checkCollisionX())
    {
        vel_x = vel_x * (-1.0);
    }

    if (checkCollisionY())
    {
        vel_y = vel_y * (-1.0);
    }    

}


void Ball::simulate(std::vector<std::shared_ptr<Block>> blocks, std::shared_ptr<Racket> racket, int milli_sec_per_frame)
{
    // launch calc function in a thread
    // threads.emplace_back(std::thread(&Ball::calc, this, milli_sec_per_frame));
    threads.emplace_back(std::thread(&Ball::calc2, this));
}

void Ball::calc(int milli_sec_per_frame)
{
    // print if of the current thread
    std::unique_lock<std::mutex> lock_u(_mtx);
    std::cout << "Ball #" << _id << "::go thread id = " << std::this_thread::get_id() << std::endl;
    lock_u.unlock();

    std::cout << "Ball::calc()" << std::endl;
    Uint32 title_timestamp = SDL_GetTicks();
    Uint32 frame_start;
    Uint32 frame_end;
    Uint32 frame_duration;
    int frame_count = 0;
    bool running = true;

    while (running) 
    {
        // pre - procedure
        frame_start = SDL_GetTicks();        
        // std::this_thread::sleep_for(std::chrono::milliseconds(1));

        //-----------------------------------------------//
        // update position
        BaseObject::updatePosition();

        // Wall : update velocity for next simulation
        checkCollisionToWall();
        //-----------------------------------------------//

        // post - procedure
        frame_end = SDL_GetTicks();

        frame_duration = frame_end - frame_start;

        if (frame_duration < milli_sec_per_frame) 
        {
            SDL_Delay(milli_sec_per_frame - frame_duration);
        }
    }
}

void Ball::calc2()
{
    // print if of the current thread
    std::unique_lock<std::mutex> lock_u(_mtx);
    std::cout << "Ball #" << _id << "::go thread id = " << std::this_thread::get_id() << std::endl;
    lock_u.unlock();

    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        // update position
        BaseObject::updatePosition();

        // Wall : update velocity for next simulation
        checkCollisionToWall();
    }
}