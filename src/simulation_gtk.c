#include "simulation_gtk.h"

void startSdlMain(int nbZombies, int nbPoliciers, int nbCitoyens){
  srand(time(NULL));
  
  Simulation * pSim = creerSimulation_sim(nbZombies, nbPoliciers, nbCitoyens, "TerrainViergePourEditeur");
  lancerSimulationSDL2(pSim);
}
void startSdlEditeurMain(){
  lancerSimulationSDL2Editeur();
}

