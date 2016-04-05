#include "affichage_SDL.h"
#include "../defs.h"
#include "input.h"

SDL_Texture *loadImage(char *name)
{

    /* Charge les images avec SDL Image dans une SDL_Surface */

    SDL_Surface *loadedImage = NULL;
    SDL_Texture *texture = NULL;
    loadedImage = IMG_Load(name);

    assert(loadedImage != NULL);
    if (loadedImage != NULL)
    {
    // Conversion de l'image en texture
    texture = SDL_CreateTextureFromSurface(getrenderer(), loadedImage);

    // On se d�barrasse du pointeur vers une surface
    SDL_FreeSurface(loadedImage);
    loadedImage = NULL;
    }
    else
    printf("L'image n'a pas pu �tre charg�e! SDL_Error : %s\n", SDL_GetError());

    return texture;

}
void drawImage(SDL_Texture *image, int x, int y)
{

    SDL_Rect dest;

    /* R�gle le rectangle � dessiner selon la taille de l'image source */
    dest.x = x;
    dest.y = y;

    /* Dessine l'image enti�re sur l'�cran aux coordonn�es x et y */
    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(getrenderer(), image, NULL, &dest);

}
void affichageFenetre(void)
{
    SDL_Texture *fond;
    SDL_Texture *zombieText;
    SDL_Texture *citoyenText;
    SDL_Texture *policierText;
    fond = loadImage("../data/Graphics/Case.png");
    zombieText = loadImage("../data/Graphics/Zombie.png");
    citoyenText = loadImage("../data/Graphics/Citoyen.png");
    policierText = loadImage("../data/Graphics/Policier.png");
    int i,j;
    i=0; j=0;
    while(i<SCREEN_WIDTH){
            while(j<SCREEN_HEIGHT){
                drawImage(fond,i,j);
                j=j+50;
            }
            i=i+50;
            j=0;
    }

     // Affiche l'�cran
    SDL_RenderPresent(getrenderer());

    // D�lai pour laisser respirer le proc
    SDL_Delay(1);

    // D�lai pour laisser respirer le proc
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
