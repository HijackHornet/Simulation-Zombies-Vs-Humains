/**
   @file terrain.c
   @brief  Implémente les fonctions de manipulation du Terrain
*/

#include "terrain.h"


//////////////////////////////////////////////////////////////////////////////
//ACCESSEURS//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void setDim_terr (int x, int y, Terrain * pTerrain){
    pTerrain->dimX = x;
    pTerrain->dimY = y;
}

void setNomTerrain_terr(char * nom, Terrain * pTerrain){
    assert(strlen(nom)<MAX_CHAR_NOM_TERRAIN);
    strcpy(pTerrain->nomTerrain, nom);
}

void setGrilleByXY_terr (int x, int y, Terrain * pTerrain, caseDeplacement caseDep){
    pTerrain->grille[x][y] = caseDep;
}

int getDimX_terr(Terrain * pTerrain){
    return pTerrain->dimX;
}

int getDimY_terr(Terrain * pTerrain){
    return pTerrain->dimY;
}

char * getNomTerrain_terr(Terrain * pTerrain){
    return pTerrain->nomTerrain;
}

caseDeplacement * getGrilleByXY_terr (int x, int y,Terrain * pTerrain){
    return &(pTerrain->grille[x][y]);
}

caseDeplacement * getGrilleByCoord_terr(Coordonnees * coord, Terrain * pTerrain){
    return getGrilleByXY_terr(getXCoord_Coord(coord), getYCoord_Coord(coord), pTerrain);
}

Coordonnees getCoordCaseDroiteByXY_terr(int x, int y){
    return (Coordonnees){x + 1, y};
}

Coordonnees getCoordCaseGaucheByXY_terr(int x, int y){
    return (Coordonnees){x - 1, y};
}

Coordonnees getCoordCaseHautByXY_terr(int x, int y){
    return (Coordonnees){x, y + 1};
}

Coordonnees getCoordCaseBasByXY_terr(int x, int y){
    return (Coordonnees){x, y - 1};
}

Coordonnees getCoordCaseBasByCoord_terr(Coordonnees * coord){
    return getCoordCaseBasByXY_terr(getXCoord_Coord(coord), getYCoord_Coord(coord));
}

Coordonnees getCoordCaseHautByCoord_terr(Coordonnees * coord){
    return getCoordCaseHautByXY_terr(getXCoord_Coord(coord), getYCoord_Coord(coord));
}

Coordonnees getCoordCaseDroiteByCoord_terr(Coordonnees * coord){
    return getCoordCaseDroiteByXY_terr(getXCoord_Coord(coord), getYCoord_Coord(coord));
}

Coordonnees getCoordCaseGaucheByCoord_terr(Coordonnees * coord){
    return getCoordCaseGaucheByXY_terr(getXCoord_Coord(coord), getYCoord_Coord(coord));
}


//////////////////////////////////////////////////////////////////////////////
//CREATION////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void terrainInitGrille_terr (Terrain * pTerrain){
    int i,j;
    caseDeplacement X;
    setPersoCase(&X, NULL);
    setEnvCase(&X, VIDE);
    for(i=0; i < getDimX_terr(pTerrain); i++){
	for(j=0; j < getDimY_terr(pTerrain); j++){
	    setGrilleByXY_terr(i, j, pTerrain, X);
	}
    }

}

Terrain * terrainCreer_terr (int dimX, int dimY, char nomTerrain[MAX_CHAR_NOM_TERRAIN]){
    Terrain * pTerrain = NULL;
    pTerrain =(Terrain*)malloc(sizeof(Terrain));
    setDim_terr(dimX,dimY, pTerrain);
    setNomTerrain_terr(nomTerrain, pTerrain);
    terrainInitGrille_terr(pTerrain);
    return pTerrain;

}

/////////////////////////////////////////////////////////////////////////////
//TESTS SPECIFIQUES//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

char estDansTerrain_terr(Terrain * pTerrain, Coordonnees * pCoord){
    int xCoord = getXCoord_Coord(pCoord);
    int yCoord = getYCoord_Coord(pCoord);

    return (xCoord >= 0 && xCoord < getDimX_terr(pTerrain) && \
	    yCoord >= 0 && yCoord < getDimY_terr(pTerrain));
}

/////////////////////////////////////////////////////////////////////////////
//DEPLACEMENT PERSONNAGES////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
char verifDeplacementBas_perso(Perso * pPerso, Terrain * pTerrain){
    Coordonnees * pCoordPerso = getCoordonneesPerso_perso(pPerso);

    setYCoord_Coord(getYCoord_Coord(pCoordPerso) - 1, pCoordPerso);

    return estDansTerrain_terr(pTerrain, pCoordPerso);
}

char verifDeplacementHaut_perso(Perso * pPerso, Terrain * pTerrain){
    Coordonnees * pCoordPerso = getCoordonneesPerso_perso(pPerso);

    setYCoord_Coord(getYCoord_Coord(pCoordPerso) + 1, pCoordPerso);

    return estDansTerrain_terr(pTerrain, pCoordPerso);
}

