// C++
#include <string>
#include <map>
#include <iostream>

// SDL
#include "SDL.h"
#include "SDL_image.h"

// Engine
#include "ImageManager.h"
#include "SpiderFish.h"


ImageManager::ImageManager()
{
}

ImageManager::~ImageManager()
{
  std::cout << "Image manager getting destroyed" << std::endl;
  ImageMap::iterator it = _imageMap.begin();
  ImageMap::iterator ie = _imageMap.end();
  for (; it != ie; ++it)
  {
    SDL_FreeSurface(it->second);
  }
}

SDL_Surface* ImageManager::createImage(std::string fileName)
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
      _imageMap[fileName] = image;
    }
  }
  else
  {
    image = _imageMap[fileName];
  }
  return image;
}

