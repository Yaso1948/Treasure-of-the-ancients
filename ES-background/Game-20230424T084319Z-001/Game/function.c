#include <SDL/SDL.h>
#include "function.h"

//IMAGE

void initialiser_imageBACK(image *imge)
{
//chargement de l'image
	imge->ur1="/home/youssef/Desktop/Game/image/menu/background.bmp";
	imge->img[0]=SDL_LoadBMP(imge->ur1);
	imge->ur1="/home/youssef/Desktop/Game/image/menu/background.bmp";
	imge->img[1]=SDL_LoadBMP(imge->ur1);
	if (imge->img[0]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imge->pos_img_ecran.x=0;
	imge->pos_img_ecran.y=0;
	imge->pos_img_affiche.x=0;
	imge->pos_img_affiche.y=0;
	imge->pos_img_affiche.h=SCREEN_H;
	imge->pos_img_affiche.w=SCREEN_W;
	imge->i=0;
}
void initialiser_imageBOUTON1(image *imgbtn)
{
//chargement de l'image
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/playbefore.png";
	imgbtn->img[0]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[0]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/play.png";
	imgbtn->img[1]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[1]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->pos_img_affiche.w=236;
	imgbtn->pos_img_affiche.h=55;
	imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2);
	imgbtn->pos_img_ecran.y=((SCREEN_W-imgbtn->pos_img_affiche.h)/4);

	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->i=1;
}

void initialiser_imageBOUTON2(image *imgbtn)
{
//chargement de l'image
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/settingsbefore.png";
	imgbtn->img[0]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[0]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/settings.png";
	imgbtn->img[1]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[1]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->pos_img_affiche.w=236;
	imgbtn->pos_img_affiche.h=55;
	imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2);
	imgbtn->pos_img_ecran.y=((SCREEN_W-imgbtn->pos_img_affiche.h)/3);

	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->i=0;
}

void initialiser_imageBOUTON3(image *imgbtn)
{
//chargement de l'image
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/quitbefore.png";
	imgbtn->img[0]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[0]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/quit.png";
	imgbtn->img[1]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[1]==NULL)
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
	imgbtn->i=0;
}

void initialiser_imageSETTING1(image *imgbtn)
{
//chargement de l'image
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/settingsbefore.png";
	imgbtn->img[0]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[0]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/settings.png";
	imgbtn->img[1]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[1]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->pos_img_affiche.w=236;
	imgbtn->pos_img_affiche.h=55;
	imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2);
	imgbtn->pos_img_ecran.y=((SCREEN_W-imgbtn->pos_img_affiche.h)/4);

	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->i=0;
}

void initialiser_imageSETTING2(image *imgbtn)
{
//chargement de l'image
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/settingsbefore.png";
	imgbtn->img[0]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[0]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/settings.png";
	imgbtn->img[1]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[1]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->pos_img_affiche.w=236;
	imgbtn->pos_img_affiche.h=55;
	imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2);
	imgbtn->pos_img_ecran.y=((SCREEN_W-imgbtn->pos_img_affiche.h)/3);

	imgbtn->pos_img_affiche.x=0;
	imgbtn->pos_img_affiche.y=0;
	imgbtn->i=0;
}

void initialiser_imageSETTING3(image *imgbtn)
{
//chargement de l'image
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/settingsbefore.png";
	imgbtn->img[0]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[0]==NULL)
	  {
            printf("unable to load background image %s \n",SDL_GetError());
	    return ;

	   }
	imgbtn->ur1="/home/youssef/Desktop/Game/image/menu/settings.png";
	imgbtn->img[1]=IMG_Load(imgbtn->ur1);
	if (imgbtn->img[1]==NULL)
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
	imgbtn->i=0;
}

void afficher_imageBMP(SDL_Surface *screen,image imge)
{
//Coller et afficher l'image du back ds screen
	SDL_BlitSurface(imge.img[imge.i],&imge.pos_img_affiche,screen,&imge.pos_img_ecran);
}
void afficher_imageBTN1(SDL_Surface *screen,image imge)
{
//Coller et afficher l'image du btn play ds screen
SDL_BlitSurface(imge.img[imge.i],NULL,screen, &imge.pos_img_ecran);
}
void afficher_imageBTN2(SDL_Surface *screen,image imge)
{
//Coller et afficher l'image du btn settings ds screen
SDL_BlitSurface(imge.img[imge.i],NULL,screen, &imge.pos_img_ecran);
}
void afficher_imageBTN3(SDL_Surface *screen,image imge)
{
//Coller et afficher l'image du btn quit ds screen
SDL_BlitSurface(imge.img[imge.i],NULL,screen, &imge.pos_img_ecran);
}
void afficher_imageSETTING1(SDL_Surface *screen,image imge)
{
SDL_BlitSurface(imge.img[imge.i],NULL,screen, &imge.pos_img_ecran);
}
void afficher_imageSETTING2(SDL_Surface *screen,image imge)
{
SDL_BlitSurface(imge.img[imge.i],NULL,screen, &imge.pos_img_ecran);
}
void afficher_imageSETTING3(SDL_Surface *screen,image imge)
{
SDL_BlitSurface(imge.img[imge.i],NULL,screen, &imge.pos_img_ecran);
}
void liberer_image(image imge)
{
SDL_FreeSurface(imge.img[0]);
SDL_FreeSurface(imge.img[1]);
}


