#ifndef SHIP_H
#define SHIP_H

#include <list>

// SDL
#include "SDL.h"

// Engine
#include "Game.h"
#include "SpiderFish.h"
#include "PhysicalEntity.h"
#include "Weapon.h"

class Weapon;

class Ship : public PhysicalEntity
{
  public:

    Ship( Game* owner , SDL_Surface* img, int x, int y );
    virtual ~Ship();
    virtual void draw( SDL_Surface* );
    virtual void handleEvent( SDL_Event* event );
    virtual void update( int msTimeStep );

  protected:
    Weapon* _weapon;
  private:
};

#endif // SHIP_H
