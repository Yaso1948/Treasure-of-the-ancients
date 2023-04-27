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
	char *ur1;
	SDL_Rect pos_img_affiche; //partie de l'image qui doit etre affichée
	SDL_Rect pos_img_ecran; //position de l'image par rapport l'écran
	SDL_Surface *character[5];
	int i;
}Character1;

void initialiser_CHARACTER1(Character1 *character);
void afficher_CHARACTER1(SDL_Surface *screen,Character1 character);






#endif
