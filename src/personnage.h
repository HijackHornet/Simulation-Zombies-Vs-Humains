#include "coordonnees.h"
#include "terrain.h"

typedef struct MPolicier {
    Coordonnees * coord;
} Policier;

char verifDeplacementHaut_pol(Policier * pPolicier, Terrain * pTerrain);

char verifDeplacementBas_pol(Policier * pPolicier, Terrain * pTerrain);

char verifDeplacementGauche_pol(Policier * pPolicier, Terrain * pTerrain);

char verifDeplacementDroite_pol(Policier * pPolicier, Terrain * pTerrain);

void deplacementHaut(Policier * pPolicier, Terrain * pTerrain);
