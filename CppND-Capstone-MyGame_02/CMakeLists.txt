cmake_minimum_required(VERSION 3.7)
# cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")
# add_definitions(-std=c++17)
# add_definitions(-pthread)
# set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CXX_FLAGS "-Wall")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

#add_executable(SnakeGame src/main.cpp src/game.cpp src/controller.cpp src/renderer.cpp src/snake.cpp src/ball.cpp src/racket.cpp)

file(GLOB project_source src/*.cpp)
add_executable(MyGame ${project_source})

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(MyGame ${SDL2_LIBRARIES})
