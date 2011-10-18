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

    virtual void handleEvent(SDL_Event* event) = 0;
    virtual void update(int msTimeStep) = 0;
    virtual void draw(SDL_Surface* screen) = 0;

  protected:
    uint _id;
    Game* _owner;
    bool _alive;
};

#endif // GAMEOBJECT_H
