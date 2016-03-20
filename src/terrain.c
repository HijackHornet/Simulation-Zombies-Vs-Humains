/**
   @file terrain.c
   @brief  Implémente les fonctions de manipulation du Terrain
*/

#ifndef _TERRAIN_C
#define _TERRAIN_C

#include "terrain.h"

void setXY_terr (int x, int y, Terrain * pTerrain){

	pTerrain->dimX = x;
	pTerrain->dimY = y;
}


void setnomTerrain_terr(char * nom, Terrain * pTerrain){
	int i;
	for (i=0; i<MAX_CHAR_NOM_TERRAIN; i++){
		pTerrain->nomTerrain[i] = nom[i];
	}
}

void setXYCoord_Coord (int x, int y, Coordonnees * pCoord);void setgrilleXY_terr (int x, int y, Terrain * pTerrain, caseDeplacement caseDep){
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

caseDeplacement getgrilleXY_terr (int x, int y,Terrain * pTerrain){
	return pTerrain->grille[x][y];
}



void terrainInitGrille_terr (Terrain * pTerrain){
	int i,j;
	caseDeplacement X = (caseDeplacement){VIDE, VIDE};
	for(i=0; i < (pTerrain->dimX); i++){
		for(j=0; j < (pTerrain->dimY); j++){
			setgrilleXY_terr(i, j, pTerrain,X);
		}
	}

}

Terrain * terrainCreer_terr (int dimX, int dimY, char nomTerrain[MAX_CHAR_NOM_TERRAIN]){
	Terrain * pTerrain = NULL;
        pTerrain = malloc(sizeof(Terrain)); //semble avoir un probleme ici
	setXY_terr(dimX,dimY, pTerrain);
	setnomTerrain_terr(nomTerrain, pTerrain);
	terrainInitGrille_terr(pTerrain);
	return pTerrain;
}

void afficherGrilleConsole(Terrain * pTerrain){
    for(int i = 0; i < (pTerrain -> dimX); i++){
	for (int j = 0; j < (pTerrain -> dimY); j++) {
	    if((pTerrain -> grille)[i][j].envCase == VIDE){
		printf("v");
	    }
	}
	printf("\n");
    }
}



void terrainCreerFichier_terr (Terrain * pTerrain){
	FILE * pFichier;

	pFichier = fopen("../data/test.ter","w");

	assert(pFichier != NULL);
	
	int i, j;
	for(i = (pTerrain -> dimY) - 1; i >= 0; i--){
	    for(j = 0; j < (pTerrain -> dimX); j++){
		if((pTerrain -> grille)[i][j].envCase == VIDE)
		    fputc('v', pFichier);
		}
	    fprintf(pFichier, "\n");
	}
}


/*
Terrain * terrainLireFichier (char nomTerrain[MAX_CHAR_NOM_TERRAIN]);
A CODER QUAND LE FONCTION DU DESSUS MARCHERA
*/

int main(int argc, char *argv[])
{
    Terrain * ter = terrainCreer_terr(10, 10, "leNom");

    afficherGrilleConsole(ter);

    terrainCreerFichier_terr(ter);
    
    return 0;
}

#endif
