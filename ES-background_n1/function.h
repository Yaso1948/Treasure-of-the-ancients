#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SPRITE_SIZE 32

typedef struct
{
    SDL_Surface *txt;
    SDL_Rect pos_txt;
    SDL_Colour color_txt;
    TTF_Font *police;
} texte;

typedef struct 
{
	SDL_Rect position;
	SDL_Surface *img_vie[3];
}Vie;
typedef struct
{
    SDL_Surface *bg[3];
    int frame;
    SDL_Rect camera,pos;
    texte score;
    Vie v;
//son

}background;





void initBack(background *b);
void afficherBack(background b, SDL_Surface *screen,int v,int score);
void scrolling (background *b,int direction);
void animerBack (background *b);

void initialiser_texte(texte *txte,int x, int y);
void afficher_texte(texte *txte,char texte[100],SDL_Surface *screen);
//audio
void initialiser_audio(Mix_Music *music);
void liberer_musique(Mix_Music *music);

void liberer_texte(texte txte);
void liberer_back(background b);



#endif
