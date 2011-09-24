#include "Game.h"

// SDL
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

// C++
#include <string>

Game::Game()
{
	_quit = false;
	_screen = NULL;
}

// Initialization
bool Game::initialize(std::string title, int width, int height)
{
	// Initialize SDL
	// Note: SDL_INIT_EVERYTHING will also enable joystick, video and cdrom stuff
	if ( SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO) == -1 )
		return false;

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
		return false;

	// Initialize SDL_ttf (true type fonts)
	if ( TTF_Init() == -1 )
		return false;

	//Initialize SDL_mixer (audio)
    if( Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1 )
        return false;

	// Managers
	SDL_Color colorKey = {0, 0xFF, 0xFF};
	this->spriteManager = &SpriteManager(colorKey);

	return true;
}

// Initialization and Game loop
bool Game::start(std::string title, int width, int height)
{
	if ( !initialize(title, width, height) )
		return false;

	// Game loop
	while (_quit)
	{
		// Logic


		// Drawing
	}

	cleanup();

	return true;
}

void Game::cleanup()
{
	spriteManager->cleanup();

	// Quit SDL_ttf
	TTF_Quit();

	// Quit
	SDL_Quit();
}