#include "simulation_gtk.h"

void startSdlMain(){
    Simulation * pSim = creerSimulation_sim(20, 50, 50, "TerrainViergePourEditeur");
    lancerSimulationSDL2(pSim);
}
void startSdlEditeurMain(){
    lancerSimulationSDL2Editeur();
}
