#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>


#include "input.h"
#include "initialisationSDL.h"
#include "affichage_SDL.h"

int lancerSimulationSdl (int argc, char* argv[]){

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
        Input input;
        //Gestion des inputs clavier
        getInput(&input);

        //On dessine tout
        affichageFenetre();

        // Gestion des 60 fps (1000ms/60 = 16.6 -> 16
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;
    }

    // On quitte
    exit(0);

}
