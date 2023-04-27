#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"



void initperso(perso *p  )
{

p->etat=0;
p->direction=0;
p->speed=1;
p->url="perso/perso0.png";
p->pers[0]=IMG_Load(p->url);
p->pers[1]=IMG_Load("perso/perso1.png");
p->pers[2]=IMG_Load("perso/perso2.png");
p->pers[3]=IMG_Load("perso/perso3.png");
p->pers[4]=IMG_Load("perso/perso4.png");
p->pers[5]=IMG_Load("perso/perso5.png");
p->pers[6]=IMG_Load("perso/perso6.png");
p->pers[7]=IMG_Load("perso/perso7.png");
p->pers[8]=IMG_Load("perso/perso8.png");
p->pers[8]=IMG_Load("perso/perso9.png");
p->pers[10]=IMG_Load("perso/perso10.png");
p->pers[11]=IMG_Load("perso/perso11.png");
p->pers[12]=IMG_Load("perso/perso12.png");
p->pers[13]=IMG_Load("perso/perso13.png");



if(p->pers==NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;

}
p->pos_enne_ecran.x=720;
p->pos_enne_ecran.y=580;
p->pos_enne_affiche.x=0;
p->pos_enne_affiche.y=0;
p->pos_enne_affiche.h=p->pers[0]->h;
p->pos_enne_affiche.w=p->pers[0]->w;


}

void initperso2(perso *p)
{
p->etat=0;
p->direction=0;
p->speed=1;
p->url="person0.png";
p->pers[0]=IMG_Load(p->url);
p->pers[1]=IMG_Load("person1.png");
p->pers[2]=IMG_Load("person2.png");
p->pers[3]=IMG_Load("person3.png");
p->pers[4]=IMG_Load("person4.png");
p->pers[5]=IMG_Load("person5.png");
p->pers[6]=IMG_Load("person6.png");
p->pers[7]=IMG_Load("person7.png");
p->pers[8]=IMG_Load("person8.png");
p->pers[9]=IMG_Load("person9.png");
p->pers[10]=IMG_Load("person10.png");
p->pers[11]=IMG_Load("person11.png");
p->pers[12]=IMG_Load("person12.png");
p->pers[13]=IMG_Load("person13.png");
if(p->pers==NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;

}
p->pos_enne_ecran.x=720;
p->pos_enne_ecran.y=580;
p->pos_enne_affiche.x=0;
p->pos_enne_affiche.y=0;
p->pos_enne_affiche.h=p->pers[0]->h;
p->pos_enne_affiche.w=p->pers[0]->w;
}


void initImage(perso *p)
{
p->etat=0;
p->url="/home/youssef/Desktop/Treasure-of-the-ancients/PERSO/image/menu/game.jpg";
p->pers[0]=IMG_Load(p->url);

if(p->pers==NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;

}
p->pos_enne_ecran.x=0;
p->pos_enne_ecran.y=0;
p->pos_enne_affiche.x=0;   
p->pos_enne_affiche.y=0;
p->pos_enne_affiche.h=880;
p->pos_enne_affiche.w=1720;
}

void initImagehealth(health *hel)
{
hel->life=0;
hel->url="healthbar/healthbar.png";
hel->health[0]=IMG_Load(hel->url);
hel->health[1]=IMG_Load("healthbar/healthbar1.png");
hel->health[2]=IMG_Load("healthbar/healthbar2.png");
hel->health[3]=IMG_Load("healthbar/healthbar3.png");
hel->health[4]=IMG_Load("healthbar/healthbar4.png");
if(hel->health==NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;

}
hel->pos_enne_ecran.x=0;
hel->pos_enne_ecran.y=0;
hel->pos_enne_affiche.x=0;   
hel->pos_enne_affiche.y=0;
hel->pos_enne_affiche.h=hel->health[0]->h;
hel->pos_enne_affiche.w=hel->health[0]->w;
}

void initImagehealth2(health *hel)
{
hel->life=0;
hel->url="healthbar/healthbar.png";
hel->health[0]=IMG_Load(hel->url);
hel->health[1]=IMG_Load("healthbar/healthbar1.png");
hel->health[2]=IMG_Load("healthbar/healthbar2.png");
hel->health[3]=IMG_Load("healthbar/healthbar3.png");
hel->health[4]=IMG_Load("healthbar/healthbar4.png");
if(hel->health==NULL){
printf("unable to load background image %s \n",SDL_GetError());
return ;

}
hel->pos_enne_ecran.x=1400;
hel->pos_enne_ecran.y=0;
hel->pos_enne_affiche.x=0;   
hel->pos_enne_affiche.y=0;
hel->pos_enne_affiche.h=hel->health[0]->h;
hel->pos_enne_affiche.w=hel->health[0]->w;
}

void afficherperso(perso p, SDL_Surface  * screen)
{
SDL_BlitSurface(p.pers[p.etat], NULL,screen,&p.pos_enne_ecran);

}

void afficherhealth(health hel, SDL_Surface  * screen)
{
SDL_BlitSurface(hel.health[hel.life], NULL,screen,&hel.pos_enne_ecran);

}

//deplacement
void move(perso *p)
{
if(p->direction==3)
p->pos_enne_ecran.y;
if (p->direction==2 && p->pos_enne_ecran.x <= 860 || p->direction==1 && p->pos_enne_ecran.x <= 860)
p->pos_enne_ecran.x = (p->pos_enne_ecran.x+15*(p->direction*p->speed));
if (p->direction==-2 && p->pos_enne_ecran.x >=10 || p->direction==-1 && p->pos_enne_ecran.x >=10)
p->pos_enne_ecran.x = (p->pos_enne_ecran.x+15*(p->direction*p->speed));
}
void jump(perso *p)
{
if(p->direction==2 )
p->pos_enne_ecran.y =(-100*(-0.2*-0.2)+(500*p->speed));
else if(p->direction==-2)
p->pos_enne_ecran.y =(10*(-0.2*-0.2)+(500*p->speed));
else if(p->direction==3)
p->pos_enne_ecran.y =(0*(-0.2*-0.2)+500);
else if(p->direction!=2 || p->direction!=-2 || p->direction!=3)
p->pos_enne_ecran.y=580;
SDL_Delay(50);
}
//animer
void animerperso( perso *p)
{
if(p->direction==0)
{
   	if(p->etat==0)
	p->etat=1;
	else if(p->etat==1)
	p->etat=3;
	else if(p->etat==3)
	p->etat=0;
	
	SDL_Delay(10);
	
}
else if(p->direction==1)
{
	if(p->etat==0)
	p->etat=4;
	else if(p->etat==4)
	p->etat=5;
	else if(p->etat==5)
	p->etat=6;
	else if(p->etat==6)
	p->etat=7;
	else if(p->etat==7)
	p->etat=4;
	else
	p->etat=0;
	SDL_Delay(10);
}
else if(p->direction==-1)
{
	if(p->etat==0)
	p->etat=11;
	else if(p->etat==11)
	p->etat=10;
	else if(p->etat==10)
	p->etat=8;
	else if(p->etat==8)
	p->etat=11;
	else
	p->etat=0;
	SDL_Delay(10);
}
else if(p->direction==3 || p->direction==2 )
{
	if(p->etat==0)
	p->etat=13;
	else
	p->etat=0;
	SDL_Delay(10);
}
else 
p->etat=0;
}

void liberer_image(perso p)
{
SDL_FreeSurface(p.pers[p.etat]);
}
void liberer_image2(health hel)
{
SDL_FreeSurface(hel.health[hel.life]);
}

