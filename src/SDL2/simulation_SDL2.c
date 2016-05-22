#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "simulation_SDL2.h"
#include "../simulation.h"



////////////////////////////////////////////////////////////////////
//INPUTS  //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void EventClavier(){
    SDL_Event event;
    while ( SDL_PollEvent(&event) )
    {
        switch(event.type)
    {
        case SDL_WINDOWEVENT:
            if ( event.window.event == SDL_WINDOWEVENT_CLOSE )
            {
                exit(0);
            }
            break;
        case SDL_KEYDOWN:
            if ( event.key.keysym.sym == SDLK_ESCAPE )
            {
                exit(0);

            }
            break;
    }
    }

}
void EventClavierEditeur(Terrain * pTerrain){
    SDL_Event event;
    int screenheight, screenwidth;

    screenheight = getDimY_terr(pTerrain) * 50 *RENDERERSCALE;
    screenwidth = getDimX_terr(pTerrain) * 50 *RENDERERSCALE;
    while ( SDL_PollEvent(&event) )
    {
        switch(event.type)
    {
        case SDL_WINDOWEVENT:
            if ( event.window.event == SDL_WINDOWEVENT_CLOSE )
            {
                exit(0);
            }
            break;
        case SDL_KEYDOWN:
            if ( event.key.keysym.sym == SDLK_ESCAPE )
            {
                exit(0);

            }

            if (event.key.keysym.sym == SDLK_s) {

                exit(0);

            }
            break;
        case SDL_MOUSEBUTTONUP:
            {int x,y;
            caseDeplacement * caseDep;


            SDL_GetMouseState(&x,&y);
            x=(x/(50*RENDERERSCALE));
            y=(y/(50*RENDERERSCALE));
            caseDep = getGrilleByXY_terr(x,(getDimY_terr(pTerrain)-y-1),pTerrain);
            if(getEnvCase(getGrilleByXY_terr(x, (getDimY_terr(pTerrain)-y-1), pTerrain)) == MUR){
                setEnvCase(caseDep, VIDE);
                setGrilleByXY_terr (x,(getDimY_terr(pTerrain)-y-1),pTerrain,caseDep);
            }
            else{
                setEnvCase(caseDep, MUR);
                setGrilleByXY_terr (x,(getDimY_terr(pTerrain)-y-1),pTerrain,caseDep);
            }
            break;
            }
    }
    }

}

void lancerSimulationSDL2 (Simulation * pSim){

  unsigned int frameLimit = SDL_GetTicks() + 16;
  int go;
  // Initialisation de la SDL
  init("Simulation Humains VS Zombie",pSim);
  // Appelle la fonction cleanup à la fin du programme
  atexit(cleanup);

  go = 1;

  // Boucle infinie, principale, du jeu
  while (go == 1)
    {
      //On dessine tout
      EventClavier();
      propagerChampsPersos(pSim);
      contaminations(pSim);
      deplacementIntelZombies_sim(pSim);
      tirs(pSim);
      deplacementIntelCitoyens_sim(pSim);
      deplacementIntelPoliciers_sim(pSim);
      affichageFenetre(pSim);

      // Gestion des 60 fps (1000ms/60 = 16.6 -> 16)
      delay(frameLimit);
      frameLimit = SDL_GetTicks() + 16;
    }
}


void lancerSimulationSDL2Editeur (){

        unsigned int frameLimit = SDL_GetTicks() + 16;
    int loopCondition;
    atexit(cleanup);
    loopCondition = 1;

    Terrain * TerrainEdit;
    TerrainEdit = terrainCreer_terr(15,15,"LeNom");


    initEditeur("Editeur de Maps",TerrainEdit);
    while (loopCondition == 1)
    {


        EventClavierEditeur(TerrainEdit);
        affichageFenetreEditeur(TerrainEdit);


        SDL_RenderPresent(getrenderer());
        SDL_Delay(DELAYREFRESH);
        SDL_RenderClear(getrenderer());

        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }


}

