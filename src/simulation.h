#include "terrain.h"
#include "personnage.h"

typedef struct MSimulation{
    Terrain * pTerrain;
    int nbZombies;
    int nbCitoyens;
    int nbPoliciers;
    Perso *  zombies[100];
    Perso * citoyens[100];
    Perso * policiers[100];
} Simulation;

Terrain * getTerrain_sim(Simulation * pSim);

Perso ** getZombies_sim(Simulation * pSim);

Perso ** getCitoyens_sim(Simulation * pSim);

Perso ** getPoliciers_sim(Simulation * pSim);

void zombiesInit_sim(int nbZombies, Simulation * pSim);

void citoyensInit_sim(int nbCitoyens, Simulation * pSim);

void policiersInit_sim(int nbPoliciers, Simulation * pSim);

void terrainInit_sim(char * nomFic, Simulation * pSim);

void initSimulation_sim(Simulation * pSim, int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic);

Simulation * creerSimulation_sim(int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic);

void testFonctions_sim();
