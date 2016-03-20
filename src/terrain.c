/**
   @file terrain.c
   @brief  Implémente les fonctions de manipulation du Terrain
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "terrain.h"


void setXY_terr (int x, int y, Terrain * pTerrain){

	pTerrain->dimX = x;
	pTerrain->dimY = y;
}


void setnomTerrain_terr(char * nom, Terrain * pTerrain){
	int i;
	for (i=0; i<MAX_CHAR_NOM_TERRAIN; i++){
		pTerrain->nomTerrain[i] = nom[i];}
}

void setgrilleXY_terr (int x, int y, Terrain * pTerrain, char valeur){
	pTerrain->grille[x][y] = valeur;
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

char getgrilleXY_terr (int x, int y,Terrain * pTerrain){
	return pTerrain->grille[x][y];
}



void terrainInitGrille_terr (Terrain * pTerrain){
	int i,j;
	char X = 'X';
	for(i=0;i<(pTerrain->dimX);i++){
		for(j=0;j<(pTerrain->dimY);j++){
			setgrilleXY_terr(i,j,pTerrain,X);
		}
	}

}

Terrain * terrainCreer_terr (int dimX, int dimY, char nomTerrain[MAX_CHAR_NOM_TERRAIN]){
	Terrain * temp = NULL;
	temp = malloc(sizeof(Terrain)); //semble avoir un probleme ici
	setXY_terr(dimX,dimY,temp);
	setnomTerrain_terr(nomTerrain,temp);
	terrainInitGrille_terr(temp);
	return temp;
}


void terrainCreerFichier_terr (Terrain * pTerrain){
	FILE * fichier;
	int err;
	//err = fopen_s(&fichier, "./data/test.Terrain","w");
	int i, j;
	for(i = 0; i<(pTerrain->dimX); i++){
		for(j = 0; j<pTerrain->dimY; j++){
			//fscanf(fichier,"%c ", pTerrain->grille[i][j]);
		}
		 //fscanf(fichier,"/n");
	}
}
/*
Terrain * terrainLireFichier (char nomTerrain[MAX_CHAR_NOM_TERRAIN]);
A CODER QUAND LE FONCTION DU DESSUS MARCHERA
*/
