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
    pSim -> nbPoliciers = nbPoliciers;
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
    for (int i = 0; i < nbZombies; i++) {
	tabZombies[i] = creePersoTerrainRand(getTerrain_sim(pSim), ZOMBIE, i);
    }

    setNbZombies_sim(nbZombies, pSim);
}

void citoyensInit_sim(int nbCitoyens, Simulation * pSim){
    Perso ** tabCitoyens = getCitoyens_sim(pSim); 
    for (int i = 0; i < nbCitoyens; i++) {
	tabCitoyens[i] = creePersoTerrainRand(getTerrain_sim(pSim), CITOYEN, i);
    }

    setNbCitoyens_sim(nbCitoyens, pSim);
}

void policiersInit_sim(int nbPoliciers, Simulation * pSim){
    Perso ** tabPoliciers = getPoliciers_sim(pSim); 
    for (int i = 0; i < nbPoliciers; i++) {
	tabPoliciers[i] = creePersoTerrainRand(getTerrain_sim(pSim), POLICIER, i);
    }

    setNbPoliciers_sim(nbPoliciers, pSim);
}

void terrainInit_sim(char * nomFic, Simulation * pSim){
    pSim -> pTerrain = (Terrain *)malloc(sizeof(Terrain));
    
    pSim -> pTerrain = terrainLireFichier_terr(nomFic);
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

void testamentSim(Simulation * pSim){
    testamentTerrain_terr(getTerrain_sim(pSim));

    int nbZombies = getNbZombies_sim(pSim);
    int nbCitoyens = getNbCitoyens_sim(pSim);
    int nbPoliciers = getNbCitoyens_sim(pSim);

    Perso ** tabZombies = getZombies_sim(pSim);
    Perso ** tabCitoyens = getCitoyens_sim(pSim);
    Perso ** tabPoliciers = getPoliciers_sim(pSim);
	
    for (int i = 0; i < nbZombies; i++) {
	testamentPerso(tabZombies[i]);
    }

    for (int i = 0; i < nbCitoyens; i++) {
	testamentPerso(tabCitoyens[i]);
    }

    for (int i = 0; i < nbPoliciers; i++) {
	testamentPerso(tabPoliciers[i]);
    }

    free(pSim);

}

void ajouterZombie(Perso * pZombie, Simulation * pSim){
    Perso ** tabZombies = getZombies_sim(pSim);
    int nbZombies = getNbZombies_sim(pSim);

    nbZombies++;
    setNbZombies_sim(nbZombies, pSim);

    setIdPerso(nbZombies - 1, pZombie);
    tabZombies[nbZombies - 1] = pZombie;
}

void supprimerZombie(Perso * pZombie, Simulation * pSim){
    Perso ** tabZombies = getZombies_sim(pSim);
    int nbZombies = getNbZombies_sim(pSim);

    int idZombie = getIdPerso(pZombie);

    for(int i = idZombie; i < nbZombies - 1; i++){
	tabZombies[i] = tabZombies[i + 1];
	(tabZombies[i] -> id)--;
    }

    tabZombies[nbZombies - 1] = NULL;
    nbZombies--;

    setNbZombies_sim(nbZombies, pSim);
}

void ajouterCitoyen(Perso * pCitoyen, Simulation * pSim){
    Perso ** tabCitoyens = getCitoyens_sim(pSim);
    int nbCitoyens = getNbCitoyens_sim(pSim);

    nbCitoyens++;
    setNbCitoyens_sim(nbCitoyens,pSim);

    setIdPerso(nbCitoyens - 1, pCitoyen);
    tabCitoyens[nbCitoyens - 1] = pCitoyen;
}

void supprimerCitoyen(Perso * pCitoyen, Simulation * pSim){
    Perso ** tabCitoyens = getCitoyens_sim(pSim);
    int nbCitoyens = getNbCitoyens_sim(pSim);

    int idCitoyen = getIdPerso(pCitoyen);

    for(int i = idCitoyen; i < nbCitoyens - 1; i++){
	tabCitoyens[i] = tabCitoyens[i + 1];	
	(tabCitoyens[i] -> id)--;
    }

    tabCitoyens[nbCitoyens - 1] = NULL;
    nbCitoyens--;
    
    setNbCitoyens_sim(nbCitoyens, pSim);
}

void ajouterPolicier(Perso * pPolicier, Simulation * pSim){
    Perso ** tabPoliciers = getPoliciers_sim(pSim);
    int nbPoliciers = getNbPoliciers_sim(pSim);

    nbPoliciers++;
    (pSim -> nbPoliciers)++;

    setIdPerso(nbPoliciers - 1, pPolicier);
    tabPoliciers[nbPoliciers - 1] = pPolicier;
}


void supprimerPolicier(Perso * pPolicier, Simulation * pSim){
    Perso ** tabPoliciers = getPoliciers_sim(pSim);
    int nbPoliciers = getNbPoliciers_sim(pSim);

    int idPolicier = getIdPerso(pPolicier);

    for(int i = idPolicier; i < nbPoliciers - 1; i++){
	tabPoliciers[i] = tabPoliciers[i + 1];	
	(tabPoliciers[i] -> id)--;
    }

    tabPoliciers[nbPoliciers - 1] = NULL;

    nbPoliciers--;
    
    setNbPoliciers_sim(nbPoliciers, pSim);
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
//INTERACTIONS/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void contaminations(Simulation * pSim){
    int nbZombies = getNbZombies_sim(pSim);
    Perso ** tabZombies = getZombies_sim(pSim);
    Perso * persoContamine = NULL;
    for (int i = 0; i < nbZombies; i++) {
	persoContamine = zombieContamineHumain(tabZombies[i], getTerrain_sim(pSim));
	if(persoContamine != NULL){
	    if(getTypePerso(persoContamine) == CITOYEN){
		supprimerCitoyen(persoContamine, pSim);
		setTypePerso_perso(ZOMBIE, persoContamine);
		ajouterZombie(persoContamine, pSim);
	    }

	    else if(getTypePerso(persoContamine) == POLICIER){
		supprimerPolicier(persoContamine, pSim);
		setTypePerso_perso(ZOMBIE, persoContamine);
		ajouterZombie(persoContamine, pSim);
	    }
	}
    }
}

void tirs(Simulation * pSim){
    int nbPoliciers = getNbPoliciers_sim(pSim);
    Perso ** tabPoliciers = getPoliciers_sim(pSim);
    Perso * zombieAPortee = NULL;

    for (int i = 0; i < nbPoliciers; i++) {
	zombieAPortee = policierTueZombie(tabPoliciers[i], getTerrain_sim(pSim));
	if(zombieAPortee != NULL){
	    supprimerZombie(zombieAPortee, pSim);
	    testamentPerso(zombieAPortee);
	}
    }
}

///////////////////////////////////////////////////////////////////////////////
//TEST/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void testFonctions_sim(){
    srand(time(NULL));
    char * nomFic = "FichierTestLecture";

    Simulation * pSim = creerSimulation_sim(100, 30, 30, nomFic);

    afficherGrilleConsole(getTerrain_sim(pSim));

    contaminations(pSim);
    deplacerPerso_sim(pSim);
    contaminations(pSim);
    deplacerPerso_sim(pSim);
    contaminations(pSim);

    afficherGrilleConsole(getTerrain_sim(pSim));

    printf("%d %d %d", getNbZombies_sim(pSim), getNbCitoyens_sim(pSim), getNbPoliciers_sim(pSim));

    testamentSim(pSim);
}
