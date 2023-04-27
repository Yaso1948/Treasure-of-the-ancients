#include <SDL/SDL.h>
#include "InGame.h"


// IMAGE

void initialiser_BACKGROUNDGAME(BACK *back)
{
//chargement de l'image
	back->ur2="/home/youssef/Desktop/Game/image/menu/backgroundgame1.bmp";
	back->bck[0]=SDL_LoadBMP(back->ur2);
	back->ur2="/home/youssef/Desktop/Game/image/menu/backgroundgame2.bmp";
	back->bck[1]=SDL_LoadBMP(back->ur2);
	if (back->bck[0]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	back->pos_img_ecran.x=0;
	back->pos_img_ecran.y=0;
	back->pos_img_affiche.x=0;
	back->pos_img_affiche.y=0;
	back->pos_img_affiche.h=SCREEN_H;
	back->pos_img_affiche.w=SCREEN_W;
	back->i=0;
}

//affichage
void afficher_BACKGROUNDGAME(SDL_Surface *screen,BACK back)
{
SDL_BlitSurface(back.bck[back.i],NULL,screen, &back.pos_img_ecran);
}

//liberer
void liberer_image_background(BACK back)
{
SDL_FreeSurface(back.bck[0]);
SDL_FreeSurface(back.bck[1]);
}

// SONO

void initialiser_audio_game(Mix_Music *gamemusic)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==1)
{
printf("%s",SDL_GetError());
}
gamemusic=Mix_LoadMUS("/home/youssef/Desktop/Game/sono/menu.mp3");
Mix_PlayMusic(gamemusic,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/2.5);
}

Mix_Chunk *initialiser_audiobref_game()
{
Mix_Chunk *gamemus;
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
gamemus = Mix_LoadWAV("/home/youssef/Desktop/Game/sono/click1.wav");

if(gamemus == NULL)
{
printf("%s",SDL_GetError());
}
return gamemus;
}

// TEXT
void initialiser_game_texte(gametexte *gametxte)
{
TTF_Init(); //initialiser SDL_TTF
gametxte->police=TTF_OpenFont("/home/youssef/Desktop/Game/text/holiday.ttf",45); //chargement d'une police et initialiser la taille
gametxte->color_gametxt.r=255;
gametxte->color_gametxt.g=255;
gametxte->color_gametxt.b=42;

gametxte->pos_gametxt.x=120;
gametxte->pos_gametxt.y=10;
}
void afficher_game_texte(SDL_Surface *screen,gametexte gametxte)
{
gametxte.gametxt=TTF_RenderText_Blended(gametxte.police,"Treasure Of The Ancients",gametxte.color_gametxt);
SDL_BlitSurface(gametxte.gametxt,NULL,screen,&gametxte.pos_gametxt);
}
void liberer_game_texte(gametexte gametxte)
{
TTF_CloseFont(gametxte.police); //fermer la police
TTF_Quit();
//arreter la SDL_ttf
}
