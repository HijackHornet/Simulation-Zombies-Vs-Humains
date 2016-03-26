#include "simulation.h"

Terrain * getTerrain_sim(Simulation * pSim){
    return pSim -> pTerrain;
}

void setTerrain_sim(Terrain * pTerrain, Simulation * pSim){
    pSim -> pTerrain = pTerrain;
}

Perso ** getZombies_sim(Simulation * pSim){
    return pSim -> zombies;
}

Perso ** getCitoyens_sim(Simulation * pSim){
    return pSim -> citoyens;
}

Perso ** getPoliciers_sim(Simulation * pSim){
    return pSim -> policiers;
}

void zombiesInit_sim(int nbZombies, Simulation * pSim){
    Perso ** tabZombies = getZombies_sim(pSim); 
    for (int i = 0; i< nbZombies; i++) {
	tabZombies[i] = creePersoTerrainRand(getTerrain_sim(pSim), ZOMBIE);
    }
}

void terrainInit_sim(char * nomFic, Simulation * pSim){
    Terrain * pTerrain = (Terrain *)malloc(sizeof(Terrain));
    pTerrain = terrainLireFichier_terr(nomFic);

    setTerrain_sim(pTerrain, pSim);
}

void initSimulation_sim(Simulation * pSim, int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic){
    terrainInit_sim(nomFic, pSim);

    //printf("%d", getDimX_terr(getTerrain_sim(pSim)));
    
    zombiesInit_sim(nbZombies, pSim);
}

Simulation * creerSimulation_sim(int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic){
    Simulation * pSim = (Simulation *)malloc(sizeof(Simulation));

    initSimulation_sim(pSim, nbZombies, 0, 0, nomFic);

    return pSim;
}

void testFonctions_sim(){
    int nbZombies = 5;

    char * nomFic = "FichierTestLecture";

    Simulation * pSim = creerSimulation_sim(nbZombies, 0, 0, nomFic);

    afficherGrilleConsole(getTerrain_sim(pSim));
}
