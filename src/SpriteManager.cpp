#include "SpriteManager.h"

// SDL
#ifdef __APPLE__
#include <SDL/SDL.h>
#include <SDL_image/SDL_image.h>
#else
#include "SDL.h"
#include "SDL_image.h"
#endif

// boost
#include <boost/dynamic_bitset.hpp>

// C++
#include <string>
#include <map>
#include <assert.h>

// Engine
#include "Sprite.h"

SpriteManager::SpriteManager()
{
    _spriteMap = SpriteMap();
    _spriteMap.clear();

    _imageMap = ImageMap();
    _imageMap.clear();

    _nextSpriteId = 0;
}

Sprite* SpriteManager::createSprite(std::string const &fileName)
{
	// get the image, start usage tracking, and record
	// the first usage.
	SDL_Surface *image = getImage(fileName);
	trackImageUse(image, fileName);
	upImageUseCount(image);

    Sprite* newSprite = new Sprite(_nextSpriteId, this, image);
    _nextSpriteId++;
	_spriteMap.insert(SpriteMap::value_type(newSprite->_id, newSprite));
	return newSprite;
}

void SpriteManager::destroySprite(Sprite * const sprite) {

	auto spriteIt = _spriteMap.find(sprite->_id);

	// it is an error to free a sprite that does not belong to this
	// SpriteManager.
	assert(spriteIt != _spriteMap.end());

	_spriteMap.erase(spriteIt);
	// decrease image usage counter
	downImageUseCount(sprite->_image);

	delete sprite;

}

void SpriteManager::cleanup()
{
	// free all images which have a usage count of zero
	auto imageUseIt = _imageUseMap.begin();
	auto imageUseEndIt = _imageUseMap.end();

	while (imageUseIt != imageUseEndIt) {
		// convenience variables
		const auto imagePtr = imageUseIt->first;
		const auto imageFileName = imageUseIt->second.first;
		const auto imageUseCount = imageUseIt->second.second;

		if (imageUseCount == 0) {
			_imageMap.erase(imageFileName);
			_imageUseMap.erase(imageUseIt++);
			delete imagePtr;
		}
		else {
			++imageUseIt;
		}
	}
}

void SpriteManager::draw(SDL_Surface * const screen) const
{
    if (!_spriteMap.empty())
    {
        SpriteMap::const_iterator end = _spriteMap.end();
        for (SpriteMap::const_iterator it = _spriteMap.begin(); it != end; ++it)
        {
            it->second->draw(screen);
        }
    }
}

SDL_Surface *SpriteManager::getImage(std::string const &fileName)
{
	auto imageIt = _imageMap.find(fileName);
	
	// if we didn't find the image, give load it
	if (imageIt == _imageMap.end()) {
		return loadImage(fileName);
	}

	return imageIt->second;
}

	
SDL_Surface *SpriteManager::loadImage(std::string const &fileName)
{
	// it is an error to load an image that is already loaded
	assert(_imageMap.find(fileName) == _imageMap.end());

	SDL_Surface* image = NULL;
	
	// Load the new image
	SDL_Surface* loadedImage = IMG_Load(fileName.c_str());

	// it is an error to load an image that does not exist
	assert(loadedImage != NULL);

	image = SDL_DisplayFormat(loadedImage);
	SDL_FreeSurface(loadedImage);

	// Map the color key
	Uint32 colorKey = SDL_MapRGB(image->format, _colorKey.r, _colorKey.g, _colorKey.b);
	SDL_SetColorKey(image, SDL_SRCCOLORKEY, colorKey);

	_imageMap.insert(ImageMap::value_type(fileName, image));

	return image;
}

/* Image usage tracking
 */

void SpriteManager::trackImageUse(SDL_Surface const* const image, std::string const &fileName)
{
	// it is an error to track an image already being tracked
	assert(_imageUseMap.find(image) == _imageUseMap.end());

	_imageUseMap.insert(ImageUseMap::value_type(
		image,
		std::pair<const std::string, uint>(fileName, 0)
	));
}

void SpriteManager::upImageUseCount(SDL_Surface const* const image)
{
	auto imageUseIt = _imageUseMap.find(image);

	// it is an error to up the usage count of an image that has
	// not been tracked via trackImageUsage()
	assert(imageUseIt != _imageUseMap.end());

	++(imageUseIt->second.second);
}

void SpriteManager::downImageUseCount(SDL_Surface const* const image)
{
	auto imageUseIt = _imageUseMap.find(image);

	// it is an error to down the usage count of an image that hat has
	// not been tracked via trackImageUsage()
	assert(imageUseIt != _imageUseMap.end());

	--(imageUseIt->second.second);
}

SpriteManager::~SpriteManager()
{
	// free all sprites
	auto spriteMapIt = _spriteMap.begin();
	auto spriteMapEndIt = _spriteMap.end();
	while (spriteMapIt != spriteMapEndIt) {
		delete spriteMapIt->second;
		++spriteMapIt;
	}

	// free all images
	auto imageMapIt = _imageMap.begin();
	auto imageMapEndIt = _imageMap.end();
	while (imageMapIt != imageMapEndIt) {
		delete imageMapIt->second;
		++imageMapIt;
	}

}