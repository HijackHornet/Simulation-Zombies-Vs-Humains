#include "policier.h"


char verifDeplacementHaut_pol(Policier * pPolicier, Terrain * pTerrain){
    if((pPolicier -> coord -> yCoord) > 0){
	return 1;
    }

    else{
	return 0;
    }
}

char verifDeplacementBas_pol(Policier * pPolicier, Terrain * pTerrain){
    if((pPolicier -> coord -> yCoord) < (pTerrain -> dimY)){
	return 1;
    }
    else{
	return 0;
    }
}

char verifDeplacementGauche_pol(Policier *  pPolicier, Terrain * pTerrain){
    if((pPolicier -> coord -> xCoord) > 0){
	return 1;
    }

    else{
	return 0;
    }
}

char verifDeplacementDroite_pol(Policier * pPolicier, Terrain * pTerrain){
    if((pPolicier -> coord -> xCoord) < (pTerrain -> dimX)){
	return 1;
    }
    else{
	return 0;
    }
}

void deplacementHaut(Policier * pPolicier, Terrain * pTerrain){
    int xPolicier = pPolicier -> coord -> xCoord;
    int yPolicier = pPolicier -> coord -> yCoord;
    
    pTerrain -> grille[yPolicier][xPolicier].persoCase = LIBRE;
	
    (pPolicier -> coord -> xCoord)--;
    yPolicier--;

    pTerrain -> grille[yPolicier][xPolicier].persoCase = POLICIER;
}
