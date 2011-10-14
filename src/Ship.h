#ifndef SHIP_H
#define SHIP_H

// SDL
#include "SDL.h"

// Engine
#include "SpiderFish.h"
#include "GameObject.h"
#include "Sprite.h"

class Ship : public GameObject
{
  public:
    static const float SPEED;

    Ship();
    Ship(Game*);
    void initialized();

    void handleEvent(SDL_Event* event);
    void update(int msTimeStep);

  private:
    Sprite* sprite_;

    float veloX_; // pixels/sec
    float veloY_; // pixels/sec

    float overflowX_;
    float overflowY_;
};

#endif // SHIP_H
