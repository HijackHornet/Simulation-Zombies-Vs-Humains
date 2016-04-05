#include "affichage_SDL.h"
#include "defs.h"
#include "input.h"

void affichageFenetre(void)
{

    // Remplis le renderer de noir, efface l'écran et l'affiche.
    //SDL_RenderPresent() remplace SDL_Flip de la SDL 1.2

    SDL_SetRenderDrawColor(getrenderer(), 0, 0, 0, 255);
    SDL_RenderClear(getrenderer());
    SDL_RenderPresent(getrenderer());

    // Délai pour laisser respirer le proc
    SDL_Delay(1);
}


void delay(unsigned int frameLimit)
{
    // Gestion des 60 fps (images/stories/seconde)
    unsigned int ticks = SDL_GetTicks();

    if (frameLimit < ticks)
    {
        return;
    }

    if (frameLimit > ticks + 16)
    {
        SDL_Delay(16);
    }

    else
    {
        SDL_Delay(frameLimit - ticks);
    }
}
