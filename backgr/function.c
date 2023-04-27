#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "function.h"
#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 440

void initialiser_texte(texte *txte,int x, int y)
{
	txte->police=TTF_OpenFont("pol.ttf",27);
	txte->color_txt.r=255;
	txte->color_txt.g=255;
	txte->color_txt.b=0;
	txte->pos_txt.x=x;
//(SCREEN_WIDTH-(txte->txt->w))/2;
	txte->pos_txt.y=y;
//90;
}

void initialiser_audio(Mix_Music *music)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==1)
{
printf("%s",SDL_GetError());
}
music=Mix_LoadMUS("son.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/2.5);
}

void liberer_musique(Mix_Music *music)
{
Mix_FreeMusic(music);
}


void initBack (background *b)
{
b->bg[0]=IMG_Load("bac2.png");
b->bg[1]=IMG_Load("bac3.png");
b->bg[2]=IMG_Load("bac1.png");
b->frame=0;
b->pos.x=0;
b->pos.y=0;
b->pos.w=b->bg[0]->w;;
b->pos.h=b->bg[0]->h;

b->camera.x=0;
b->camera.y=0;
b->camera.w=SCREEN_WIDTH;
b->camera.h=SCREEN_HEIGHT;
b->v.position.x=25;
b->v.position.y=25;
b->v.img_vie[2]=IMG_Load("health3.png");
b->v.img_vie[1]=IMG_Load("health2.png");
b->v.img_vie[0]=IMG_Load("health1.png");
initialiser_texte(&b->score,616, 25);
}

void afficher_texte(texte* txte,char texte[100],SDL_Surface *screen)
{
txte->txt = TTF_RenderText_Blended(txte->police,texte,txte->color_txt);
SDL_BlitSurface(txte->txt ,NULL,screen,&txte->pos_txt);

}

void afficherBack(background b, SDL_Surface *screen,int v,int score)
{
char scr[100];
SDL_BlitSurface(b.bg[b.frame],&(b.camera),screen,&(b.pos));
SDL_BlitSurface(b.v.img_vie[v-1],NULL,screen,&(b.v.position));
sprintf(scr,"score: %d",score);
 afficher_texte(&b.score,scr,screen);
}

void scrolling(background *back, int direction) {
    if (direction == 1) {
        // Scroll right
        if (back->camera.x < (back->pos.w - SCREEN_WIDTH)) {
            back->camera.x += 1.5;
            if (back->camera.x > (back->pos.w - SCREEN_WIDTH)) {
                back->camera.x = back->pos.w - SCREEN_WIDTH;
            }
        }
    } else if (direction == 2) {
        // Scroll left
        if (back->camera.x > 0) {
            back->camera.x -= 1.1;
            if (back->camera.x < 0) {
                back->camera.x = 0;
            }
        }
    } else if (direction == 3) {
        // Scroll up
        if (back->camera.y > 0) {
            back->camera.y -= 1.5;
            if (back->camera.y < 0) {
                back->camera.y = 0;
            }
        }
    } else if (direction == 4) {
        // Scroll down
        if (back->camera.y < (back->pos.h - SCREEN_HEIGHT)) {
            back->camera.y += 1.1;
            if (back->camera.y > (back->pos.h - SCREEN_HEIGHT)) {
                back->camera.y = back->pos.h - SCREEN_HEIGHT;
            }
        }
    }
}



void animerBack (background *b)
{
if(b->frame==2)
  b->frame=0;
else
 b->frame+=1;

}



void liberer_texte (texte txte)
{
    TTF_CloseFont(txte.police);
    TTF_Quit();
}



void freeFont(TTF_Font **police)
{
	TTF_CloseFont(*police);
    TTF_Quit();	
}

