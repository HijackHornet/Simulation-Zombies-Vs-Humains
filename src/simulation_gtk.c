#include "defs.h"
#include <stdlib.h>
#include <gtk/gtk.h>


void startSdlMain(){
    Simulation * pSim = creerSimulation_sim(50, 50, 50, "FichierTestLecture");
    lancerSimulationSDL2(pSim);
}
void startSdlEditeurMain(){
    lancerSimulationSDL2Editeur();
}
