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

void setGrilleByCoord_terr(Coordonnees * coord, Terrain * pTerrain, caseDeplacement * caseDep){
    setGrilleByXY_terr(getXCoord_Coord(coord), getYCoord_Coord(coord), pTerrain, caseDep);
}

void setGrilleByXY_terr (int x, int y, Terrain * pTerrain, caseDeplacement * caseDep){
    pTerrain->grille[x][y] = *caseDep;
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
    Coordonnees coord2 = getCoordCaseBasByXY_terr(getXCoord_Coord(coord), getYCoord_Coord(coord));
    printf("%d %d", coord2.xCoord, coord2.yCoord);
    return coord2;
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

char placePersoByCoord(Perso * pPerso, Coordonnees * coord, Terrain * pTerrain){
    if(getEnvCase(getGrilleByCoord_terr(coord, pTerrain)) == VIDE && getPersoCase(getGrilleByCoord_terr(coord, pTerrain)) == NULL){
	caseDeplacement * pCase = initCase(VIDE, pPerso);
	
	setGrilleByCoord_terr(coord, pTerrain, pCase);

	free(pCase);

	return 1;
    }
    
    else{
	return 0;
    }
}

Perso * creePersoTerrainRand(Terrain * pTerrain, enum typePerso type, int idPerso){ //crée un perso et le place sur le terrain
    Coordonnees * pCoordZombie = initCoordonnees_coord(-1, -1);
    Perso * pZombie = initPerso(pCoordZombie, type, idPerso);

    char coordOk = 0;
    
    while(!coordOk){
	setXCoord_Coord(rand()%getDimX_terr(pTerrain), pCoordZombie);
	setYCoord_Coord(rand()%getDimY_terr(pTerrain), pCoordZombie);

	coordOk = placePersoByCoord(pZombie, pCoordZombie, pTerrain);
    }
    
    return pZombie;
}

//////////////////////////////////////////////////////////////////////////////
//CREATION-TESTAMENT//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void terrainInitGrille_terr (Terrain * pTerrain){
    caseDeplacement X;
    setPersoCase(&X, NULL);
    setEnvCase(&X, VIDE);

    int i,j;
    
    for(i=0; i < getDimX_terr(pTerrain); i++){
	for(j=0; j < getDimY_terr(pTerrain); j++){
	    setGrilleByXY_terr(i, j, pTerrain, &X);
	}
    }
}

Terrain * terrainCreer_terr (int dimX, int dimY, char nomTerrain[MAX_CHAR_NOM_TERRAIN]){
    Terrain * pTerrain = NULL;
    pTerrain = (Terrain*)malloc(sizeof(Terrain));
    setDim_terr(dimX,dimY, pTerrain);
    setNomTerrain_terr(nomTerrain, pTerrain);
    terrainInitGrille_terr(pTerrain);
    return pTerrain;
}

void testamentTerrain_terr(Terrain * pTerrain){
    free(pTerrain);

    pTerrain = NULL;
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
    Coordonnees coordBas = (Coordonnees){getXPerso_perso(pPerso), getYPerso_perso(pPerso) - 1};

    return (estDansTerrain_terr(pTerrain, &coordBas) && getPersoCase(getGrilleByCoord_terr(&coordBas, pTerrain)) == NULL && getEnvCase(getGrilleByCoord_terr(&coordBas, pTerrain)) == VIDE);
}

char verifDeplacementHaut_perso(Perso * pPerso, Terrain * pTerrain){
    Coordonnees coordHaut = (Coordonnees){getXPerso_perso(pPerso), getYPerso_perso(pPerso) + 1};

    return (estDansTerrain_terr(pTerrain, &coordHaut) && getPersoCase(getGrilleByCoord_terr(&coordHaut, pTerrain)) == NULL && getEnvCase(getGrilleByCoord_terr(&coordHaut, pTerrain)) == VIDE);
}

char verifDeplacementGauche_perso(Perso *  pPerso, Terrain * pTerrain){
    Coordonnees coordGauche = (Coordonnees){getXPerso_perso(pPerso) - 1, getYPerso_perso(pPerso)};

    return (estDansTerrain_terr(pTerrain, &coordGauche) && getPersoCase(getGrilleByCoord_terr(&coordGauche, pTerrain)) == NULL && getEnvCase(getGrilleByCoord_terr(&coordGauche, pTerrain)) == VIDE);
}

char verifDeplacementDroite_perso(Perso * pPerso, Terrain * pTerrain){
    Coordonnees coordDroite = (Coordonnees){getXPerso_perso(pPerso) + 1, getYPerso_perso(pPerso)};

    return (estDansTerrain_terr(pTerrain, &coordDroite) && getPersoCase(getGrilleByCoord_terr(&coordDroite, pTerrain)) == NULL && getEnvCase(getGrilleByCoord_terr(&coordDroite, pTerrain)) == VIDE);
}

