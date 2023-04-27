#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "function.h"
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 440

int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL;
    SDL_Event event;
    background back;
    Mix_Music *music;

    // Initialize SDL
    TTF_Init();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_RESIZABLE) != 0) {
        printf("Erreur : %s", SDL_GetError());
        return -1;
    }
    // Initialize SDL_mixer
    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);

    // Initialize the screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE | SDL_RESIZABLE);
    if (screen == NULL) {
        printf("Erreur : %s", SDL_GetError());
        SDL_Quit();
    }

    // Initialize the background and music
    initBack(&back);
    music = Mix_LoadMUS("son.mp3");
    Mix_PlayMusic(music, -1);

    // Set the initial state
    int running = 1;
    int scrolling_right = 0;
    int scrolling_left = 0;
    int scrolling_up = 0;
    int scrolling_down = 0;

    // Main loop
    while (running) {
        // Handle events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = 0;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                            scrolling_right = 1;
                            break;
                        case SDLK_LEFT:
                            scrolling_left = 1;
                            break;
			case SDLK_UP:
                            scrolling_up = 1;
                            break;
                        case SDLK_DOWN:
                            scrolling_down = 1;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_RIGHT:
                            scrolling_right = 0;
                            break;
                        case SDLK_LEFT:
                            scrolling_left = 0;
                            break;
			case SDLK_UP:
                            scrolling_up = 0;
                            break;
                        case SDLK_DOWN:
                            scrolling_down = 0;
                            break;
                    }
                    break;
            }
        }

        // Scroll the background
	if (scrolling_right) {
	    scrolling(&back, 1);
	} else if (scrolling_left) {
	    scrolling(&back, 2);
	} else if (scrolling_up) {
	    scrolling(&back, 3);
	} else if (scrolling_down) {
	    scrolling(&back, 4);
	}

        // Animate the background and update the screen
        animerBack(&back);
        afficherBack(back, screen, 3, 100);
        SDL_Flip(screen);
    }

    // Free resources and quit SDL
    Mix_FreeMusic(music);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

