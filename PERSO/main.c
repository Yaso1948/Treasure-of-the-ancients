#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "perso.h"
int main()
{
    perso p,p2, image;
    health h,h2;
    SDL_Rect posp;
    SDL_Rect pose;
    SDL_Surface *screen;
    SDL_Event event;
    int boucle = 1, left = 0, right = 0, key = 0 , speed=0, left2 = 0, right2 = 0, key2 = 0 , speed2=0;
    int collision;
	
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) == -1)
    {
        printf("could not initialize SDL:%s\n", SDL_GetError());
        return -1;
    }

    screen = SDL_SetVideoMode(1720, 880, 32, SDL_SWSURFACE | SDL_DOUBLEBUF);
    initImage(&image);
    initperso(&p);
    initperso2(&p2);
    initImagehealth(&h);
    initImagehealth2(&h2);
    while (boucle)
    {	
	
	int up=0,up2=0;
        // Handle events
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                boucle = 0;
                break;
            case SDL_KEYDOWN:
               
		if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    right = 1;
                }
                else if (event.key.keysym.sym == SDLK_LEFT)
                {
                    left = 1;
                }
		else if (event.key.keysym.sym == SDLK_UP)
                {
                    up = 1;
                }
		else if (event.key.keysym.sym == SDLK_RSHIFT)
                {
                    speed = 1;
                }
		else if (event.key.keysym.sym == SDLK_d)
                {
                    right2 = 1;
                }
                else if (event.key.keysym.sym == SDLK_q)
                {
                    left2 = 1;
                }
		else if (event.key.keysym.sym == SDLK_z)
                {
                    up2 = 1;
                }
		else if (event.key.keysym.sym == SDLK_LSHIFT)
                {
                    speed2 = 1;
                }
                break;
            case SDL_KEYUP:
                if (event.key.keysym.sym == SDLK_RIGHT)
                {
                    right = 0;
		    p.etat=0;
			
                }
                else if (event.key.keysym.sym == SDLK_LEFT)
                {
                    left = 0;
      		    p.etat=0;
                }
		else if (event.key.keysym.sym == SDLK_UP)
                {
                    up = 0;
		    p.etat=0;	
                }
		else if (event.key.keysym.sym == SDLK_RSHIFT)
                {
                    speed =0;
		    p.etat=0;
                }
		else if (event.key.keysym.sym == SDLK_d)
                {
                    right2 = 0;
		    p2.etat=0;
                }
                else if (event.key.keysym.sym == SDLK_q)
                {
                    left2 = 0;
		    p2.etat=0;
                }
		else if (event.key.keysym.sym == SDLK_z)
                {
                    up2 = 0;
                }
		else if (event.key.keysym.sym == SDLK_LSHIFT)
                {
                    speed2 =0;
                }
                break;
            }
        }

        // Update character position based on input
	if (up && right && speed)
        {
	p.speed=2;
        p.direction = 2;
        move(&p);
        } 
	else if (up && left && speed)
        {
	p.speed=2;
        p.direction = -2;
        move(&p);
        } 
	else if (right && speed)
        {
	p.speed=2;
        p.direction = 1;
        move(&p);
        } 	
	else if (left && speed)
        {
	p.speed=2;
        p.direction = -1;
        move(&p);
        }           
	else if (up && right)
        {
        p.direction = 2;
        move(&p);
        }
	else if (up && left)
        {
         p.direction = -2;
         move(&p);
        }
	else if (left)
        {
            p.direction = -1;
            move(&p);
        }
        else if (right)
        {
            p.direction = 1;
            move(&p);
        }
	else if (up)
        {
            p.direction = 3;
            move(&p);
        } 
        else
{
	p.direction = 0;
	p.speed=1;
}
	if (up2 && right2 && speed2)
        {
	p2.speed=2;
        p2.direction = 2;
        move(&p2);
        } 
	else if (up2 && left2 && speed2)
        {
	p2.speed=2;
        p2.direction = -2;
        move(&p2);
        } 
	else if (right2 && speed2)
        {
	p2.speed=2;
        p2.direction = 1;
        move(&p2);
        } 	
	else if (left2 && speed2)
        {
	p2.speed=2;
        p2.direction = -1;
        move(&p2);
        }           
	else if (up2 && right2)
        {
        p2.direction = 2;
        move(&p2);
        }
	else if (up2 && left2)
        {
         p2.direction = -2;
        move(&p2);
        }
	else if (left2)
        {
            p2.direction = -1;
            move(&p2);
        }
        else if (right2)
        {
            p2.direction = 1;
            move(&p2);
        }
	else if (up2)
        {
            p2.direction = 3;
            move(&p2);
        } 
	
        else
	{
	p2.direction = 0;
	p2.speed=1;
	}

	jump(&p);
	jump(&p2);
        afficherperso(image, screen);
        afficherperso(p, screen);
        afficherhealth(h, screen);
        SDL_Flip(screen);
 	SDL_Delay(5);
	animerperso(&p);
	animerperso(&p2);
	/*while(contact enemy with character)
	{
	h.life++;
	SDL_Delay(10);
	SDL_Flip(screen);
	
	}*/
    }

    liberer_image(p);
    liberer_image(p2);
    liberer_image(image);
    liberer_image2(h);
    liberer_image2(h2);
    SDL_Quit();

    return 0;
}
