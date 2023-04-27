#include <SDL/SDL.h>
#include "InGame.h"

void initialiser_MAIN_CHARACTER1(image *image)
{
//chargement de l'image
	imgcharacter1->ur1="/home/youssef/Desktop/Game/image/menu/character1(1).png";
	imgcharacter1->img[0]=IMG_Load(imgcharacter1->ur1);
	if (imgcharacter1->img[0]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgcharacter1->ur1="/home/youssef/Desktop/Game/image/menu/character1(2).png";
	imgcharacter1->img[1]=IMG_Load(imgcharacter1->ur1);
	if (imgcharacter1->img[1]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->pos_img_affiche.w=236;
	imgbtn->pos_img_affiche.h=55;
	imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2);
	imgbtn->pos_img_ecran.y=((SCREEN_W-imgbtn->pos_img_affiche.h)/2.39);

	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->i=1;
}

