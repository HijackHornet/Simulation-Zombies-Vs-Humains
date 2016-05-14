#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "simulation_SDL2.h"

void lancerSimulationSDL2 (Simulation * pSim){

        unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;
    // Initialisation de la SDL
    init("Simulation Humains VS Zombie - Par Leo et Tristan");
    // Appelle la fonction cleanup à la fin du programme
    atexit(cleanup);

    go = 1;

    // Boucle infinie, principale, du jeu
    while (go == 1)
      {
        //On dessine tout
        contaminations(pSim);
        tirs(pSim);
        propagerChampsPersos(pSim);
        deplacerPerso_sim(pSim);
        affichageFenetre(pSim);

        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }

}
void lancerSimulationSDL2Editeur (){

    unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;
    // Initialisation de la SDL
    init("Editeur de Maps");
    // Appelle la fonction cleanup à la fin du programme
    atexit(cleanup);

    go = 1;

    // Boucle infinie, principale, du jeu
    while (go == 1)
    {
        //On dessine tout
        affichageFenetreEditeur();

        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }

}

