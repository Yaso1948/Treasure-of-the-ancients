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
	SDL_Surface *img[2];
	int i;
}image;
typedef struct
{
	SDL_Surface *txt;
	SDL_Rect pos_txt;
	SDL_Colour color_txt;
	TTF_Font *police;
}texte;

//image
void initialiser_imageBACK(image *image);
void initialiser_imageBOUTON1(image *imgbtn);
void initialiser_imageBOUTON2(image *imgbtn);
void initialiser_imageBOUTON3(image *imgbtn);
void initialiser_imageBACKSETTING(image *image);
void initialiser_imageSETTING1(image *imgbtn);
void initialiser_imageSETTING2(image *imgbtn);
void initialiser_imageSETTING3(image *imgbtn);
void afficher_imageBMP(SDL_Surface *screen,image imge);
void afficher_imageBTN1(SDL_Surface *screen,image imge);
void afficher_imageBTN2(SDL_Surface *screen,image imge);
void afficher_imageBTN3(SDL_Surface *screen,image imge);
void afficher_imageBACKSETTING(SDL_Surface *screen,image imge);
void afficher_imageSETTING1(SDL_Surface *screen,image imge);
void afficher_imageSETTING2(SDL_Surface *screen,image imge);
void afficher_imageSETTING3(SDL_Surface *screen,image imge);
void liberer_image(image imge);
//audio
void initialiser_audio(Mix_Music *music);
void liberer_musique(Mix_Music *music);
Mix_Chunk *initialiser_audiobref();
void liberer_musiquebref(Mix_Chunk *music);
//texte
void initialiser_texte(texte *txte);
void afficher_texte(SDL_Surface *screen,texte txte);
void liberer_texte(texte txte);

#endif
