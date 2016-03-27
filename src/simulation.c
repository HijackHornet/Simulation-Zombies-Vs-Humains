#include "simulation.h"

////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

Terrain * getTerrain_sim(Simulation * pSim){
    return pSim -> pTerrain;
}

void setTerrain_sim(Terrain * pTerrain, Simulation * pSim){
    pSim -> pTerrain = pTerrain;
}

int getNbZombies_sim(Simulation * pSim){
    return pSim -> nbZombies;
}

void setNbZombies_sim(int nbZombies, Simulation * pSim){
    pSim -> nbZombies = nbZombies;
}

int getNbCitoyens_sim(Simulation * pSim){
    return pSim -> nbCitoyens;
}

void setNbCitoyens_sim(int nbCitoyens, Simulation * pSim){
    pSim -> nbCitoyens = nbCitoyens;
}

int getNbPoliciers_sim(Simulation * pSim){
    return pSim -> nbPoliciers;
}

void setNbPoliciers_sim(int nbPoliciers, Simulation * pSim){
    pSim -> nbPoliciers= nbPoliciers;
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

////////////////////////////////////////////////////////////////////
//CREATION-INITALISATION////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void zombiesInit_sim(int nbZombies, Simulation * pSim){
    Perso ** tabZombies = getZombies_sim(pSim); 
    for (int i = 0; i< nbZombies; i++) {
	tabZombies[i] = creePersoTerrainRand(getTerrain_sim(pSim), ZOMBIE);
    }

    setNbZombies_sim(nbZombies, pSim);
}

void citoyensInit_sim(int nbCitoyens, Simulation * pSim){
    Perso ** tabCitoyens = getCitoyens_sim(pSim); 
    for (int i = 0; i< nbCitoyens; i++) {
	tabCitoyens[i] = creePersoTerrainRand(getTerrain_sim(pSim), CITOYEN);
    }

    setNbCitoyens_sim(nbCitoyens, pSim);
}

void policiersInit_sim(int nbPoliciers, Simulation * pSim){
    Perso ** tabPoliciers = getPoliciers_sim(pSim); 
    for (int i = 0; i< nbPoliciers; i++) {
	tabPoliciers[i] = creePersoTerrainRand(getTerrain_sim(pSim), POLICIER);
    }

    setNbPoliciers_sim(nbPoliciers, pSim);
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

///////////////////////////////////////////////////////////////////////////////
//EXECUTION////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void deplacerZombies_sim(Simulation * pSim){
    int nbZombies = getNbZombies_sim(pSim);
    Perso ** tabZombies = getZombies_sim(pSim);
    for(int i = 0; i < nbZombies; i++){
	deplacementAleatoire_perso(tabZombies[i], getTerrain_sim(pSim));
    }
}

void deplacerCitoyens_sim(Simulation * pSim){
    int nbCitoyens = getNbCitoyens_sim(pSim);    
    Perso ** tabCitoyens = getCitoyens_sim(pSim);
    for(int i = 0; i < nbCitoyens; i++){
	deplacementAleatoire_perso(tabCitoyens[i], getTerrain_sim(pSim));
    }
}

void deplacerPoliciers_sim(Simulation * pSim){
    int nbPoliciers = getNbPoliciers_sim(pSim);
    Perso ** tabPoliciers = getPoliciers_sim(pSim);
    for(int i = 0; i < nbPoliciers; i++){
	deplacementAleatoire_perso(tabPoliciers[i], getTerrain_sim(pSim));
    }
}

void deplacerPerso_sim(Simulation * pSim){
    deplacerZombies_sim(pSim);
    deplacerPoliciers_sim(pSim);
    deplacerCitoyens_sim(pSim);
}


///////////////////////////////////////////////////////////////////////////////
//TEST/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void testFonctions_sim(){
    char * nomFic = "FichierTestLecture";

    Simulation * pSim = creerSimulation_sim(2, 2, 1, nomFic);

    afficherGrilleConsole(getTerrain_sim(pSim));

    deplacerPerso_sim(pSim);

    afficherGrilleConsole(getTerrain_sim(pSim));
}
