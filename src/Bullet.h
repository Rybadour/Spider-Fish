#ifndef BULLET_H
#define BULLET_H

#include <string>

#include "SDL.h"

#include "SpiderFish.h"
#include "Sprite.h"
#include "PhysicalEntity.h"


class Bullet : public PhysicalEntity
{
  public:
    Bullet( Game* owner, SDL_Surface* image, int x, int y, int vx, int vy );
    virtual ~Bullet();
    virtual void draw( SDL_Surface* );
    virtual void update( int msTimeStep );
    virtual void handleEvent(SDL_Event* event);
  protected:
  private:
};

#endif // BULLET_H