char verifDeplacementGauche_perso(Perso *  pPerso, Terrain * pTerrain){
    Coordonnees * pCoordPerso = getCoordonneesPerso_perso(pPerso);

    setXCoord_Coord(getXCoord_Coord(pCoordPerso) - 1, pCoordPerso);

    return estDansTerrain_terr(pTerrain, pCoordPerso);
}

char verifDeplacementDroite_perso(Perso * pPerso, Terrain * pTerrain){
    Coordonnees * pCoordPerso = getCoordonneesPerso_perso(pPerso);

    setXCoord_Coord(getXCoord_Coord(pCoordPerso) + 1, pCoordPerso);

    return estDansTerrain_terr(pTerrain, pCoordPerso);
}

char deplacementHaut_perso(Perso * pPerso, Terrain * pTerrain){
    if(verifDeplacementHaut_perso(pPerso, pTerrain)){

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);

    setPersoCase(getGrilleByXY_terr(xPerso, yPerso, pTerrain), NULL);

    yPerso++;
    setYPerso_perso(pPerso, yPerso);

    setPersoCase(getGrilleByXY_terr(xPerso, yPerso, pTerrain), pPerso);

    return 1;
    }

    else{
	return 0;
    }
}

char deplacementBas_perso(Perso * pPerso, Terrain * pTerrain){
    if(verifDeplacementBas_perso(pPerso, pTerrain)){

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);

    setPersoCase(getGrilleByXY_terr(xPerso, yPerso, pTerrain), NULL);

    yPerso--;
    setYPerso_perso(pPerso, yPerso);

    setPersoCase(getGrilleByXY_terr(xPerso, yPerso, pTerrain), pPerso);

    return 1;
    }

    else{
	return 0;
    }
}

char deplacementGauche_perso(Perso * pPerso, Terrain * pTerrain){
    if(verifDeplacementGauche_perso(pPerso, pTerrain)){

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);

    setPersoCase(getGrilleByXY_terr(xPerso, yPerso, pTerrain), NULL);

    xPerso--;
    setXPerso_perso(pPerso, xPerso);

    setPersoCase(getGrilleByXY_terr(xPerso, yPerso, pTerrain), pPerso);
    
    return 1;
    }

    else{
	return 0;
    }
}

char deplacementDroite_perso(Perso * pPerso, Terrain * pTerrain){
    if(verifDeplacementDroite_perso(pPerso, pTerrain)){

	int xPerso = getXPerso_perso(pPerso);
	int yPerso = getYPerso_perso(pPerso);

	setPersoCase(getGrilleByXY_terr(xPerso, yPerso, pTerrain), NULL);

	xPerso++;
	setXPerso_perso(pPerso, xPerso);

	setPersoCase(getGrilleByXY_terr(xPerso, yPerso, pTerrain), pPerso);
	return 1;
    }

    else{
	return 0;
    }
}

void deplacementAleatoire_perso(Perso * pPerso, Terrain * pTerrain){
    srand(time(NULL));

    char deplacementEffectue;

    while(deplacementEffectue != 1){
    
	char direction = rand()%4;

	assert(direction < 4 && direction >= 0);
    
	if(direction == 0){
	    deplacementEffectue = deplacementBas_perso(pPerso, pTerrain);
	}

	else if(direction == 1){
	    deplacementEffectue = deplacementHaut_perso(pPerso, pTerrain);
	}

	else if(direction == 2){
	    deplacementEffectue = deplacementDroite_perso(pPerso, pTerrain);
	}

	else{
	    deplacementEffectue = deplacementGauche_perso(pPerso, pTerrain);
	}
    }
}

/////////////////////////////////////////////////////////////////////////////
//SPECIFIQUE ZOMBIE//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
char humainEnHaut(Terrain * pTerrain, Coordonnees * coordZombie){
    Coordonnees coordCaseHaut = getCoordCaseHautByCoord_terr(coordZombie);

    if(estDansTerrain_terr(pTerrain, &coordCaseHaut)){
	caseDeplacement * caseHaut = getGrilleByCoord_terr(&coordCaseHaut, pTerrain);
	if(getTypePerso(getPersoCase(caseHaut)) == CITOYEN || getTypePerso(getPersoCase(caseHaut)) == POLICIER){
	    return 1;
	}
	else{
	    return 0; 
	}
    }
    else{
	return 0;
    }
}

char humainEnBas(Terrain * pTerrain, Coordonnees * coordZombie){
    Coordonnees coordCaseBas = getCoordCaseBasByCoord_terr(coordZombie);

    if(estDansTerrain_terr(pTerrain, &coordCaseBas)){
	caseDeplacement * caseBas = getGrilleByCoord_terr(&coordCaseBas, pTerrain);
	if(getTypePerso(getPersoCase(caseBas)) == CITOYEN || getTypePerso(getPersoCase(caseBas)) == POLICIER){
	    return 1;
	}
	else{
	    return 0; 
	}
    }
    else{
	return 0;
    }
}

