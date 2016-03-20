#include "personnage.h"


char verifDeplacementBas_perso(Policier * pPolicier, Terrain * pTerrain){
    if((pPolicier -> coord -> yCoord) > 0){
	return 1;
    }

    else{
	return 0;
    }
}

char verifDeplacementHaut_perso(Policier * pPolicier, Terrain * pTerrain){
    if((pPolicier -> coord -> yCoord) < (pTerrain -> dimY)){
	return 1;
    }
    else{
	return 0;
    }
}

char verifDeplacementGauche_perso(Policier *  pPolicier, Terrain * pTerrain){
    if((pPolicier -> coord -> xCoord) > 0){
	return 1;
    }

    else{
	return 0;
    }
}

char verifDeplacementDroite_perso(Policier * pPolicier, Terrain * pTerrain){
    if((pPolicier -> coord -> xCoord) < (pTerrain -> dimX)){
	return 1;
    }
    else{
	return 0;
    }
}

void deplacementHaut_perso(Policier * pPolicier, Terrain * pTerrain){
    int xPolicier = pPolicier -> coord -> xCoord;
    int yPolicier = pPolicier -> coord -> yCoord;
    
    pTerrain -> grille[xPolicier][yPolicier].persoCase = LIBRE;
	
    (pPolicier -> coord -> yCoord)++;
    yPolicier++;

    pTerrain -> grille[yPolicier][xPolicier].persoCase = POLICIER;
}
