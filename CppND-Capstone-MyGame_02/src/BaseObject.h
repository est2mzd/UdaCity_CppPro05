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
    void setPosition(float  x, float  y);
    void getPosition(float &x, float &y);

    void setVelocity(float  vx, float  vy);
    void getVelocity(float &vx, float &vy);

    void setSize(float  w, float  h);
    void getSize(float &w, float &h);

    ObjectType getType(){ return _type;};
    int getID(){ return _id;};
    bool getActiveStatus(){ return _is_active;}
    static void setWindowSize(int width, int height);

    // special method
    void render(SDL_Renderer *sdl_renderer, SDL_Rect &block);

    template <class SPHEHE, class OTHEROBJ>
    bool checkCollision(SPHEHE& ball, OTHEROBJ& other_obj);
    void updatePosition();

    virtual void update(){};



protected:
    ObjectType _type;
    int _id;
    bool _is_active; // if deactivated, the object is not rendered.

    float _pos_x, _pos_y;
    float _vel_x, _vel_y;
    float _width, _height;

    static int _window_width;
    static int _window_height;

    
    // std::vector<std::thread> threads; // holds all threads that have been launced withing this object
    // static std::mutex _mtx;           // mutex shared by all objects for protecting cout
    

private:
    static int _id_counter;

};

#endif