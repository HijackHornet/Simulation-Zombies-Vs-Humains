#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "coordonnees.h"
#include "terrain.h"
#include "assert.h"

enum typePerso {LIBRE, POLICIER, ZOMBIE, CITOYEN};

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



#endif
