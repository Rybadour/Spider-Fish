#ifndef SHIP_H
#define SHIP_H

#include <list>

// SDL
#include "SDL.h"

// Engine
#include "Game.h"
#include "SpiderFish.h"
#include "GameObject.h"
#include "Sprite.h"
#include "Weapon.h"

class Ship : public GameObject
{
  public:
    static const float SPEED;

    Ship( Game*, Uint32 );
    virtual ~Ship();
    virtual void initialize();
    virtual void draw( SDL_Surface* );
    virtual void handleEvent( SDL_Event* event );
    virtual void update( int msTimeStep );
    virtual int getX();
    virtual int getY();

  private:
    Sprite _sprite;

    float _veloX; // pixels/sec
    float _veloY; // pixels/sec

    float _overflowX;
    float _overflowY;

    float _haloRad;
    Uint32 _haloColour;

    std::list<Weapon*> _weaponList;
    Weapon* _activeWeapon;
};

#endif // SHIP_H
