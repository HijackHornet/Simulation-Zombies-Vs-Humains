/**
   @file terrain.c
   @brief  Définit les fonctions et les structures du terrain
*/
#ifndef _TERRAIN
#define _TERRAIN

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "caseDeplacement.h"

#define MAX_CHAR_NOM_TERRAIN 101
#define MAX_TAILLE_XY 1000

/** @struct terrain
 *  @brief Structure definissant un terrain et ses dimensions
 *  @var Terrain::dimX
 *  Largeur du terrain
 *  @var Terrain::dimY
 *  Hauteur du terrain
 *	@var Terrain::nomTerrain
 *	Nom du Terrain en chaine de carractere limité a 101 carracteres
 *	@var Terrain::grille
 *	Grille a deux dimension de carractere definisant la grille du terrain (sol / mur)
 */
typedef struct MTerrain{
    int dimX, dimY;
    char nomTerrain[MAX_CHAR_NOM_TERRAIN];
    caseDeplacement grille[MAX_TAILLE_XY][MAX_TAILLE_XY];
} Terrain;

/**
	@brief Edition de X et de Y dans la structure
	@param x Entier pour la largeur du terrain
	@param y Entier pour la hauteur du terrain
	@param pTerrain Pointeur sur la structure terrain a editer
*/
void setXY_terr (int x, int y, Terrain * pTerrain);
/**
	@brief Edition du nom du terrain dans sa structure
	@param nom Chaine de carractere ne pouvant dépasser les 101 carractere et definissant le nom du terrain
	@param pTerrain Pointeur sur la structure terrain a editer
*/
void setnomTerrain_terr(char nom[MAX_CHAR_NOM_TERRAIN], Terrain * pTerrain);
/**
	@brief Edition de la grille du terrain au coordonnées X/Y
	@param x Valeur ou le point de la grille doit etre edité en X
	@param y Valeur ou le point de la grille doit etre edité en Y
	@param pTerrain Pointeur sur la structure Terrain a editer
	@param valeur Carractere definissant ce que serra la case
*/
void setgrilleXY_terr (int x, int y, Terrain * pTerrain, char valeur);
/**
	@brief Recupère la dimension en X de la structure Terrain
	@param pTerrain Pointeur sur la structure Terrain a lire
	@return Entier de la dimension en X du terrain
*/
int getX_terr(Terrain * pTerrain);
/**
	@brief Recupère la dimension en Y de la structure Terrain
	@param pTerrain Pointeur sur la structure Terrain a lire
	@return Entier de la dimension en Y du terrain
*/
int getY_terr(Terrain * pTerrain);
/**
	@brief Recupère le nom de la structure Terrain
	@param pTerrain Pointeur sur la structure Terrain a lire
	@return Chaine de carractere du nom du terrain pointé
*/
char * getnom_terr(Terrain * pTerrain);
/**
	@brief Recupere la valleur de la grille au point X/Y
	@param x Position en x a recuperer
	@param y poisition en u a récuperer 
	@param pTerrain Pointeur sur la structure Terrain a editer
	@return Le carractere de la grille en X/Y
*/
char getgrilleXY_terr (int x, int y,Terrain * pTerrain);


/**
	@brief Sert a remplir la grille de terrain avec un valeur par défaut
	@param pTerrain Pointeur sur la structure Terrain a editer
*/
void terrainInitGrille_terr (Terrain * pTerrain);
/**
	@brief Creer un terrain avec les dimension et le nom choisi et initialise sa grille en appelant TerrainInitGrille
	@param dimX La largeur du terrain
	@param dimY La haueteur du terrain
	@param nomTerrain Nom du terrain a creer
	@return Pointeur vers le terrain nouvellement creer
*/
Terrain * terrainCreer_terr (int dimX, int dimY, char nomTerrain[MAX_CHAR_NOM_TERRAIN]);
/**
	@brief Sauvegarde le terrain pointé dans un fichier (.terrain)
	@param pTerrain Pointeur sur la structure Terrain a sauvegarder
*/
void terrainCreerFichier_terr (Terrain * pTerrain);
/**
	@brief Li le fichier terrain de nom spécifié et le retourne par un pointeur
	@param nomTerrain Nom du fichier terrain à lire
	@return Pointeur vers la structure lu dans le fichier
*/
Terrain * terrainLireFichier_terr (char nomTerrain[MAX_CHAR_NOM_TERRAIN]);



#endif
