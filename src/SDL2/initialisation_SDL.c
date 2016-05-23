#include "initialisation_SDL.h"

SDL_Window *screen;
SDL_Renderer *renderer;

////////////////////////////////////////////////////////////////////
//ACCESSEUR  ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

SDL_Renderer *getrenderer()
{
    return renderer;
}


////////////////////////////////////////////////////////////////////
//INITIALISATION ET LIBERATION  ////////////////////////////////////
////////////////////////////////////////////////////////////////////

void init(char *title,Simulation * pSim)
{
    int screenheight, screenwidth;
    screenheight = getDimY_terr(getTerrain_sim(pSim)) * 50 *RENDERERSCALE;
    screenwidth = getDimX_terr(getTerrain_sim(pSim)) * 50 *RENDERERSCALE;

    screen = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  screenwidth, screenheight,
                                  SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);

    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode écran à %d x %d: %s\n", screenwidth,
                                                                    screenheight, SDL_GetError());
        exit(1);
    }
    SDL_RenderSetScale(renderer,RENDERERSCALE,RENDERERSCALE);

    //Initialisation du chargement des images png avec SDL_Image 2
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image n'a pu être initialisée! SDL_image Error: %s\n", IMG_GetError() );
        exit(1);
    }

}
void initEditeur(char *title, Terrain * pTerrain)
{
    int screenheight, screenwidth;
    screenheight = getDimY_terr(pTerrain) * 50 *RENDERERSCALE;
    screenwidth = getDimX_terr(pTerrain) * 50 *RENDERERSCALE;
    screen = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  screenwidth, screenheight,
                                  SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);

    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode écran à %d x %d: %s\n", screenwidth,
                                                                    screenheight, SDL_GetError());
        exit(1);
    }
    SDL_RenderSetScale(renderer,RENDERERSCALE,RENDERERSCALE);

    //Initialisation du chargement des images png avec SDL_Image 2
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf( "SDL_image n'a pu être initialisée! SDL_image Error: %s\n", IMG_GetError() );
        exit(1);
    }

}

void cleanup()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(screen);
    screen = NULL;
}
