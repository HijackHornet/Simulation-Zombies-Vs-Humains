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

void init(char *title)
{

    screen = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  SCREEN_WIDTH, SCREEN_HEIGHT,
                                  SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);

    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode écran à %d x %d: %s\n", SCREEN_WIDTH,
                                                                    SCREEN_HEIGHT, SDL_GetError());
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
void initEditeur(char *title)
{

    screen = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  FULLSCREEN_WIDTH, FULLSCREEN_HEIGHT,
                                  SDL_WINDOW_FULLSCREEN);

    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_PRESENTVSYNC);

    if (screen == NULL || renderer == NULL)
    {
        printf("Impossible d'initialiser le mode écran à %d x %d: %s\n", FULLSCREEN_WIDTH,
                                                                    FULLSCREEN_HEIGHT, SDL_GetError());
        exit(1);
    }
    SDL_RenderSetScale(renderer,FULLSCREEN_RENDERERSCALE,FULLSCREEN_RENDERERSCALE);

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

    SDL_Quit();
}
