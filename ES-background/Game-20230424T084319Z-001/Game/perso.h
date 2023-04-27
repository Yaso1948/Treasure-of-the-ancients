#ifndef PERSO_H
#define PERSO_H


#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct
{
	char *url;
	SDL_Rect pos_enne_affiche;
	SDL_Rect pos_enne_ecran;
	SDL_Surface *pers[100];
	int etat;
	int direction,speed;

}perso;

typedef struct
{
	char *url;
	SDL_Rect pos_enne_affiche;
	SDL_Rect pos_enne_ecran;
	SDL_Surface *health[10];
	int life;

}health;

void initImagehealth(health *h);
void initImagehealth2(health *h);
void afficherhealth(health h, SDL_Surface  * screen);
void initImage(perso *p );
void initperso(perso *p);
void initperso2(perso *p);
void afficherperso(perso p, SDL_Surface  * screen);
void animerperso( perso *p);
void move( perso *p);
void jump(perso *p);
void liberer_image(perso p);
void liberer_image2(health h);


#endif
