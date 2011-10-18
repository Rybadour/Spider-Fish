#ifndef SHIPBULLET_H
#define SHIPBULLET_H

// SDL
#include "SDL.h"

// Engine
#include "Weapon.h"
#include "Game.h"
#include "SpiderFish.h"
#include "Ship.h"
#include "Sprite.h"

class SingleShooter : public Weapon
{
  public:
    SingleShooter( Game*owner, Ship* body );
    virtual ~SingleShooter();
    virtual void initialize();
    virtual void handleEvent( SDL_Event* event );
    virtual void update( int msTimeStep );
    virtual void draw( SDL_Surface* screen );
    virtual void fire();
  protected:
  private:
};

#endif // SHIPBULLET_H
