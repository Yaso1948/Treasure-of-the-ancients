#ifndef FONCTION_H
#define FONCTION_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_W 610
#define SCREEN_H 420

typedef struct
{
	char *ur2;
	SDL_Rect pos_img_affiche; //partie de l'image qui doit etre affichée
	SDL_Rect pos_img_ecran; //position de l'image par rapport l'écran
	SDL_Surface *bck[3];
	int i;
}BACK;
typedef struct
{
	SDL_Surface *gametxt;
	SDL_Rect pos_gametxt;
	SDL_Colour color_gametxt;
	TTF_Font *police;
}gametexte;

// IMAGE
void initialiser_BACKGROUNDGAME(BACK *back);
void afficher_BACKGROUNDGAME(SDL_Surface *screen,BACK back);
void liberer_image_background(BACK back);

// SONO
void initialiser_audio_game(Mix_Music *gamemusic);
void liberer_musique_game(Mix_Music *gamemusic);
Mix_Chunk *initialiser_audiobref_game();
void liberer_musiquebref_game(Mix_Chunk *gamemusic);

// TEXT
void initialiser_gametexte(gametexte *gametxte);
void afficher_gametexte(SDL_Surface *screen,gametexte gametxte);
void liberer_gametexte(gametexte gametxte);




#endif
