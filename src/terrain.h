/**
   @file terrain.c
   @brief  Définit les fonctions et les structures du terrain
*/
#ifndef _TERRAIN
#define _TERRAIN

#define MAX_CHAR_NOM_TERRAIN 101
#define MAX_TAILLE_XY 1000

typedef struct MTerrain{
    int dimx, dimy;
    char nomTerrain[MAX_CHAR_NOM_TERRAIN];
	char grille[MAX_TAILLE_XY][MAX_TAILLE_XY];
    
} terrain;

void setXY (int x, int y, terrain * leTerrain);
void setnomTerrain(char nom[MAX_CHAR_NOM_TERRAIN], terrain * leTerrain);
void setgrilleXY (int x, int y, terrain * leTerrain, char valeur);
int getX(terrain * leTerrain);
int getY(terrain * leTerrain);
char * getnom(terrain * leTerrain);
char getgrilleXY (int x, int y,terrain * leTerrain);



void TerrainInit (terrain * leTerrain);

terrain * TerrainCreer (int dimx, int dimy, char nomTerrain[MAX_CHAR_NOM_TERRAIN]);

void TerrainCreerFichier (terrain * leTerrain);

terrain * TerrainLireFichier (char nomTerrain[MAX_CHAR_NOM_TERRAIN]);



#endif