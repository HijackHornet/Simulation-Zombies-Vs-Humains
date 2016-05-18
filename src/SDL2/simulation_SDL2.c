#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "simulation_SDL2.h"



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
            x=(x/(50*FULLSCREEN_RENDERERSCALE));
            y=(y/(50*FULLSCREEN_RENDERERSCALE));
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



////////////////////////////////////////////////////////////////////
//EXECUTIONS////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void lancerSimulationSDL2 (Simulation * pSim){

        unsigned int frameLimit = SDL_GetTicks() + 16;
    int loopCondition;
    init("Simulation Humains VS Zombie - Par Leo et Tristan");
    atexit(cleanup);

    loopCondition = 1;

    while (loopCondition == 1)
    {

        EventClavier();
        propagerChampsPersos(pSim);
        contaminations(pSim);
        deplacementIntelZombies_sim(pSim);
        tirs(pSim);
        deplacementIntelCitoyens_sim(pSim);
        deplacementIntelPoliciers_sim(pSim);
        affichageFenetre(pSim);

        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }

}
void lancerSimulationSDL2Editeur (){

        unsigned int frameLimit = SDL_GetTicks() + 16;
    int loopCondition;
    initEditeur("Editeur de Maps");
    atexit(cleanup);

    loopCondition = 1;

    Terrain * TerrainEdit;
    TerrainEdit = terrainCreer_terr(15,15,"LeNom");

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

