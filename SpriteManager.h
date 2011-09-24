#ifndef SDL_GAME_ENGINE__SPRITE_MANAGER_H
#define SDL_GAME_ENGINE__SPRITE_MANAGER_H

// SDL
#include "SDL.h"

// C++
#include <string>
#include <map>

// Engine
class Sprite; // Forward declaration, acts like including the header

typedef std::map<std::string, SDL_Surface*> ImageMapDef;

class SpriteManager
{
public:
	SpriteManager(SDL_Color colorKey);

	Sprite* createSprite(std::string fileName);

	void cleanup();

private:
	SDL_Color _colorKey;

	ImageMapDef _imageMap;
};

#endif