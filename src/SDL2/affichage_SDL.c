#include "affichage_SDL.h"
#include "../defs.h"
#include "input.h"


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

    // On se débarrasse du pointeur vers une surface
    SDL_FreeSurface(loadedImage);
    loadedImage = NULL;
    }
    else
    printf("L'image n'a pas pu être chargée! SDL_Error : %s\n", SDL_GetError());

    return texture;

}
void drawImage(SDL_Texture *image, int x, int y)
{

    SDL_Rect dest;

    /* Règle le rectangle à dessiner selon la taille de l'image source */
    dest.x = x;
    dest.y = y;

    /* Dessine l'image entière sur l'écran aux coordonnées x et y */
    SDL_QueryTexture(image, NULL, NULL, &dest.w, &dest.h);
    SDL_RenderCopy(getrenderer(), image, NULL, &dest);

}
void afficherPersoFenetre(Simulation * pSim){

    Terrain * pTerrain = getTerrain_sim(pSim);

    SDL_Texture *zombieText;
    SDL_Texture *citoyenText;
    SDL_Texture *policierText;

    zombieText = loadImage("../data/Graphics/Zombie.png");
    citoyenText = loadImage("../data/Graphics/Citoyen.png");
    policierText = loadImage("../data/Graphics/Policier.png");

    for(int i = 0; i < getDimY_terr(pTerrain); i++){
        for (int j = 0; j < getDimX_terr(pTerrain); j++) {
            if(getPersoCase(getGrilleByXY_terr(j, i, pTerrain)) != NULL){
                if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == ZOMBIE){
                    drawImage(zombieText,j*50,i*50);
                }
                else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == CITOYEN){
                    drawImage(citoyenText,j*50,i*50);
                }
                else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == POLICIER){
                    drawImage(policierText,j*50,i*50);
                }
            }
	    }
	}


   SDL_RenderPresent(getrenderer());

    // Délai pour laisser respirer le proc
    SDL_Delay(500);
}

void affichageFenetre(Simulation *pSim)
{
    SDL_Texture *fond;

    fond = loadImage("../data/Graphics/Case.png");

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



     // Affiche l'écran
    SDL_RenderPresent(getrenderer());

    // Délai pour laisser respirer le proc
    SDL_Delay(1);

    // Délai pour laisser respirer le proc
    SDL_Delay(1);
}




