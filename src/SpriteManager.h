#ifndef SDL_GAME_ENGINE__SPRITE_MANAGER_H
#define SDL_GAME_ENGINE__SPRITE_MANAGER_H

// SDL
#include "SDL.h"

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
	SpriteManager(SDL_Color colorKey);
    void draw(SDL_Surface* screen);

	Sprite* createSprite(std::string fileName);

	void cleanup();

private:
	SDL_Color _colorKey;

    SpriteMap spriteMap_;
	ImageMap _imageMap;

    uint nextSpriteId_;
};

#endif