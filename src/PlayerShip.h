#ifndef PLAYERSHIP_H
#define PLAYERSHIP_H

#include <list>
#include "SDL.h"

#include "Ship.h"
#include "SpiderFish.h"
#include "Game.h"
#include "Weapon.h"
#include "ShipHalo.h"

class PlayerShip : public Ship
{
  public:
    static const float SPEED;
    PlayerShip( Game* owner , int x, int y );
    virtual ~PlayerShip();
    virtual void draw( SDL_Surface* );
    virtual void handleEvent( SDL_Event* event );
    virtual void update( int msTimeStep );
  protected:
  private:
    std::list<Weapon*> _weaponList;
    ShipHalo _halo;
};

#endif // PLAYERSHIP_H

