// C++
#include <string>

// SDL
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"

// Game
#include "Game.h"
#include "SpiderFish.h"
#include "GameObject.h"

Game::Game( std::string title, int width, int height ):
  imageManager(),
  width( width ),
  height( height ),
  _quit( false ),
  _nextGameObjectId( 0 )
{
  // Initialize SDL
  // Note: SDL_INIT_EVERYTHING will also enable joystick, video and cdrom stuff
  if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    return;

  // Set up the Window and View Port
  SDL_WM_SetCaption( title.c_str(), NULL ); // window caption
  // Note: the icon must be a bmp file because it must be called before SDL_SetVideoMode
  //SDL_WM_SetIcon(SDL_LoadBMP("icon.bmp"), NULL); // window icon

  // Note: Use SDL_FULLSCREEN instead of SDL_SWSURFACE to run in fullscreen
  _screen = SDL_SetVideoMode( width, height, SCREEN_BPP, SDL_SWSURFACE );
  //SDL_putenv("SDL_VIDEO_CENTERED=center"); // center the window
  //SDL_putenv("SDL_VIDEO_WINDOW_POS=x,y"); // position the window

  // Quit if screen couldn't be setup
  if( _screen == NULL )
    return;

  // Initialize SDL_ttf (true type fonts)
  if( TTF_Init() == -1 )
    return;

  //Initialize SDL_mixer (audio)
  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    return;
}

Game::~Game()
{
  GameObjectMap::iterator it = _gameObjects.begin();
  GameObjectMap::iterator ie = _gameObjects.end();
  for( ; it != ie; ++it )
  {
    delete it->second;
  }
}

// Initialization and Game loop
bool Game::start()
{
  // Game loop
  Uint32 lastTimeStep = SDL_GetTicks();
  Uint32 msTimeStep = 0;
  Uint32 msTime;
  SDL_Event event;
  while( !_quit )
  {
    msTime = SDL_GetTicks();
    msTimeStep = msTime - lastTimeStep;
    lastTimeStep = msTime;
    while( SDL_PollEvent( &event ) )
      handleEvent( &event );
    update( msTimeStep );
    render();
  }
  cleanup();
  return true;
}

void Game::handleEvent( SDL_Event* event )
{
  switch( event->type )
  {
    case SDL_QUIT:
      _quit = true;
      break;
    default: break;
  }
  GameObjectMap::const_iterator ie = _gameObjects.end();
  GameObjectMap::const_iterator it = _gameObjects.begin();
  for( ; it != ie; ++it )
  {
    it->second->handleEvent( event );
  }
}
//call the draw method for each game object
//aswell as clear and flip the screen
void Game::render()
{
  SDL_FillRect( _screen, NULL, 0 );
  GameObjectMap::const_iterator ie = _gameObjects.end();
  GameObjectMap::const_iterator it = _gameObjects.begin();
  for( ; it != ie; ++it )
  {
    it->second->draw( _screen );
  }
  if( SDL_Flip( _screen ) == -1 )
    _quit = true;
}

//update all game objects
void Game::update( Uint32 msTimeStep )
{
  GameObjectMap::const_iterator it = _gameObjects.begin();
  while( it != _gameObjects.end() )
  {
    if( !it->second->_alive )
    {
      removeGameObject(( it++ )->second );
    }
    else
    {
      ++it;
    }
  }
  it = _gameObjects.begin();
  for( ; it != _gameObjects.end(); ++it )
  {
    it->second->update( msTimeStep );
  }
}

void Game::cleanup()
{
  // Quit SDL_ttf
  TTF_Quit();

  // Quit
  SDL_Quit();
}

bool Game::addGameObject( GameObject* gameObject )
{
  if( gameObject->_id == 0 )
  {
    gameObject->_owner = this;
    gameObject->_id = _nextGameObjectId;
    _nextGameObjectId++;
    _gameObjects[gameObject->_id] = gameObject;

    return true;
  }

  // otherwise it's already used somewhere
  return false;
}

bool Game::removeGameObject( GameObject* gameObject )
{
  if( gameObject->_id != 0 )
  {
    // Remove the game object
    if( _gameObjects.erase( gameObject->_id ) == 1 )
    {
      if( gameObject->_id + 1 == _nextGameObjectId )
        --_nextGameObjectId;
      delete gameObject;
      return true;
    }
  }
  // otherwise it's already removed
  return false;
}

