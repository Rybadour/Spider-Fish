#include <math.h>

#include "Ship.h"

// Engine
#include "Game.h"

#ifdef __APPLE__
#include "resources.h"
#endif


// Constant
const float Ship::SPEED = 100; // pixels/sec

Ship::Ship() : sprite_(NULL), veloX_(0), veloY_(0), overflowX_(0), overflowY_(0)
{
/*    veloX_ = 0;
    veloY_ = 0;

    overflowX_ = 0;
    overflowY_ = 0;*/
}

void Ship::initialized()
{
#ifdef __APPLE__
    sprite_ = owner_->spriteManager->createSprite(resourcePathFor("ship.png"));
#else
    sprite_ = owner_->spriteManager->createSprite("ship.png");
#endif
    sprite_->x = 200;
    sprite_->y = 100;
}

void Ship::handleEvent(SDL_Event* event)
{
    // Key Down events
    if (event->type == SDL_KEYDOWN)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_UP: veloY_ -= SPEED; break;
            case SDLK_DOWN: veloY_ += SPEED; break;
            case SDLK_RIGHT: veloX_ += SPEED; break;
            case SDLK_LEFT: veloX_ -= SPEED; break;
        }
    }

    // Key Up events
    else if (event->type == SDL_KEYUP)
    {
        switch (event->key.keysym.sym)
        {
            case SDLK_UP: veloY_ += SPEED; break;
            case SDLK_DOWN: veloY_ -= SPEED; break;
            case SDLK_RIGHT: veloX_ -= SPEED; break;
            case SDLK_LEFT: veloX_ += SPEED; break;
        }
    }
}

void Ship::update(int msTimeStep)
{
    // TODO: Refactored to something nicer
    overflowX_ += veloX_ * ((float)msTimeStep/1000);
    overflowY_ += veloY_ * ((float)msTimeStep/1000);

    if (overflowX_ >= 1 || overflowX_ <= -1)
    {
        sprite_->x += floor(overflowX_);
        overflowX_ = overflowX_ - floor(overflowX_);
    }

    if (overflowY_ >= 1  || overflowY_ <= -1)
    {
        sprite_->y += floor(overflowY_);
        overflowY_ = overflowY_ - floor(overflowY_);
    }
}