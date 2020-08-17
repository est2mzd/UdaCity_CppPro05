cmake_minimum_required(VERSION 3.7)
# cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17 -pthread")

set(CXX_FLAGS "-Wall")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)


file(GLOB project_source src/*.cpp)
add_executable(Block_Breaking ${project_source})

string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Block_Breaking ${SDL2_LIBRARIES})
