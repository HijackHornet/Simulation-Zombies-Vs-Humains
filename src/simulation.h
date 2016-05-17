#ifndef _SIMULATION
#define _SIMULATION

#include "terrain.h"
#include "personnage.h"

typedef struct MSimulation{
    Terrain * pTerrain;
    int nbZombies;
    int nbCitoyens;
    int nbPoliciers;
    Perso *  zombies[500];
    Perso * citoyens[500];
    Perso * policiers[500];
} Simulation;

////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

Terrain * getTerrain_sim(Simulation * pSim);

Perso ** getZombies_sim(Simulation * pSim);

Perso ** getCitoyens_sim(Simulation * pSim);

Perso ** getPoliciers_sim(Simulation * pSim);

int getNbZombies_sim(Simulation * pSim);

int getNbCitoyens_sim(Simulation * pSim);

int getNbPoliciers_sim(Simulation * pSim);

////////////////////////////////////////////////////////////////////
//CREATION-INITALISATION////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void zombiesInit_sim(int nbZombies, Simulation * pSim);

void citoyensInit_sim(int nbCitoyens, Simulation * pSim);

void policiersInit_sim(int nbPoliciers, Simulation * pSim);

void terrainInit_sim(char * nomFic, Simulation * pSim);

void initSimulation_sim(Simulation * pSim, int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic);

Simulation * creerSimulation_sim(int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic);

///////////////////////////////////////////////////////////////////////////////
//EXECUTION////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void deplacerPerso_sim(Simulation * pSim);

void deplacerPoliciers_sim(Simulation * pSim);

void deplacerCitoyens_sim(Simulation * pSim);

void deplacerZombies_sim(Simulation * pSim);

void deplacementIntelZombies_sim(Simulation * pSim);

void deplacementIntelCitoyens_sim(Simulation * pSim);

void deplacementIntelPoliciers_sim(Simulation * pSim);

void deplacementIntelPersos(Simulation * pSim);

///////////////////////////////////////////////////////////////////////////////
//INTERACTIONS/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void contaminations(Simulation * pSim);

void tirs(Simulation * pSim);

////////////////////////////////////////////////////////////////////////////
//CHAMPS////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

void propagerChampsPersos(Simulation * pSim);

void deplacementIntelZombie(Perso * pPerso, Simulation * pSim);

void deplacementIntelCitoyen(Perso * pPerso, Simulation * pSim);

void deplacementIntelPolicier(Perso * pPerso, Simulation * pSim);

///////////////////////////////////////////////////////////////////////////////
//TEST/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

void testFonctions_sim();

////////////////////////////////////////////////////////////////////////////
//AUTRES////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
int compareTab2D(const void * a, const void * b);

#endif
