gith#include "terrain.h"
#include "personnage.h"

typedef struct MSimulation{
    Terrain * pTerrain;
    Personnage zombies[100];
    Personnage citoyens[100];
    Personnage policiers[100];
} Simulation;

Terrain * getZombies_sim(Simulation * pSim);

Terrain * getCitoyens_sim(Simulation * pSim);

Terrain * getPoliciers_sim(Simulation * pSim);
