/**
   @file terrain.c
   @brief  Définit les fonctions et les structures du terrain
*/

#define MAX_CHAR_NOM_TERRAIN 101

typedef struct MTerrain{
    int dimx, dimy;
    char nomTerrain[MAX_CHAR_NOM_TERRAIN];
    
} terrain;
