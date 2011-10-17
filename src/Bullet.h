#ifndef BULLET_H
#define BULLET_H

#include <string>

#include "SDL.h"

#include "SpiderFish.h"
#include "GameObject.h"
#include "Sprite.h"


class Bullet : public GameObject
{
  public:
    Bullet( Game* owner, SDL_Surface* image, int x, int y, int vx, int vy );
    virtual ~Bullet();
    virtual void initialize();
    virtual void draw( SDL_Surface* );
    virtual void update( int msTimeStep );
    virtual void handleEvent(SDL_Event* event);
  protected:
  private:
    Sprite _sprite;

    float _veloX; // pixels/sec
    float _veloY; // pixels/sec

    float _overflowX;
    float _overflowY;

};

#endif // BULLET_H
