# CPPND: Capstone : Block Breaking Game

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="./CppND-Capstone-Block-Breaking/block_breaking_game.gif2"/> <br><br><br>

# Project Specifications

## Criteria 1 : A README with instructions is included with the project
- instructions for building/running the project.

### Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

### Basic Build Instructions

1. Clone this repo.
2. Move to the folder "CppND-Capstone-Block-Breaking"
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./Block_Breaking`.
<br><br><br>

## Criteria 2 : The README indicates which project is chosen.

### 2-1 : The README describes the project you have built.
* I chose the video game as my project program.
* The game name is "Block Breaking game".
* The game has 4 types of objects.
  * 1 : blocks -> To get socres, players have to break blocks.
  * 2 : balls -> When balls hit the blocks, blocks break.
  * 3 : racket -> To controll ball movemnets, racket can reflect balls.
  * 4 : wall -> Balls reflect by 4 walls (up,down.right,left).

<img src="./CppND-Capstone-Block-Breaking/game_explanation_1.jpg2"/> 

### 2-2 : The README also indicates the file and class structure, along with the expected behavior or output of the program.
* My program consists of 7 .cpp files.

* 1 : main.cpp
  * main.cpp creates all objects.
  * In this file, players can modify the number of balls and blocks.
  * To stop this program, clicke `X` button on the GUI. 

* 2 : BaseObject.cpp
  * This file has `BaseObject` class.
  * `BaseObject` is a super class of `Ball`, `Racket` and `Block` classes.
  * `BaseObject` provides common members such as position, velocity, size and etc.
  * This program does not have an object for Walls. Instead, `BaseObject` has window_width and window_height as static members. To calculate the collision of Walls and Balls, these 2 members are used.
  * To create thread barrier, `BaseObject::~BaseObject()` do `std::thread::join()` for all thread.

* 3 : ball.cpp
  * This file has `Ball` class.
  * `Ball` inherits `BaseObject`.
  * To calculate the collision to wall, `Ball` has 3 methods (checkCollisionX(), checkCollisionY() and checkCollisionToWall()).
  * `Ball::simulate()` create a thread for each ball and call `Ball::calc()`.
  * `Ball::calc()` runs while-loop and calculates ball movement.

* 3 : racket.cpp
  * This file has `Racket` class.
  * `Racket` inherits `BaseObject`.
  * To calculate the collision to wall, `Racket` has 1 methods (checkCollisionToWall()).
  * `Ball::simulate()` create a thread for each ball and call `Ball::calc()`.
  * `Ball::calc()` runs while-loop and calculates ball movement.

## Program Structure
<img src="./CppND-Capstone-Block-Breaking/program_design.jpg2"/>