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

void deplacementAleatoire_perso(Perso * pPerso, Terrain * pTerrain){
    srand(time(NULL));

    char direction = rand()%4;

    assert(direction < 4 && direction >= 0);

    if(direction == 0){
	deplacementBas_perso(pPerso, pTerrain);
    }

    else if(direction == 1){
	deplacementHaut_perso(pPerso, pTerrain);
    }

    else if(direction == 2){
	deplacementDroite_perso(pPerso, pTerrain);
    }

    else{
	deplacementGauche_perso(pPerso, pTerrain);
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////
//PARTIE ZOMBIE//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/*ERREURS A CORRIGER : NE VERIFIE PAS LES BORDURES DE LA GRILLE
UTILISER VERIF DU DESSUS
*/

Perso * contaminationHumain(Perso * pHumain){ //retourne l'humain en mode zombie
    pHumain -> type = ZOMBIE;

    return pHumain;
}

char humainEnHaut(Terrain * pTerrain, Coordonnees * coordZombie){
    if(pTerrain -> grille[(coordZombie -> xCoord)][(coordZombie -> yCoord) + 1].persoCase -> type == CITOYEN \
       || \
       pTerrain -> grille[coordZombie -> xCoord][(coordZombie -> yCoord) + 1].persoCase -> type == POLICIER){
	return 1;
    }
    else{
	return 0;
    }
}

char humainEnBas(Terrain * pTerrain, Coordonnees * coordZombie){
    if(pTerrain -> grille[coordZombie -> xCoord][(coordZombie -> yCoord) - 1].persoCase -> type == CITOYEN \
       || \
       pTerrain -> grille[coordZombie -> xCoord][(coordZombie -> yCoord) - 1].persoCase -> type == POLICIER){
	return 1;
    }
    else{
	return 0;
    }
}

char humainAGauche(Terrain * pTerrain, Coordonnees * coordZombie){
    if(pTerrain -> grille[(coordZombie -> xCoord) - 1][coordZombie -> yCoord].persoCase -> type == CITOYEN \
       || pTerrain -> grille[(coordZombie -> xCoord) - 1][coordZombie -> yCoord].persoCase -> type == POLICIER){
	return 1;
    }
    else{
	return 0;
    }
}

char humainADroite(Terrain * pTerrain, Coordonnees * coordZombie){
    if(pTerrain -> grille[(coordZombie -> xCoord) + 1][coordZombie -> yCoord].persoCase -> type == CITOYEN \
       || pTerrain -> grille[(coordZombie -> xCoord) + 1][coordZombie -> yCoord].persoCase -> type == POLICIER){
	return 1;
    }
    else{
	return 0;
    }
}

Perso * zombieComtamineHumain(Perso * pZombie, Terrain * pTerrain){
    int xZombie, yZombie;
    
    if(humainEnHaut(pTerrain, pZombie -> coord)){
	xZombie = pZombie -> coord -> xCoord;
	yZombie = pZombie -> coord -> yCoord;
	return contaminationHumain(pTerrain -> grille [xZombie][yZombie + 1].persoCase);
    }

    else if(humainEnBas(pTerrain, pZombie -> coord)){
	xZombie = pZombie -> coord -> xCoord;
	yZombie = pZombie -> coord -> yCoord;
	return contaminationHumain(pTerrain -> grille [xZombie][yZombie - 1].persoCase);
    }

    else if(humainAGauche(pTerrain, pZombie -> coord)){
	xZombie = pZombie -> coord -> xCoord;
	yZombie = pZombie -> coord -> yCoord;
	return contaminationHumain(pTerrain -> grille [xZombie - 1][yZombie].persoCase);
    }

    else if(humainAGauche(pTerrain, pZombie -> coord)){
	xZombie = pZombie -> coord -> xCoord;
	yZombie = pZombie -> coord -> yCoord;
	return contaminationHumain(pTerrain -> grille [xZombie + 1][yZombie].persoCase);
    }

    else{
	return NULL;
    }
}

