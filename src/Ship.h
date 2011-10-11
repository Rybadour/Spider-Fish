#ifndef SHIP_H
#define SHIP_H

// SDL
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include "SDL.h"
#endif

// Engine
#include "GameObject.h"
#include "Sprite.h"

class Ship : public GameObject
{
    public:
        static const float SPEED;

        Ship();
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