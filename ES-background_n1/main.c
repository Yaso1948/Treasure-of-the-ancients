#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "function.h"
#include "ES.h"
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 480
#define LEVEL_WIDTH 3000
#define LEVEL_HEIGHT 480

int main(int argc, char *argv[])
{
    SDL_Surface *screen = NULL;
    SDL_Event event;
    background back;
    Mix_Music *music;
    Ennemi enm;
    //Ennemi enm1;

    // Initialize SDL
    TTF_Init();
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_RESIZABLE) != 0) {
        printf("Erreur : %s", SDL_GetError());
        return -1;
    }
    // Initialize SDL_mixer
    Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);

    // Initialize the screen
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_SWSURFACE);
    if (screen == NULL) {
        printf("Erreur : %s", SDL_GetError());
        SDL_Quit();
    }

    // Initialize the background and music
    initBack(&back);
    music = Mix_LoadMUS("menu.mp3");
    Mix_PlayMusic(music, -1);
    initialiser_ennemi(&enm,"golem_walkin.png",10,340,390,15,0,0,67,60);
    //initialiser_object(&enm1);

    // Set the initial state
    int running = 1;
    int scrolling_right = 0;
    int scrolling_left = 0;
    enm.exist = 1;
    enm.dir = 0;
    // Main loop
    while(running) {
	afficherBack(back, screen, 3, 100);
        afficher_ennemi(&back,enm);
	//afficher_object(screen,enm1);
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
                    }
                    break;
            }
        }
	if(enm.exist==1){
	move(&enm);
	animer_ennemi(&enm);
	//if(bounding_box(enm1.pos,enm.pos)==1){enm.exist = 0;}
	}

        // Scroll the background
	if (scrolling_right) {
	    scrolling(&back, 1);
	} else if (scrolling_left) {
	    scrolling(&back, 2);
	}



        // Animate the background and update the screen
        animerBack(&back);
        SDL_Flip(screen);
    }

    // Free resources and quit SDL
    liberer_image_ennemi(enm);
    Mix_FreeMusic(music);
    liberer_back(back);
    TTF_Quit();
    SDL_Quit();

    return 0;
}

