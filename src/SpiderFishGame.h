#ifndef SPIDERFISHGAME_H
#define SPIDERFISHGAME_H

#include <list>

// SDL
#include "SDL.h"

// Engine
#include "SpiderFish.h"
#include "Game.h"
#include "EnemyData.h"

class SpiderFishGame : public Game
{
  public:
    SpiderFishGame();

  protected:
    virtual void handleEvent(SDL_Event*);
    virtual void update(Uint32 msTimeStep);
  private:
    void loadEnemyList();
    std::list<EnemyData> _enemyList;
};

#endif // SPIDERFISHGAME_H