char deplacementHaut_perso(Perso * pPerso, Terrain * pTerrain){
    if(verifDeplacementHaut_perso(pPerso, pTerrain)){
	
        setPersoCase(getGrilleByCoord_terr(getCoordonneesPerso_perso(pPerso), pTerrain), NULL);

	setYPerso_perso(pPerso, getYPerso_perso(pPerso) + 1);

	placePersoByCoord(pPerso, getCoordonneesPerso_perso(pPerso), pTerrain);

	return 1;
    }

    else{
	return 0;
    }
}

char deplacementBas_perso(Perso * pPerso, Terrain * pTerrain){
    if(verifDeplacementBas_perso(pPerso, pTerrain)){

        setPersoCase(getGrilleByCoord_terr(getCoordonneesPerso_perso(pPerso), pTerrain), NULL);

	setYPerso_perso(pPerso, getYPerso_perso(pPerso) - 1);

        setPersoCase(getGrilleByCoord_terr(getCoordonneesPerso_perso(pPerso), pTerrain), pPerso);

	return 1;
    }

    else{
	return 0;
    }
}

char deplacementGauche_perso(Perso * pPerso, Terrain * pTerrain){
    if(verifDeplacementGauche_perso(pPerso, pTerrain)){

        setPersoCase(getGrilleByCoord_terr(getCoordonneesPerso_perso(pPerso), pTerrain), NULL);

	setXPerso_perso(pPerso, getXPerso_perso(pPerso) - 1);

	placePersoByCoord(pPerso, getCoordonneesPerso_perso(pPerso), pTerrain);
    
	return 1;
    }

    else{
	return 0;
    }
}

char deplacementDroite_perso(Perso * pPerso, Terrain * pTerrain){
    if(verifDeplacementDroite_perso(pPerso, pTerrain)){
        setPersoCase(getGrilleByCoord_terr(getCoordonneesPerso_perso(pPerso), pTerrain), NULL);

	setXPerso_perso(pPerso, getXPerso_perso(pPerso) + 1);

        setPersoCase(getGrilleByCoord_terr(getCoordonneesPerso_perso(pPerso), pTerrain), pPerso);

	return 1;
    }

    else{
	return 0;
    }
}

void deplacementAleatoire_perso(Perso * pPerso, Terrain * pTerrain){
    char deplacementEffectue = 0;

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

    printf("%d %d", coordZombie -> xCoord, coordZombie -> yCoord);
    
    if(estDansTerrain_terr(pTerrain, &coordCaseHaut) && \
       getPersoCase(getGrilleByCoord_terr(&coordCaseHaut, pTerrain)) != NULL){ //Vérifie d'une part que la case est dans le terrain, d'autre part qu'il y a bien un personnage sur cette case pour pouvoir appeler getTypePerso (SEGFAULT si NULL)
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

    printf("%d %d", coordCaseBas.xCoord, coordCaseBas.yCoord);
    
    if(estDansTerrain_terr(pTerrain, &coordCaseBas) && \
       getPersoCase(getGrilleByCoord_terr(&coordCaseBas, pTerrain)) != NULL){ //Vérifie d'une part que la case est dans le terrain, d'autre part qu'il y a bien un personnage sur cette case pour pouvoir appeler getTypePerso (SEGFAULT si NULL)
	
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

    if(estDansTerrain_terr(pTerrain, &coordCaseGauche) && \
       getPersoCase(getGrilleByCoord_terr(&coordCaseGauche, pTerrain)) != NULL){ //Vérifie d'une part que la case est dans le terrain, d'autre part qu'il y a bien un personnage sur cette case pour pouvoir appeler getTypePerso (SEGFAULT si NULL)
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

    if(estDansTerrain_terr(pTerrain, &coordCaseDroite) && \
       getPersoCase(getGrilleByCoord_terr(&coordCaseDroite, pTerrain)) != NULL){ //Vérifie d'une part que la case est dans le terrain, d'autre part qu'il y a bien un personnage sur cette case pour pouvoir appeler getTypePerso (SEGFAULT si NULL)
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
//INTERACTIONS///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

Perso * zombieContamineHumain(Perso * pZombie, Terrain * pTerrain){
    Coordonnees * coordZombie = getCoordonneesPerso_perso(pZombie);
    Coordonnees coordHumain;
    caseDeplacement * caseHumain;

    printf("%d %d %d",coordZombie -> xCoord, coordZombie -> yCoord, humainEnHaut(pTerrain, coordZombie));
    
    if(humainEnHaut(pTerrain, coordZombie)){
	coordHumain = getCoordCaseHautByCoord_terr(coordZombie);
	caseHumain = getGrilleByCoord_terr(&coordHumain, pTerrain);
	setTypePerso_perso(ZOMBIE, getPersoCase(caseHumain));
	assert(getTypePerso(getPersoCase(caseHumain)) == ZOMBIE);
	return getPersoCase(caseHumain);
    }
    
    else if(humainEnBas(pTerrain, coordZombie)){
	coordHumain = getCoordCaseBasByCoord_terr(coordZombie);
	printf("ping %d %d\n", coordHumain.xCoord, coordHumain.yCoord);
	caseHumain = getGrilleByCoord_terr(&coordHumain, pTerrain);
	setTypePerso_perso(ZOMBIE, getPersoCase(caseHumain));
	assert(getTypePerso(getPersoCase(caseHumain)) == ZOMBIE);
        return getPersoCase(caseHumain);
    }

    else if(humainAGauche(pTerrain, coordZombie)){
	coordHumain = getCoordCaseGaucheByCoord_terr(coordZombie);
	caseHumain = getGrilleByCoord_terr(&coordHumain, pTerrain);
	setTypePerso_perso(ZOMBIE, getPersoCase(caseHumain));
	assert(getTypePerso(getPersoCase(caseHumain)) == ZOMBIE);
        return getPersoCase(caseHumain);
    }

    else if(humainADroite(pTerrain, coordZombie)){
	coordHumain = getCoordCaseDroiteByCoord_terr(coordZombie);
	caseHumain = getGrilleByCoord_terr(&coordHumain, pTerrain);
	setTypePerso_perso(ZOMBIE, getPersoCase(caseHumain));
        assert(getTypePerso(getPersoCase(caseHumain)) == ZOMBIE);
        return getPersoCase(caseHumain);
    }

    return NULL;
}

/////////////////////////////////////////////////////////////////////////////
//ENTREES-SORTIES////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void afficherGrilleConsole(Terrain * pTerrain){
    for(int i = getDimY_terr(pTerrain) - 1; i >= 0; i--){
	for (int j = 0; j < getDimX_terr(pTerrain); j++) {
	    if(getPersoCase(getGrilleByXY_terr(j, i, pTerrain)) != NULL){
		if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == ZOMBIE){
		    printf("Z");
		}
		else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == CITOYEN){
		    printf("C");
		}
		else if(getTypePerso(getPersoCase(getGrilleByXY_terr(j, i, pTerrain))) == POLICIER){
		    printf("P");
		}
	    }
	    else{
		if(getEnvCase(getGrilleByXY_terr(j, i, pTerrain)) == VIDE){
		    printf(" ");
		}
		else{
		    printf("#");
		}
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
		fputc('#', pFichier);
	    }
	}
	fprintf(pFichier, "\n");

    }
    fprintf(pFichier, "\n");

    fclose(pFichier);
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
                setGrilleByXY_terr(j,i,pTerrain,&caseVide);
            }
	    
            if(caseFichier=='#'){
                setEnvCase(&caseVide,MUR);
                setPersoCase(&caseVide,NULL);
                setGrilleByXY_terr(j,i,pTerrain,&caseVide);
            }
	}
	fscanf(pFichier,"\n");
    }

    fclose(pFichier);

    return pTerrain;
}

