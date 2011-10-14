#include "SpriteManager.h"

// SDL
#ifdef __APPLE__
#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#else
#include "SDL.h"
#include "SDL_image.h"
#endif

// C++
#include <string>
#include <map>
#include <iostream>

// Engine
#include "Sprite.h"

SpriteManager::SpriteManager(SDL_Color colorKey)
	:_colorKey(colorKey), nextSpriteId_(0)
{
}

Sprite* SpriteManager::createSprite(std::string fileName)
{
  SDL_Surface* image = NULL;
  if (_imageMap.find(fileName) == _imageMap.end())
  {
    // Load the new image
    SDL_Surface* loadedImage = IMG_Load(fileName.c_str());
    if (loadedImage != NULL)
    {
      image = SDL_DisplayFormatAlpha(loadedImage);
      SDL_FreeSurface(loadedImage);

      // Map the color key
      Uint32 colorKey = SDL_MapRGBA(image->format, _colorKey.r, _colorKey.g, _colorKey.b, 0);
      SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorKey);

      _imageMap[fileName] = image;
    }
  }
  else
  {
    image = _imageMap[fileName];
  }

  if (image == NULL)
    return NULL;

  Sprite* newSprite = new Sprite(nextSpriteId_, this, image);
  nextSpriteId_++;
  spriteMap_[newSprite->id_] = newSprite;
  return newSprite;
}

void SpriteManager::cleanup()
{
}

void SpriteManager::draw(SDL_Surface* screen)
{
  if (!spriteMap_.empty())
  {
    SpriteMap::const_iterator end = spriteMap_.end();
    for (SpriteMap::const_iterator it = spriteMap_.begin(); it != end; ++it)
    {
      it->second->draw(screen);
    }
  }
}
