#ifndef SDL_GAME_ENGINE__GAME_H
#define SDL_GAME_ENGINE__GAME_H

// C++
#include <string>
#include <map>
#include <iostream>

// SDL
#include "SDL.h"

// Engine
#include "Types.h"
#include "SpriteManager.h"
// #include "GameObject.h"

#define img_resource(P) "resources/images/"P

class GameObject;

typedef std::map<uint, GameObject*> GameObjectMap;

const int SCREEN_BPP = 32;

class Game
{
  public:
	SpriteManager spriteManager;

    Game(std::string title, int width, int height);
    bool start();

    bool addGameObject(GameObject* gameObject);
    bool removeGameObject(GameObject* gameObject);

  protected:
    virtual void handleEvent(SDL_Event* event) = 0;

    bool _quit;

  private:
    SDL_Surface*	_screen;
    SDL_Event		_eventManager;

    GameObjectMap gameObjectsOwned_;
    uint nextGameObjectId_;

    bool initialize(std::string title, int width, int height);
    void cleanup();
};

#endif