void testFonctions_terr(){
    //Terrain * pFichierLectureTest;
    Terrain * pFichierEcritureTest;
    
    char * nomFicEcriture = "FichierTestEcriture";
    //char * nomFicLecture = "FichierTestLecture";

    pFichierEcritureTest = terrainCreer_terr (20, 15, nomFicEcriture);
    terrainCreerFichier_terr(pFichierEcritureTest);

    //pFichierLectureTest = terrainLireFichier_terr(nomFicLecture);
    //afficherGrilleConsole(pFichierLectureTest);

    Coordonnees * coordZombie = initCoordonnees_coord(2,3);
    Coordonnees * coordHumain = initCoordonnees_coord(2,2);

    Perso * pZombie = initPerso(coordZombie, ZOMBIE, 0);
    Perso * pHumain = initPerso(coordHumain, CITOYEN, 1);

    placePersoByCoord(pZombie, coordZombie, pFichierEcritureTest);
    placePersoByCoord(pHumain, coordHumain, pFichierEcritureTest);
    
    afficherGrilleConsole(pFichierEcritureTest);

    if(humainEnHaut(pFichierEcritureTest, getCoordonneesPerso_perso(pZombie))){
	printf("YES\n");
    }
    else{
	printf("NO\n");
    }

    zombieContamineHumain(pZombie, pFichierEcritureTest);

    afficherGrilleConsole(pFichierEcritureTest);

    /*
    
    deplacementDroite_perso(pHumain, pFichierEcritureTest);
    deplacementBas_perso(pHumain, pFichierEcritureTest);
    deplacementAleatoire_perso(pHumain, pFichierEcritureTest);

    afficherGrilleConsole(pFichierEcritureTest);

    if(humainADroite(pFichierEcritureTest, getCoordonneesPerso_perso(pZombie)) && !humainEnHaut(pFichierEcritureTest, getCoordonneesPerso_perso(pZombie))){
	printf("YES\n");
    }
    else{
	printf("NO\n");
    }
    
    testamentPerso(pZombie);
    testamentPerso(pHumain);

    pZombie = creePersoTerrainRand(pFichierLectureTest, ZOMBIE);

    afficherGrilleConsole(pFichierLectureTest);

    testamentPerso(pZombie);
    
    testamentTerrain_terr(pFichierEcritureTest);
    testamentTerrain_terr(pFichierLectureTest);
    */
}
