/**
   @file terrain.c
   @brief  Implémente les fonctions de manipulation du Terrain
*/

#include "terrain.h"
#include <string.h>


//////////////////////////////////////////////////////////////////////////////
//ACCESSEURS//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void setXY_terr (int x, int y, Terrain * pTerrain){
    pTerrain->dimX = x;
    pTerrain->dimY = y;
}

void setnomTerrain_terr(char * nom, Terrain * pTerrain){
    assert(strlen(nom)<MAX_CHAR_NOM_TERRAIN);
    strcpy(pTerrain->nomTerrain, nom);
}

void setgrilleXY_terr (int x, int y, Terrain * pTerrain, caseDeplacement caseDep){
    pTerrain->grille[x][y] = caseDep;
}

int getX_terr(Terrain * pTerrain){
    return pTerrain->dimX;
}

int getY_terr(Terrain * pTerrain){
    return pTerrain->dimY;
}

char * getnom_terr(Terrain * pTerrain){
    return pTerrain->nomTerrain;
}

caseDeplacement * getgrilleXY_terr (int x, int y,Terrain * pTerrain){
    return &(pTerrain->grille[x][y]);
}

//////////////////////////////////////////////////////////////////////////////
//CREATION////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

void terrainInitGrille_terr (Terrain * pTerrain){
    int i,j;
    caseDeplacement X;
    setPersoCase(&X, NULL);
    setEnvCase(&X, VIDE);
    for(i=0; i < getX_terr(pTerrain); i++){
	for(j=0; j < getY_terr(pTerrain); j++){
	    setgrilleXY_terr(i, j, pTerrain, X);
	}
    }

}

Terrain * terrainCreer_terr (int dimX, int dimY, char nomTerrain[MAX_CHAR_NOM_TERRAIN]){
    Terrain * pTerrain = NULL;
    pTerrain =(Terrain*)malloc(sizeof(Terrain));
    setXY_terr(dimX,dimY, pTerrain);
    setnomTerrain_terr(nomTerrain, pTerrain);
    terrainInitGrille_terr(pTerrain);
    return pTerrain;

}

/////////////////////////////////////////////////////////////////////////////
//TESTS SPECIFIQUES//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

char estDansTerrain_terr(Terrain * pTerrain, Coordonnees * pCoord){
    int xCoord = getXCoord_Coord(pCoord);
    int yCoord = getYCoord_Coord(pCoord);

    return (xCoord >= 0 && xCoord < getX_terr(pTerrain) && \
	    yCoord >= 0 && yCoord < getY_terr(pTerrain));
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

void deplacementHaut_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementHaut_perso(pPerso, pTerrain));

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), NULL);

    yPerso++;
    setYPerso_perso(pPerso, yPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), pPerso);
}

void deplacementBas_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementBas_perso(pPerso, pTerrain));

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), NULL);

    yPerso--;
    setYPerso_perso(pPerso, yPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), pPerso);
}

void deplacementGauche_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementGauche_perso(pPerso, pTerrain));

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), NULL);

    xPerso--;
    setXPerso_perso(pPerso, xPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), pPerso);
}

void deplacementDroite_perso(Perso * pPerso, Terrain * pTerrain){
    assert(verifDeplacementDroite_perso(pPerso, pTerrain));

    int xPerso = getXPerso_perso(pPerso);
    int yPerso = getYPerso_perso(pPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), NULL);

    xPerso++;
    setXPerso_perso(pPerso, xPerso);

    setPersoCase(getgrilleXY_terr(xPerso, yPerso, pTerrain), pPerso);
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

/////////////////////////////////////////////////////////////////////////////
//SPECIFIQUE ZOMBIE//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
char humainEnHaut(Terrain * pTerrain, Coordonnees * coordZombie){
    caseDeplacement * caseHaut = getgrilleXY_terr(getXCoord_Coord(coordZombie), getYCoord_Coord(coordZombie) + 1, pTerrain);
    
    if(getTypePerso(getPersoCase(caseHaut)) == CITOYEN || getTypePerso(getPersoCase(caseHaut)) == POLICIER){
	return 1;
    }
    else{
	return 0; 
    }
}

char humainEnBas(Terrain * pTerrain, Coordonnees * coordZombie){
    caseDeplacement * caseBas = getgrilleXY_terr(getXCoord_Coord(coordZombie), getYCoord_Coord(coordZombie) - 1, pTerrain);
    
    if(getTypePerso(getPersoCase(caseBas)) == CITOYEN || getTypePerso(getPersoCase(caseBas)) == POLICIER){
	return 1;
    }
    else{
	return 0; 
    }
}

char humainAGauche(Terrain * pTerrain, Coordonnees * coordZombie){
    caseDeplacement * caseGauche = getgrilleXY_terr(getXCoord_Coord(coordZombie)-1, getYCoord_Coord(coordZombie), pTerrain);
    
    if(getTypePerso(getPersoCase(caseGauche)) == CITOYEN || getTypePerso(getPersoCase(caseGauche)) == POLICIER){
	return 1;
    }
    else{
	return 0; 
    }
}

char humainADroite(Terrain * pTerrain, Coordonnees * coordZombie){
    caseDeplacement * caseDroite = getgrilleXY_terr(getXCoord_Coord(coordZombie)+1, getYCoord_Coord(coordZombie), pTerrain);
    
    if(getTypePerso(getPersoCase(caseDroite)) == CITOYEN || getTypePerso(getPersoCase(caseDroite)) == POLICIER){
	return 1;
    }
    else{
	return 0;
    }
}


/////////////////////////////////////////////////////////////////////////////
//ENTREES-SORTIES////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void afficherGrilleConsole(Terrain * pTerrain){
    for(int i = getY_terr(pTerrain) - 1; i >= 0; i--){
	for (int j = 0; j < getX_terr(pTerrain); j++) {
	    if(getEnvCase(getgrilleXY_terr(j, i, pTerrain)) == VIDE){
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
    
    strcat(cheminFichier, getnom_terr(pTerrain));
    strcat(cheminFichier, ".terrain");
    
    pFichier = fopen(cheminFichier,"w");

    int dimX = getX_terr(pTerrain);
    int dimY = getY_terr(pTerrain);
    
    fprintf(pFichier, "%d %d\n", dimX, dimY);
    
    int i, j;
    for(i = dimY - 1; i >= 0; i--){
	for(j = 0; j < dimX; j++){
            if(getEnvCase(getgrilleXY_terr(j, i, pTerrain)) == VIDE){
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
                setgrilleXY_terr(j,i,pTerrain,caseVide);
            }
	    
            if(caseFichier=='X'){
                setEnvCase(&caseVide,MUR);
                setPersoCase(&caseVide,NULL);
                setgrilleXY_terr(j,i,pTerrain,caseVide);
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
