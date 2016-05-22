#include "affichage_SDL.h"

void delay(unsigned int frameLimit)
{
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
void afficherParamFenetre(Simulation * pSim){

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
	  drawImage(zombieText,j*50,(getDimY_terr(pTerrain)*50 - i*50)-50);
	}
	else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == CITOYEN){
	  drawImage(citoyenText,j*50,(getDimY_terr(pTerrain)*50 - i*50)-50);
	}
	else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == POLICIER){
	  drawImage(policierText,j*50,(getDimY_terr(pTerrain)*50 - i*50)-50);

	}
      }


    }
  }

  SDL_RenderPresent(getrenderer());


  SDL_Delay(DELAYREFRESH);
  SDL_RenderClear(getrenderer());

}

void affichageFenetre(Simulation *pSim)
{

  Terrain * pTerrain = getTerrain_sim(pSim);
  SDL_Texture *fond;
  SDL_Texture *murText;

  int screenheight, screenwidth;
  screenheight = getDimY_terr(getTerrain_sim(pSim)) * 50 *RENDERERSCALE;
  screenwidth = getDimX_terr(getTerrain_sim(pSim)) * 50 *RENDERERSCALE;

  fond = loadImage("../data/Graphics/Case.png");
  murText = loadImage("../data/Graphics/Mur.png");
  int i,j;
  i=0; j=0;
  while(i<screenwidth*(1/RENDERERSCALE)){
    while(j<screenheight*(1/RENDERERSCALE)){
      drawImage(fond,i,j);
      j=j+50;
    }
    i=i+50;
    j=0;
  }


  for(int i = 0; i < getDimY_terr(pTerrain); i++){
    for (int j = 0; j < getDimX_terr(pTerrain); j++) {
      if(getEnvCase(getGrilleByXY_terr(j, i, pTerrain)) == MUR){
	drawImage(murText,j*50,(getDimY_terr(pTerrain)*50 - i*50)-50);
      }
    }
  }





  afficherParamFenetre(pSim);
}
void affichageFenetreEditeur(Terrain * pTerrain)
{

  SDL_Texture *fond;
  SDL_Texture *murText;
  fond = loadImage("../data/Graphics/Case.png");
  murText = loadImage("../data/Graphics/Mur.png");
  for(int i = 0; i < getDimY_terr(pTerrain); i++){
    for (int j = 0; j < getDimX_terr(pTerrain); j++) {
      if(getEnvCase(getGrilleByXY_terr(j, i, pTerrain)) == MUR){
	drawImage(murText,j*50,(getDimY_terr(pTerrain)*50 - i*50)-50);
      }
      else{
	drawImage(fond,j*50,(getDimY_terr(pTerrain)*50 - i*50)-50);
      }
    }
  }
}




