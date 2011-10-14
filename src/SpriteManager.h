#ifndef SDL_GAME_ENGINE__SPRITE_MANAGER_H
#define SDL_GAME_ENGINE__SPRITE_MANAGER_H

// SDL
#ifdef __APPLE__
#include <SDL/SDL.h>
#else
#include "SDL.h"
#endif

// C++
#include <string>
#include <map>

// Engine
#include "Types.h"
class Sprite; // Forward declaration, acts like including the header

typedef std::map<uint, Sprite*> SpriteMap;
typedef std::map<std::string, SDL_Surface*> ImageMap;

class SpriteManager
{
public:
	SDL_Color _colorKey;

	SpriteManager(SDL_Color colorKey);
    void draw(SDL_Surface* screen);

	Sprite* createSprite(std::string fileName);

	void cleanup();

private:
    SpriteMap spriteMap_;
	ImageMap _imageMap;

    uint nextSpriteId_;
};

#endif