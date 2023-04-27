#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>
#include "ES.h"
#include "function.h"

/*
void initialiser_imageBACK(image *imge)
{
//chargement de l'image
 	imge->ur1="back.png";
	imge->img=IMG_Load(imge->ur1);
	if(imge->img==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imge->pos_img_ecran.x=0;
	imge->pos_img_ecran.y=0;
        
}*/


/*void liberer_back(image imge)
{
//liberation background
SDL_FreeSurface(imge.img);
}*/
//ennemi aspect image seulement
/*void initialiser_object(Ennemi* imag){
	imag->ur1="one_golem.png";
	imag->img=IMG_Load(imag->ur1);
	if(imag->img == NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imag->pos.y=340;
	imag->pos.x=240;
}*/

/*void initialiser_step_sound(Ennemi *e){
	Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
	e->step_sound=Mix_LoadWAV("/home/yaso/Documents/game/ESsprite/enemies/golem_step.wav");
}
void liberer_step_sound(Mix_Chunk *music){
	Mix_FreeChunk(music);
}*/

void initialiser_ennemi(Ennemi* imag,char ref[],int x,int y,int pos_M,int pos_m,int first_sprite_x,int first_sprite_y,int width,int height)
{
      imag->ur1=ref;
      imag->img=IMG_Load(imag->ur1);
      
      if(imag->img == NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
      imag->pos.y=y;
      imag->pos.x=x;
      imag->pos_max=pos_M;//borne  de deplacement
      imag->pos_min=pos_m;//borne de deplacement
      imag->sprite.x=first_sprite_x;
      imag->sprite.y=first_sprite_y;
      imag->sprite.w=width;
      imag->sprite.h=height;//initialisation du premier frame su spritesheet	
}

void afficher_object(SDL_Surface *screen,Ennemi imag){
     SDL_BlitSurface(imag.img,NULL,screen,&imag.pos);

}
void liberer_image_ennemi(Ennemi imag){
        SDL_FreeSurface(imag.img);
}
void move(Ennemi *e){
     if(e->pos.x<e->pos_min){
	e->dir=0;
	}
     if(e->pos.x>e->pos_max){
	e->dir=1;
       }
     switch(e->dir){
          case 0:
               e->pos.x+=10;
               break;
          case 1:
               e->pos.x-=10;
               break;
}

}

void animer_ennemi(Ennemi * e)
{

    e->sprite.x = e->sprite.x + 61;
    if(e->sprite.x >= 492)
    {
        e->sprite.x=0;
    }
    e->sprite.y = e->dir * 110 ;   
    SDL_Delay(50);
	
    
}
void afficher_ennemi(SDL_Surface *screen,Ennemi imag, background p){
     imag.pos.x = imag.pos.x - p.camera.x;
     SDL_BlitSurface(imag.img,&imag.sprite,screen,&imag.pos);


}
int bounding_box(SDL_Rect ep,SDL_Rect pp){
	int collision = 0;
	if((pp.x + pp.w < ep.x)||(pp.x >  ep.x + ep.w)||(pp.y + pp.h < ep.y)||(pp.y>ep.y + ep.h)){
	collision=0;}
	else {if((pp.x + pp.w == ep.x)||(pp.x ==  ep.x + ep.w)||(pp.y + pp.h == ep.y)||(pp.y == ep.y + ep.h)){collision=1;}}
        return collision;}

	
	


