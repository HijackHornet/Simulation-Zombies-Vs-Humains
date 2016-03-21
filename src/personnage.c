#include "personnage.h"


char verifDeplacementBas_perso(Perso * pPerso, Terrain * pTerrain){
    if((pPerso -> coord -> yCoord) > 0){
	return 1;
    }

    else{
	return 0;
    }
}

char verifDeplacementHaut_perso(Perso * pPerso, Terrain * pTerrain){
    if((pPerso -> coord -> yCoord) < (pTerrain -> dimY)){
	return 1;
    }
    else{
	return 0;
    }
}

char verifDeplacementGauche_perso(Perso *  pPerso, Terrain * pTerrain){
    if((pPerso -> coord -> xCoord) > 0){
	return 1;
    }

    else{
	return 0;
    }
}

char verifDeplacementDroite_perso(Perso * pPerso, Terrain * pTerrain){
    if((pPerso -> coord -> xCoord) < (pTerrain -> dimX)){
	return 1;
    }
    else{
	return 0;
    }
}

void deplacementHaut_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementHaut_perso(pPerso, pTerrain));
    
    int xPerso = pPerso -> coord -> xCoord;
    int yPerso = pPerso -> coord -> yCoord;
    
    pTerrain -> grille[xPerso][yPerso].persoCase = NULL;
	
    (pPerso -> coord -> yCoord)++;
    yPerso++;

    pTerrain -> grille[xPerso][yPerso].persoCase = pPerso;
}

void deplacementBas_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementBas_perso(pPerso, pTerrain));
    
    int xPerso = pPerso -> coord -> xCoord;
    int yPerso = pPerso -> coord -> yCoord;
    
    pTerrain -> grille[xPerso][yPerso].persoCase = NULL;
	
    (pPerso -> coord -> yCoord)--;
    yPerso--;

    pTerrain -> grille[xPerso][yPerso].persoCase = pPerso;
}

void deplacementGauche_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementGauche_perso(pPerso, pTerrain));
    
    int xPerso = pPerso -> coord -> xCoord;
    int yPerso = pPerso -> coord -> yCoord;
    
    pTerrain -> grille[xPerso][yPerso].persoCase = NULL;
	
    (pPerso -> coord -> xCoord)--;
    xPerso--;

    pTerrain -> grille[xPerso][yPerso].persoCase = pPerso;
}

void deplacementDroite_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementDroite_perso(pPerso, pTerrain));
    
    int xPerso = pPerso -> coord -> xCoord;
    int yPerso = pPerso -> coord -> yCoord;
    
    pTerrain -> grille[xPerso][yPerso].persoCase = NULL;
	
    (pPerso -> coord -> xCoord)++;
    xPerso++;

    pTerrain -> grille[xPerso][yPerso].persoCase = pPerso;
}
