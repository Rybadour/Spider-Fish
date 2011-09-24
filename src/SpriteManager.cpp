#include "SpriteManager.h"

// SDL
#include "SDL.h"
#include "SDL_image.h"

// C++
#include <string>
#include <map>

// Engine
#include "Sprite.h"

SpriteManager::SpriteManager(SDL_Color colorKey)
{
	_colorKey = colorKey;
}

Sprite* SpriteManager::createSprite(std::string fileName)
{
	SDL_Surface* image;
	if (_imageMap.find(fileName) == _imageMap.end())
	{
		// Load the new image
		SDL_Surface* loadedImage = IMG_Load(fileName.c_str());
		if (loadedImage != NULL)
		{
			image = SDL_DisplayFormat(loadedImage);
			SDL_FreeSurface(loadedImage);

			// Map the color key
			Uint32 colorKey = SDL_MapRGB(image->format, _colorKey.r, _colorKey.g, _colorKey.b);
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

	return &Sprite(this, image);
}

void SpriteManager::cleanup()
{
}