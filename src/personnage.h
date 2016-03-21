#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "coordonnees.h"
#include "terrain.h"
#include "assert.h"
#include "time.h"

enum typePerso {POLICIER, ZOMBIE, CITOYEN};

typedef struct MPerso {
    Coordonnees * coord;
    enum typePerso type;
} Perso;

char verifDeplacementHaut_perso(Perso * pPerso, Terrain * pTerrain);

char verifDeplacementBas_perso(Perso * pPerso, Terrain * pTerrain);

char verifDeplacementGauche_perso(Perso * pPerso, Terrain * pTerrain);

char verifDeplacementDroite_perso(Perso * pPerso, Terrain * pTerrain);

void deplacementHaut_perso(Perso * pPerso, Terrain * pTerrain);

void deplacementBas_perso(Perso * pPerso, Terrain * pTerrain);

void deplacementAleatoire_perso(Perso * pPerso, Terrain * pTerrain);

Perso * contaminationHumain(Perso * pHumain);

char humainEnHaut(Terrain * pTerrain, Coordonnees * coordZombie);

char humainEnBas(Terrain * pTerrain, Coordonnees * coordZombie);

char humainAGauche(Terrain * pTerrain, Coordonnees * coordZombie);

char humainADroite(Terrain * pTerrain, Coordonnees * coordZombie);

Perso * zombieComtamineHumain(Perso * pZombie, Terrain * pTerrain);

#endif
