/**
   @file terrain.c
   @brief  Implémente les fonctions de manipulation du terrain
*/
#include <stdio.h>
#include <stdlib.h>
#include "terrain.h"

void setXY (int x, int y, terrain * leTerrain){

	leTerrain->dimx = x;
	leTerrain->dimy = y;
}

void setnomTerrain(char * nom, terrain * leTerrain){
	int i;
	for (i=0; i<MAX_CHAR_NOM_TERRAIN; i++){
		leTerrain->nomTerrain[i] = nom[i];}
}
void setgrilleXY (int x, int y, terrain * leTerrain, char valeur){
	leTerrain->grille[x][y] = valeur;
}
int getX(terrain * leTerrain){
	return leTerrain->dimx;
}
int getY(terrain * leTerrain){
	return leTerrain->dimy;
}
char * getnom(terrain * leTerrain){
	return leTerrain->nomTerrain;
}
char getgrilleXY (int x, int y,terrain * leTerrain){
	return leTerrain->grille[x][y];
}



void TerrainInit (terrain * leTerrain){
	int i,j;
	char X = 'X';
	for(i=0;i<(leTerrain->dimx);i++){
		for(j=0;j<(leTerrain->dimy);j++){
			setgrilleXY(i,j,leTerrain,X);
		}
	}

}

terrain * TerrainCreer (int dimx, int dimy, char nomTerrain[MAX_CHAR_NOM_TERRAIN]){
	terrain * temp = NULL;
	temp = malloc(sizeof(terrain)); //semble avoir un probleme ici
	setXY(dimx,dimy,temp);
	setnomTerrain(nomTerrain,temp);
	TerrainInit(temp);
	return temp;
}


void TerrainCreerFichier (terrain * leTerrain){
	FILE * fichier;
	errno_t err;
	err = fopen_s(&fichier, "./data/test.terrain","w");
	int i, j;
	for(i = 0; i<(leTerrain->dimx); i++){
		for(j = 0; j<leTerrain->dimy; j++){
			//fscanf(fichier,"%c ", leTerrain->grille[i][j]);
		}
		 //fscanf(fichier,"/n");
	}
}
/*
terrain * TerrainLireFichier (char nomTerrain[MAX_CHAR_NOM_TERRAIN]); */