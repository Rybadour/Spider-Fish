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

typedef std::map<const uint, Sprite* const> SpriteMap;
typedef std::map<const std::string, SDL_Surface* const> ImageMap;
typedef std::map<
	  SDL_Surface const* const
	, std::pair<const std::string, uint>
> ImageUseMap;

/* SpriteManager
 * Allows creation, deletion, and drawing of sprites.
 * Rule: for every createSprite() there should be a
 *       destroySprite().
 */
class SpriteManager
{
public:
	SDL_Color _colorKey;

	// default constructor
	SpriteManager();

	// causes all sprites to be drawn to this SDL_Surface
    void draw(SDL_Surface* const screen) const;

	// creates a new sprite instance automatically setup with the
	// image specified by the fileName and associated with this
	// SpriteManager.
	Sprite* createSprite(std::string const &fileName);

	// frees the sprite. does not free the sprite's image.
	void destroySprite(Sprite * const sprite);

	// calling this frees all images that are not currently
	// being used by any sprite.
	void cleanup();

	// destructing the SpriteManager frees all sprites and
	// images in _spriteMap and _imageMap.
	~SpriteManager();

private:
    SpriteMap _spriteMap;
	ImageMap _imageMap;

    uint _nextSpriteId;

	// returns a pointer to the loaded image. if the image
	// has not yet been loaded, this will automatically call
	// loadImage().
	SDL_Surface *getImage(std::string const &fileName);

	// loads an image from disk and returns a pointer to it
	SDL_Surface *loadImage(std::string const &fileName);

	/* Image usage tracking
	 */

	// image ptr -> pair(fileName, # times used)
	ImageUseMap _imageUseMap;

	// calling these methods tracks how many clients are using
	// each image. this is needed for freeing unused images.
	// the image must exist in _imageMap before using these.
	void trackImageUse(SDL_Surface const* const image, std::string const &fileName);
	void upImageUseCount(SDL_Surface const* const image);
	void downImageUseCount(SDL_Surface const* const image);

};

#endif