#ifndef BASE_OBJECT
#define BASE_OBJECT

#include <vector>
#include <thread>
#include <mutex>
#include "SDL.h"

enum ObjectType
{
    none,
    ball,
    racket,
    block,
};

class BaseObject
{
public:
    // constructor / destructor
    BaseObject();
    ~BaseObject();

    // getter / setter
    ObjectType getType(){ return _type;};
    int  getID(){ return _id;};
    bool getActiveStatus(){ return _is_active;}
    static void setWindowSize(int width, int height);

    // special method
    void render(SDL_Renderer *sdl_renderer, SDL_Rect &block);
    void updatePosition();
    virtual void update(){};

    // this variables are use by other classes to check collision
    float pos_x, pos_y;
    float vel_x, vel_y;
    float width, height;

    // std::vector<std::thread> threads; // holds all threads that have been launced withing this object
    static std::mutex _mtx;           // mutex shared by all objects for protecting cout

protected:
    ObjectType _type;
    int _id;
    bool _is_active; // if deactivated, the object is not rendered.

    static int _window_width;
    static int _window_height;

    // std::vector<std::thread> threads; // holds all threads that have been launced withing this object

private:
    static int _id_counter;
};

#endif