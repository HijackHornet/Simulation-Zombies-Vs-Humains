#include "initialisationSDL.h"
#include "affichage_SDL.h"
#include "../defs.h"
#include "input.h"

SDL_Window *screen;
SDL_Renderer *renderer;


SDL_Renderer *getrenderer(void)
{
    return renderer;
}


void init(char *title)
{
    /* On cr�e la fen�tre, repr�sent�e par le pointeur jeu.window en utilisant la largeur et la
    hauteur d�finies dans les defines (defs.h).
    Nouveaut�s SDL2 : on peut centrer la fen�tre avec SDL_WINDOWPOS_CENTERED, et choisir la taille
    de la fen�tre, pour que la carte graphique l'agrandisse automatiquement. Notez aussi qu'on peut
    maintenant cr�er plusieurs fen�tres. */

    screen = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);

    //On cr�e un renderer pour la SDL et on active la synchro verticale : VSYNC
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);

    // Si on n'y arrive pas, on quitte en enregistrant l'erreur dans stdout.txt
    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode �cran � %d x %d: %s\n", SCREEN_WIDTH,
                                                                    SCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }
    SDL_RenderSetScale(renderer,RENDERERSCALE,RENDERERSCALE);

    //Initialisation du chargement des images png avec SDL_Image 2
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image n'a pu �tre initialis�e! SDL_image Error: %s\n", IMG_GetError() );
        exit(1);
    }


    // D�finit le nombre de pistes audio (channels) � mixer
    Mix_AllocateChannels(32);

}



void cleanup()
{
    //On quitte SDL_Mixer 2 et on d�charge la m�moire
    Mix_CloseAudio();
    Mix_Quit();

    //On fait le m�nage et on remet les pointeurs � NULL
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;

    //On quitte SDL_TTF 2
    TTF_Quit();

    //On quitte la SDL
    SDL_Quit();
}
