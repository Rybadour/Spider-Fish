#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// SDL
#include "SDL.h"

// Engine
#include "SpiderFish.h"

class Game;

class GameObject
{
  public:
    friend class Game;

    GameObject();
    GameObject(Game*);
    virtual ~GameObject();

    virtual void initialized() = 0;
    virtual void handleEvent(SDL_Event* event) = 0;
    virtual void update(int msTimeStep) = 0;

  protected:
    uint id_;
    Game* owner_;
};

#endif // GAMEOBJECT_H
