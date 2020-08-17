#include "ball.h"
#include <cmath>
#include <iostream>

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


void Ball::simulate(std::vector<std::shared_ptr<Block>> blocks, std::shared_ptr<Racket> racket)
{
    // launch calc function in a thread
    threads.emplace_back(std::thread(&Ball::calc, this));
}

void Ball::calc()
{
    // print if of the current thread
    std::unique_lock<std::mutex> lock_u(_mtx);
    std::cout << "Ball #" << _id << "::go thread id = " << std::this_thread::get_id() << std::endl;
    lock_u.unlock();

    while(true)
    {
        // update position
        BaseObject::updatePosition();

        // Wall : update velocity for next simulation
        checkCollisionToWall();
    }
}