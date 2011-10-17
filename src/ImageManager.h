#ifndef SDL_GAME_ENGINE__SPRITE_MANAGER_H
#define SDL_GAME_ENGINE__SPRITE_MANAGER_H
// C++
#include <string>
#include <map>

// SDL
#include "SDL.h"

// Engine
#include "SpiderFish.h"

class Sprite; // Forward declaration, acts like including the header

typedef std::map<std::string, SDL_Surface*> ImageMap;

class ImageManager
{
  public:
    ImageManager();
    virtual ~ImageManager();
    SDL_Surface* createImage(std::string fileName);

  private:
    ImageMap _imageMap;
};

#endif
