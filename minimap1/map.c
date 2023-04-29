
#include "map.h"

void initialiser_map (map *m,SDL_Surface *screen)
{
	m->map=IMG_Load("mini_backgg.png");
	m->pos_map.x = 240;
	m->pos_map.y = 80;
	m->mini_perso=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,12,12,32,0,0,0,0);
	SDL_FillRect(m->mini_perso,NULL,SDL_MapRGB(screen->format,0,0,0));
	m->perso_pos_map.x=0;
	m->perso_pos_map.y=0;

}


void perso_map(map *m,personne *p)
{
	m->perso_pos_map.x=p->pos_perso.x/10+m->pos_map.x;
	m->perso_pos_map.y=p->pos_perso.y/10+10+m->pos_map.y;
}



void affiche_map(map *m , SDL_Surface *screen,personne *p)
{
	SDL_BlitSurface(m->map, NULL, screen,&m->pos_map);
	SDL_BlitSurface(m->mini_perso, NULL, screen,&m->perso_pos_map);
}

