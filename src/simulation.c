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

void citoyensInit_sim(int nbCitoyens, Simulation * pSim){
    Perso ** tabCitoyens = getCitoyens_sim(pSim); 
    for (int i = 0; i< nbCitoyens; i++) {
	tabCitoyens[i] = creePersoTerrainRand(getTerrain_sim(pSim), CITOYEN);
    }
}

void policiersInit_sim(int nbPoliciers, Simulation * pSim){
    Perso ** tabPoliciers = getPoliciers_sim(pSim); 
    for (int i = 0; i< nbPoliciers; i++) {
	tabPoliciers[i] = creePersoTerrainRand(getTerrain_sim(pSim), POLICIER);
    }
}

void terrainInit_sim(char * nomFic, Simulation * pSim){
    Terrain * pTerrain = (Terrain *)malloc(sizeof(Terrain));
    pTerrain = terrainLireFichier_terr(nomFic);

    setTerrain_sim(pTerrain, pSim);
}

void initSimulation_sim(Simulation * pSim, int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic){
    terrainInit_sim(nomFic, pSim);
    
    zombiesInit_sim(nbZombies, pSim);

    citoyensInit_sim(nbCitoyens, pSim);

    policiersInit_sim(nbPoliciers, pSim);
}

Simulation * creerSimulation_sim(int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic){
    Simulation * pSim = (Simulation *)malloc(sizeof(Simulation));

    initSimulation_sim(pSim, nbZombies, nbCitoyens, nbPoliciers, nomFic);

    return pSim;
}

void testFonctions_sim(){
    char * nomFic = "FichierTestLecture";

    Simulation * pSim = creerSimulation_sim(2, 2, 1, nomFic);

    afficherGrilleConsole(getTerrain_sim(pSim));
}