char humainAGauche(Terrain * pTerrain, Coordonnees * coordZombie){
    Coordonnees coordCaseGauche = getCoordCaseGaucheByCoord_terr(coordZombie);

    if(estDansTerrain_terr(pTerrain, &coordCaseGauche)){
	caseDeplacement * caseGauche = getGrilleByCoord_terr(&coordCaseGauche, pTerrain);
	if(getTypePerso(getPersoCase(caseGauche)) == CITOYEN || getTypePerso(getPersoCase(caseGauche)) == POLICIER){
	    return 1;
	}
	else{
	    return 0; 
	}
    }
    else{
	return 0;
    }
}

char humainADroite(Terrain * pTerrain, Coordonnees * coordZombie){
    Coordonnees coordCaseDroite = getCoordCaseDroiteByCoord_terr(coordZombie);

    if(estDansTerrain_terr(pTerrain, &coordCaseDroite)){
	caseDeplacement * caseDroite = getGrilleByCoord_terr(&coordCaseDroite, pTerrain);
	if(getTypePerso(getPersoCase(caseDroite)) == CITOYEN || getTypePerso(getPersoCase(caseDroite)) == POLICIER){
	    return 1;
	}
	else{
	    return 0; 
	}
    }
    else{
	return 0;
    }
}


/////////////////////////////////////////////////////////////////////////////
//ENTREES-SORTIES////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void afficherGrilleConsole(Terrain * pTerrain){
    for(int i = getDimY_terr(pTerrain) - 1; i >= 0; i--){
	for (int j = 0; j < getDimX_terr(pTerrain); j++) {
	    if(getEnvCase(getGrilleByXY_terr(j, i, pTerrain)) == VIDE){
		printf(" ");
	    }
	    else{
		printf("X");
	    }
	}
	printf("\n");
    }
}


void terrainCreerFichier_terr (Terrain * pTerrain){
    FILE * pFichier;

    char cheminFichier[MAX_CHAR_NOM_TERRAIN + 16] = "../data/"; //16 correspond à la taille de la chaine d'accees
    
    strcat(cheminFichier, getNomTerrain_terr(pTerrain));
    strcat(cheminFichier, ".terrain");
    
    pFichier = fopen(cheminFichier,"w");

    int dimX = getDimX_terr(pTerrain);
    int dimY = getDimY_terr(pTerrain);
    
    fprintf(pFichier, "%d %d\n", dimX, dimY);
    
    int i, j;
    for(i = dimY - 1; i >= 0; i--){
	for(j = 0; j < dimX; j++){
            if(getEnvCase(getGrilleByXY_terr(j, i, pTerrain)) == VIDE){
		fputc(' ', pFichier);
	    }
	    else{
		fputc('X', pFichier);
	    }
	}
	fprintf(pFichier, "\n");

    }
    fprintf(pFichier, "\n");
}

Terrain * terrainLireFichier_terr (char * nomTerrain){
    FILE * pFichier;
    
    char cheminFichier[MAX_CHAR_NOM_TERRAIN + 16] = "../data/"; //16 correspond à la taille de la chaine d'accees
    strcat(cheminFichier, nomTerrain);
    strcat(cheminFichier, ".terrain");
    
    pFichier = fopen(cheminFichier,"r");

    assert(pFichier != NULL);

    Terrain * pTerrain = NULL;
    int dimX, dimY;
    fscanf(pFichier,"%d %d\n", &dimX, &dimY);
    printf("%d %d\n", dimX, dimY);
    pTerrain = terrainCreer_terr(dimX, dimY, nomTerrain);

    assert(pTerrain != NULL);

    caseDeplacement caseVide;
    char caseFichier;
    for(int i = dimY - 1; i >= 0; i--){
	for(int j = 0; j < dimX; j++){
            fscanf(pFichier,"%c", &caseFichier);
	    
            if(caseFichier==' '){
                setEnvCase(&caseVide,VIDE);
                setPersoCase(&caseVide,NULL);
                setGrilleByXY_terr(j,i,pTerrain,caseVide);
            }
	    
            if(caseFichier=='X'){
                setEnvCase(&caseVide,MUR);
                setPersoCase(&caseVide,NULL);
                setGrilleByXY_terr(j,i,pTerrain,caseVide);
            }
	}
	fscanf(pFichier,"\n");
    }

    return pTerrain;
}

void testFonctions_terr(){
    Terrain * pFichierLectureTest;
    Terrain * pFichierEcritureTest;
    
    char * nomFicEcriture = "FichierTestEcriture";
    char * nomFicLecture = "FichierTestLecture";

    pFichierEcritureTest = terrainCreer_terr (20, 15, nomFicEcriture);
    terrainCreerFichier_terr(pFichierEcritureTest);

    pFichierLectureTest = terrainLireFichier_terr(nomFicLecture);
    afficherGrilleConsole(pFichierLectureTest);
}