//SONO

void initialiser_audio(Mix_Music *music)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==1)
{
printf("%s",SDL_GetError());
}
music=Mix_LoadMUS("/home/youssef/Desktop/Game/sono/menu.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/2.5);
}

void liberer_musique(Mix_Music *music)
{
Mix_FreeMusic(music);
}

Mix_Chunk *initialiser_audiobref()
{
Mix_Chunk *music;
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
music = Mix_LoadWAV("/home/youssef/Desktop/Game/sono/click1.wav");

if(music == NULL)
{
printf("%s",SDL_GetError());
}
return music;
}

void liberer_musiquebref(Mix_Chunk *music)
{
Mix_FreeChunk(music);
}

//TEXT

void initialiser_texte(texte *txte)
{
TTF_Init(); //initialiser SDL_TTF
txte->police=TTF_OpenFont("/home/youssef/Desktop/Game/text/holiday.ttf",45); //chargement d'une police et initialiser la taille
txte->color_txt.r=255;
txte->color_txt.g=255;
txte->color_txt.b=42;

txte->pos_txt.x=120;
txte->pos_txt.y=10;
}
void afficher_texte(SDL_Surface *screen,texte txte)
{
txte.txt=TTF_RenderText_Blended(txte.police,"Treasure Of The Ancients",txte.color_txt);
SDL_BlitSurface(txte.txt,NULL,screen,&txte.pos_txt);
}
void liberer_texte(texte txte)
{
TTF_CloseFont(txte.police); //fermer la police
TTF_Quit();
//arreter la SDL_ttf
}/*#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

//IMAGE

void initialiser_imageBACK(image *imge)
{
imge->url="background.bmp";
imge->img=SDL_LoadBMP(imge->url);

if(imge->img == NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}

imge->pos_img_ecran.x=0;
imge->pos_img_ecran.y=0;
imge->pos_img_affiche.x=0;
imge->pos_img_affiche.y=0;
imge->pos_img_affiche.h=SCREEN_H;
imge->pos_img_affiche.w=SCREEN_W;
}

void initialiser_imageBOUTON1(image *imgbtn)
{
imgbtn->url="play.png";
imgbtn->img=IMG_Load(imgbtn->url);

if(imgbtn->img == NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}

imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=0;
imgbtn->pos_img_affiche.w=237;
imgbtn->pos_img_affiche.h=50;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2);
imgbtn->pos_img_ecran.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3);
}

void initialiser_imageBOUTON2(image *imgbtn)
{
imgbtn->url="quit.png";
imgbtn->img=IMG_Load(imgbtn->url);

if(imgbtn->img == NULL)
{
printf("unable to load background image %s \n",SDL_GetError());
return;
}

imgbtn->pos_img_affiche.x=0;
imgbtn->pos_img_affiche.y=-50;
imgbtn->pos_img_affiche.w=236;
imgbtn->pos_img_affiche.h=55;
imgbtn->pos_img_ecran.x=((SCREEN_W-imgbtn->pos_img_affiche.w)/2);
imgbtn->pos_img_ecran.y=((SCREEN_H-imgbtn->pos_img_affiche.h)/3);
}

void afficher_imageBMP(SDL_Surface *screen, image imge)
{
SDL_BlitSurface(imge.img, &imge.pos_img_affiche, screen, &imge.pos_img_ecran);
}

void afficher_imageBTN1(SDL_Surface *screen, image imge)
{
SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void afficher_imageBTN2(SDL_Surface *screen, image imge)
{
SDL_BlitSurface(imge.img, NULL, screen, &imge.pos_img_ecran);
}

void liberer_image(image imge)
{
SDL_FreeSurface(imge.img);
}

//SONO
 
void initialiser_audio(Mix_Music *music)
{
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==1)
{
printf("%s",SDL_GetError());
}
music=Mix_LoadMUS("menu.mp3");
Mix_PlayMusic(music,-1);
Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}

void liberer_musique(Mix_Music *music)
{
Mix_FreeMusic(music);
}

void initialiser_audiobref(Mix_Chunk *music)
{
Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
music = Mix_LoadWAV("click.mp3");
Mix_PlayChannel(1, music, 0);
if(music == NULL)
{
printf("%s",SDL_GetError());
}
}

void liberer_musiquebref(Mix_Chunk *music)
{
Mix_FreeChunk(music);
}

//TEXT

//void initialiser_texte(texte *text)
//{
//TTF_Init();
//text->police = TTF_OpenFont("Ubuntu-B.ttf", 45);
//text->color_txt.r=0;
//text->color_txt.g=0;
//text->color_txt.b=0;

//text->pos_txt.x=210;
//text->pos_txt.y=0;
//}

//void afficher_texte(SDL_Surface *screen, texte text)
//{
//text.txt=TTF_RenderText_Blended(text.police, "Welcome", text.color_txt);
//SDL_BlitSurface(text.txt, NULL, screen, &text.pos_txt);
//}

//void liberer_texte(texte text)
//{
//TTF_CloseFont(text.police);
//TTF_Quit();
//}
*/

