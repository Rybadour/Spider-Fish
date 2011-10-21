#ifndef SDL_GAME_ENGINE__GAME_H
#define SDL_GAME_ENGINE__GAME_H

// C++
#include <string>
#include <map>
#include <iostream>

// SDL
#include "SDL.h"

// Engine
#include "SpiderFish.h"
#include "ImageManager.h"

class GameObject;

typedef std::map<uint, GameObject*> GameObjectMap;

const int SCREEN_BPP = 32;

class Game
{
  public:
    ImageManager imageManager;

    Game( std::string title, int width, int height );
    virtual ~Game();
    bool start();

    bool addGameObject( GameObject* gameObject );
    bool removeGameObject( GameObject* gameObject );
    virtual void handleEvent( SDL_Event* event );
    virtual void update( Uint32 );
    virtual void render();
    virtual void cleanup();

    int width;
    int height;

  protected:
    bool _quit;
    SDL_Surface*	_screen;

  private:
    GameObjectMap _gameObjects;
    uint _nextGameObjectId;


};

#endif
