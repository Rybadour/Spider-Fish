#include "Game.h"

// C++
#include <string>

// SDL
#ifdef __APPLE__
#include <SDL/SDL.h>
#include <SDL_ttf/SDL_ttf.h>
#include <SDL_mixer/SDL_mixer.h>
#include <SDL_image/SDL_image.h>
#else
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
#endif

// Engine
#include "GameObject.h"

Game::Game(std::string title, int width, int height)
  : _quit(false),
    _screen(NULL),
    spriteManager(),
    nextGameObjectId_(0)
{

	SDL_Color color = {0, 0xFF, 0xFF};
	this->spriteManager._colorKey = color;

  // Initialize SDL
  // Note: SDL_INIT_EVERYTHING will also enable joystick, video and cdrom stuff
  if ( SDL_Init(SDL_INIT_EVERYTHING) == -1 )
    return;

  // Set up the Window and View Port
  SDL_WM_SetCaption(title.c_str(), NULL); // window caption
  // Note: the icon must be a bmp file because it must be called before SDL_SetVideoMode
  //SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL); // window icon

  // Note: Use SDL_FULLSCREEN instead of SDL_SWSURFACE to run in fullscreen
  _screen = SDL_SetVideoMode(width, height, SCREEN_BPP, SDL_SWSURFACE);
  //SDL_putenv("SDL_VIDEO_CENTERED=center"); // center the window
  //SDL_putenv("SDL_VIDEO_WINDOW_POS=x,y"); // position the window

  // Quit if screen couldn't be setup
  if ( _screen == NULL )
    return;

  // Initialize SDL_ttf (true type fonts)
  if ( TTF_Init() == -1 )
    return;

  //Initialize SDL_mixer (audio)
  if( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1 )
    return;
}

// Initialization and Game loop
bool Game::start()
{
  // Game loop
  Uint32 lastTimeStep = SDL_GetTicks();
  Uint32 msTimeStep = 0;
  int eventCount = 0;
  while (!_quit)
  {
    msTimeStep = SDL_GetTicks() - lastTimeStep;
    lastTimeStep = SDL_GetTicks();

    // Tell the game objects to update
    GameObjectMap::const_iterator end = gameObjectsOwned_.end();
    for (GameObjectMap::const_iterator it = gameObjectsOwned_.begin(); it != end; ++it)
    {
      it->second->update(msTimeStep); // TODO: Eventually pass a timestep value here?
    }

    // Iterate over all the events this step and tell the game objects about them
    while ( SDL_PollEvent(&_eventManager) )
    {
      handleEvent(&_eventManager);

      GameObjectMap::const_iterator end = gameObjectsOwned_.end();
      for (GameObjectMap::const_iterator it = gameObjectsOwned_.begin(); it != end; ++it)
      {
        it->second->handleEvent(&_eventManager);
      }

      // If the user wants to close the game
      if (_eventManager.type == SDL_QUIT)
      {
        // QUIT
        _quit = true;
      }
    }

    // Drawing
	  SDL_FillRect(_screen, NULL, 0x00000000);
    spriteManager.draw(_screen);

    // Refresh screen
    if(SDL_Flip(_screen) == -1)
      _quit = true;
  }

  cleanup();

  return true;
}

bool Game::addGameObject(GameObject* gameObject)
{
  if (gameObject->id_ == 0)
  {
    gameObject->owner_ = this;
    gameObject->id_ = nextGameObjectId_;
    nextGameObjectId_++;

    gameObject->initialized();

    gameObjectsOwned_[gameObject->id_] = gameObject;

    return true;
  }

  // otherwise it's already used somewhere
  return false;
}

bool Game::removeGameObject(GameObject* gameObject)
{
  if (gameObject->id_ != 0)
  {
    // Remove the game object
    if (gameObjectsOwned_.erase(gameObject->id_) == 1)
    {
      // Attemp to make
      if (gameObject->id_ + 1 == nextGameObjectId_)
        nextGameObjectId_--;

      gameObject->owner_ = NULL;
      gameObject->id_ = 0;

      return true;
    }
  }

  // otherwise it's already removed
  return false;
}

void Game::cleanup()
{
	spriteManager.cleanup();

  // Quit SDL_ttf
  TTF_Quit();

  // Quit
  SDL_Quit();
}
