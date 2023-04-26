#ifndef ES_H
#define ES_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "function.h"
#define SCREEN_W 610
#define SCREEN_H 420
typedef struct
{
	char *ur1;
	SDL_Rect pos_img_ecran; //position de l'image par rapport l'écran
	SDL_Surface *img;
}image;
typedef struct{
        char *ur1;// path to image(in this case spritesheet
        SDL_Surface *img;
        int exist;//index qui surveille l'existance de l'ennemi, vivant ou mort.
        int dir;//idex de direction 0 right , 1 left
        SDL_Rect pos;//position de l'image par rapport au background
        int pos_max;//borne de deplacement
        int pos_min;//born de deplacement
	SDL_Rect sprite;
	Mix_Chunk *step_sound;
}Ennemi;
//background
void initialiser_imageBACK(image *imge);

//void liberer_back(image imge);
//ennemi
void initialiser_ennemi(Ennemi* imag,char ref[],int x,int y,int pos_M,int pos_m,int first_sprite_x,int first_sprite_y,int width,int height);
void afficher_ennemi(background *screen,Ennemi imag);
void liberer_image_ennemi(Ennemi imag);
void move(Ennemi *e);
void animer_ennemi(Ennemi *e);
int bounding_box(SDL_Rect ep,SDL_Rect pp);
void initialiser_object(Ennemi* imag);
void afficher_object(SDL_Surface *screen,Ennemi imag);
/*void initialiser_step_sound(Ennemi *e);
void liberer_step_sound(Mix_Chunk *music);*/
#endif

