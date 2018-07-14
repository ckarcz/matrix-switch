#include <iostream>
#include <random>

#include <math.h>

#include <switch.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "main.hpp"

using namespace std;

int main(int argc, char **argv)
{
	// Initialize
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	romfsInit();

    // Create an SDL window & renderer
    SDL_Window* window = SDL_CreateWindow("Main-Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);

	// Create bg texture:
	SDL_Surface* bg_surface = IMG_Load("romfs:/resources/images/main.png");			// Read image as surface
	SDL_Texture* bg_texture = SDL_CreateTextureFromSurface(renderer, bg_surface);	// Create texture from surface
	// Clear renderer:
	SDL_RenderClear(renderer);							// Clear renderer
	
	// Copy bg texture to renderer:
	SDL_RenderCopy(renderer, bg_texture, NULL, NULL); 	// Copy texture to renderer
	
	// Render
	SDL_RenderPresent(renderer);						// Render renderer

	// Game loop:
	while (appletMainLoop())
	{
		// Get inputs
		hidScanInput();
		u32 controller1_keys = hidKeysDown(CONTROLLER_P1_AUTO);

		// On controller 1 input...PLUS
		if (controller1_keys & KEY_PLUS)
		{
			break; 	// Break out of main applet loop to exit
		}
	}
	
	SDL_Quit();				// SDL cleanup
	return EXIT_SUCCESS; 	// Clean exit to HBMenu
}