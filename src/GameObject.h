#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// SDL
#include "SDL.h"

// Engine
#include "Types.h"
//#include "Game.h"
class Game;

class GameObject
{
    public:
        friend class Game;

        GameObject();

        virtual void initialized() = 0;
        virtual void handleEvent(SDL_Event* event) = 0;
        virtual void update() = 0;

    protected:
        uint id_;
        Game* owner_;
};

#endif // GAMEOBJECT_H