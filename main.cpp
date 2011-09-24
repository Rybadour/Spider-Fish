#include "Game.h"

/*
//The music that will be played
Mix_Music *music = NULL;

//The sound effects that will be used
Mix_Chunk *scratch = NULL;
Mix_Chunk *high = NULL;
Mix_Chunk *med = NULL;
Mix_Chunk *low = NULL;

// The event object
SDL_Event event;

// Font object
TTF_Font* font = NULL;

// Font color
SDL_Color textColor = {255, 255, 255};

bool load_files()
{	
	font = TTF_OpenFont("lazy.ttf", 28);
	
	// if there was an error
	if (background == NULL || font == NULL)
		return false;

	//Load the music
    music = Mix_LoadMUS( "Sounds/beat.wav" );
    
    //If there was a problem loading the music
    if( music == NULL )
        return false;

	//Load the sound effects
    scratch = Mix_LoadWAV( "Sounds/scratch.wav" );
    high = Mix_LoadWAV( "Sounds/high.wav" );
    med = Mix_LoadWAV( "Sounds/medium.wav" );
    low = Mix_LoadWAV( "Sounds/low.wav" );
    
    //If there was a problem loading the sound effects
    if( ( scratch == NULL ) || ( high == NULL ) || ( med == NULL ) || ( low == NULL ) )
        return false;

	return true;
}

void cleanup()
{
	// Free the image
	SDL_FreeSurface(message);
	SDL_FreeSurface(background);

	//Free the sound effects
    Mix_FreeChunk( scratch );
    Mix_FreeChunk( high );
    Mix_FreeChunk( med );
    Mix_FreeChunk( low );
    
    //Free the music
    Mix_FreeMusic( music );

	// Close the font
	TTF_CloseFont(font);
}
*/

int main(int argc, char * args[])
{
	Game game;
	bool result = game.start("Test Game", 640, 480);

	if (result)
		return 0;
	else
		return 1;

	/*
	if (load_files() == false)
		return 1;

	set_clips();

	//Generate the message surfaces
    SDL_Surface* upMessage = TTF_RenderText_Solid( font, "Up was pressed.", textColor );
    SDL_Surface* downMessage = TTF_RenderText_Solid( font, "Down was pressed.", textColor );
    SDL_Surface* leftMessage = TTF_RenderText_Solid( font, "Left was pressed", textColor );
    SDL_Surface* rightMessage = TTF_RenderText_Solid( font, "Right was pressed", textColor );
	if (upMessage == NULL || downMessage == NULL || leftMessage == NULL || rightMessage == NULL)
		return 1;

	Button button(170, 120, 320, 240);

	// While the user hasn't quit
	while (quit == false)
	{
		// Drawing
		// Apply the surfaces to the screen
		apply_surface( 0, 0, background, screen );
		button.show(screen);

		//Update the screen
		if(SDL_Flip(screen) == -1)
			return 1;

		// While there's an event to handle
		while (SDL_PollEvent(&event))
		{
			// Button events
			button.handle_events(event);

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_UP: message = upMessage; break;
					case SDLK_DOWN: message = downMessage; break;
					case SDLK_RIGHT: message = rightMessage; break;
					case SDLK_LEFT: message = leftMessage; break;

					// Music keys
					case SDLK_1: Mix_PlayChannel(-1, scratch, 0); break;

					// Pause/Resume music key
					case SDLK_9:
						if (Mix_PlayingMusic() == 0)
						{
							if (Mix_PlayMusic(music, -1) == -1)
								return 1;
						}
						else
						{
							if (Mix_PausedMusic() == 1)
							{
								// Resume
								Mix_ResumeMusic();
							}
							else
							{
								Mix_PauseMusic();
							}
						}
						break;

					// Halt music key
					case SDLK_0: Mix_HaltMusic(); break;
				}
			}
			// If the user has Xed out the window
			else if (event.type == SDL_QUIT)
			{
				// QUIT
				quit = true;
			}
		}
	}

	cleanup();
	return 0;
	*/
}