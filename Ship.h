#ifndef SHIP_H
#define SHIP_H

// SDL
#include "SDL.h"

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
        void update();

    private:
        Sprite* sprite_;

        float veloX_;
        float veloY_;

        float overflowX_;
        float overflowY_;
};

#endif // SHIP_H