#ifndef SHIPHALO_H
#define SHIPHALO_H

#include "PhysicalEntity.h"
#include "SpiderFish.h"
#include "Game.h"

class ShipHalo : public PhysicalEntity
{
  public:
    ShipHalo( Game* owner, float rad , int x, int y );
    virtual ~ShipHalo();
    virtual void draw( SDL_Surface* );
    virtual void handleEvent( SDL_Event* event );
    virtual void update( int msTimeStep );
    int getRad()const;
    void setRad( int rad );
  protected:
  private:
    float _rad;
};

#endif // SHIPHALO_H
