#include "simulation.h"

static Terrain * getTerrain_sim(Simulation * pSim){
    return sim -> pTerrain;
}

static Terrain * getZombies_sim(Simulation * pSim){
    return sim -> zombies;
}

static Terrain * getCitoyens_sim(Simulation * pSim){
    return sim -> citoyens;
}

static Terrain * getPoliciers_sim(Simulation * pSim){
    return sim -> policiers;
}

static void zombiesInit_sim(int nbZombies, Simulation * pSim){
    
}

void initSimulation_terr(Simulation * pSim, int nbHumains, int nbZombies, int nbPoliciers){
    zombiesInit_sim(nbZombies, pSim);
    
}

