/**
   @file terrain.h
   @brief  Définit les fonctions et les structures du terrain
*/
#ifndef _TERRAIN_H
#define _TERRAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <string.h>

#include "caseDeplacement.h"
#include "coordonnees.h"

#define MAX_CHAR_NOM_TERRAIN 101
#define MAX_TAILLE_XY 500

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
    caseDeplacement * grille;
} Terrain;

//////////////////////////////////////////////////////////////////////////////
//ACCESSEURS//////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
/**
	@brief Edition de X et de Y dans la structure
	@param x Entier pour la largeur du terrain
	@param y Entier pour la hauteur du terrain
	@param pTerrain Pointeur sur la structure terrain a editer
*/
void setDim_terr (int x, int y, Terrain * pTerrain);
/**
	@brief Edition du nom du terrain dans sa structure
	@param nom Chaine de carractere ne pouvant dépasser les 101 carractere et definissant le nom du terrain
	@param pTerrain Pointeur sur la structure terrain a editer
*/
void setNomTerrain_terr(char nom[MAX_CHAR_NOM_TERRAIN], Terrain * pTerrain);
/**
	@brief Edition du type de la grille du terrain au coordonnées X/Y
	@param x Valeur ou le point de la grille doit etre edité en X
	@param y Valeur ou le point de la grille doit etre edité en Y
	@param pTerrain Pointeur sur la structure Terrain a editer
	@param caseDep Le type de case
*/
void setGrilleByXY_terr (int x, int y, Terrain * pTerrain, caseDeplacement * caseDep);

/**
	@brief Recupère la dimension en X de la structure Terrain
	@param pTerrain Pointeur sur la structure Terrain a lire
	@return Entier de la dimension en X du terrain
*/
int getDimX_terr(Terrain * pTerrain);
/**
	@brief Recupère la dimension en Y de la structure Terrain
	@param pTerrain Pointeur sur la structure Terrain a lire
	@return Entier de la dimension en Y du terrain
*/
int getDimY_terr(Terrain * pTerrain);
/**
	@brief Recupère le nom de la structure Terrain
	@param pTerrain Pointeur sur la structure Terrain a lire
	@return Chaine de carractere du nom du terrain pointé
*/
char * getNomTerrain_terr(Terrain * pTerrain);
/**
	@brief Recupere la case de deplacement de la grille au point X/Y
	@param x Position en x a recuperer
	@param y poisition en y a récuperer
	@param pTerrain Pointeur sur la structure Terrain a editer
	@return Case de deplacement en XY
*/
caseDeplacement * getGrilleByXY_terr (int x, int y,Terrain * pTerrain);
/**
	@brief Recupere la case de deplacement de la grille au coordonnées données
	@param pCoord Coordonnée ou aller recuperer
	@param pTerrain Pointeur sur la structure Terrain a editer
	@return Case de deplacement au coordonnées
*/
caseDeplacement * getGrilleByCoord_terr(Coordonnees * pCoord, Terrain * pTerrain);
/**
	@brief Change la case de deplacement de la grille au coordonnées données
	@param pCoord Coordonnée ou aller recuperer
	@param pTerrain Pointeur sur la structure Terrain a editer
	@param caseDep Case de deplacement a placer au coordonnées
*/
void setGrilleByCoord_terr(Coordonnees * coord, Terrain * pTerrain, caseDeplacement * caseDep);

Perso * creePersoTerrainRand(Terrain * pTerrain, enum typePerso type, int idPerso);

/**
	@brief Recupere la case de deplacement de la grille en dessous des coordonée
	@param coord Coordonnée ou aller recuperer
	@param pTerrain Pointeur sur la structure Terrain a editer
	@return Case de deplacement en dessous
*/
caseDeplacement * getCaseBasByCoord(Coordonnees * coord, Terrain * pTerrain);
/**
	@brief Recupere la case de deplacement de la grille en haut des coordonée
	@param coord Coordonnée ou aller recuperer
	@param pTerrain Pointeur sur la structure Terrain a editer
	@return Case de deplacement en haut
*/
caseDeplacement * getCaseHautByCoord(Coordonnees * coord, Terrain * pTerrain);
/**
	@brief Recupere la case de deplacement de la grille a gauche des coordonée
	@param coord Coordonnée ou aller recuperer
	@param pTerrain Pointeur sur la structure Terrain a editer
	@return Case de deplacement a gauche
*/
caseDeplacement * getCaseGaucheByCoord(Coordonnees * coord, Terrain * pTerrain);
/**
	@brief Recupere la case de deplacement de la grille a droite des coordonée
	@param coord Coordonnée ou aller recuperer
	@param pTerrain Pointeur sur la structure Terrain a editer
	@return Case de deplacement a droite
*/
caseDeplacement * getCaseDroiteByCoord(Coordonnees * coord, Terrain * pTerrain);

////////////////////////////////////////////////////////////////////////////
//CREATION//////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/**
	@brief Initialise la grille d'un terrain
	@param pTerrain Pointeur vers le terrain a initialiser
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
	@brief Libere la mémoire occupé par un terrain
	@param pTerrain Pointeur vers le terrain a liberer
*/
void testamentTerrain_terr(Terrain * pTerrain);

/////////////////////////////////////////////////////////////////////////////
//TESTS SPECIFIQUES//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/**
	@brief Verifie si des coordonnées appartiennent au terrain
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@param pCoord Les coordonnées a verifier
	@return 1 si oui, 0 sinon, sous forme d'un caractere
*/
char estDansTerrain_terr(Terrain * pTerrain, Coordonnees * pCoord);

/////////////////////////////////////////////////////////////////////////////
//DEPLACEMENT PERSONNAGES////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/**
	@brief Verifie si le personnage peut aller en haut
	@param pPerso Pointeur vers le personnage dont les deplacement serront testé
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@return 1 si oui, 0 sinon, sous forme d'un caractere
*/
char verifDeplacementHaut_perso(Perso * pPerso, Terrain * pTerrain);
/**
	@brief Verifie si le personnage peut aller en bas
	@param pPerso Pointeur vers le personnage dont les deplacement serront testé
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@return 1 si oui, 0 sinon, sous forme d'un caractere
*/
char verifDeplacementBas_perso(Perso * pPerso, Terrain * pTerrain);
/**
	@brief Verifie si le personnage peut aller a gauche
	@param pPerso Pointeur vers le personnage dont les deplacement serront testé
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@return 1 si oui, 0 sinon, sous forme d'un caractere
*/
char verifDeplacementGauche_perso(Perso * pPerso, Terrain * pTerrain);
/**
	@brief Verifie si le personnage peut aller a droite
	@param pPerso Pointeur vers le personnage dont les deplacement serront testé
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@return 1 si oui, 0 sinon, sous forme d'un caractere
*/
char verifDeplacementDroite_perso(Perso * pPerso, Terrain * pTerrain);
/**
	@brief Deplace le personnage vers le haut (test avant qu'il peut etre deplacé dans ce sens)
	@param pPerso Pointeur vers le personnage dont les deplacement serront testé
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@return 1 si le personnage a été deplacé, 0 sinon, sous forme d'un caractere
*/
char deplacementHaut_perso(Perso * pPerso, Terrain * pTerrain);
/**
	@brief Deplace le personnage vers le bas (test avant qu'il peut etre deplacé dans ce sens)
	@param pPerso Pointeur vers le personnage dont les deplacement serront testé
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@return 1 si le personnage a été deplacé, 0 sinon, sous forme d'un caractere
*/
char deplacementBas_perso(Perso * pPerso, Terrain * pTerrain);
/**
	@brief Deplace le personnage vers la gauche (test avant qu'il peut etre deplacé dans ce sens)
	@param pPerso Pointeur vers le personnage dont les deplacement serront testé
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@return 1 si le personnage a été deplacé, 0 sinon, sous forme d'un caractere
*/
char deplacementGauche_perso(Perso * pPerso, Terrain * pTerrain);
/**
	@brief Deplace le personnage vers la droite (test avant qu'il peut etre deplacé dans ce sens)
	@param pPerso Pointeur vers le personnage dont les deplacement serront testé
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@return 1 si le personnage a été deplacé, 0 sinon, sous forme d'un caractere
*/
char deplacementDroite_perso(Perso * pPerso, Terrain * pTerrain);
/**
	@brief Deplace le personnage dans une direction aléatoire (test avant qu'il peut etre deplacé dans ce sens)
	@param pPerso Pointeur vers le personnage dont les deplacement serront testé
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@return 1 si le personnage a été deplacé, 0 sinon, sous forme d'un caractere
*/
char deplacementAleatoire_perso(Perso * pPerso, Terrain * pTerrain);

/////////////////////////////////////////////////////////////////////////////
//INTERACTIONS///////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

Perso * zombieContamineHumain(Perso * pZombie, Terrain * pTerrain);

Perso * policierTueZombie(Perso * pPolicier, Terrain * pTerrain);

/////////////////////////////////////////////////////////////////////////////
//SPECIFIQUE ZOMBIE//////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/**
	@brief Verifie si le personnage en haut est un humain
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@param coordZombie coordonnées du zombie qui va regarder si un humain se trouve a proximité
	@return 1 si oui, 0 sinon, sous forme d'un caractere
*/
char humainEnHaut(Terrain * pTerrain, Coordonnees * coordZombie);
/**
	@brief Verifie si le personnage en bas est un humain
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@param coordZombie coordonnées du zombie qui va regarder si un humain se trouve a proximité
	@return 1 si oui, 0 sinon, sous forme d'un caractere
*/
char humainEnBas(Terrain * pTerrain, Coordonnees * coordZombie);
/**
	@brief Verifie si le personnage a gauche est un humain
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@param coordZombie coordonnées du zombie qui va regarder si un humain se trouve a proximité
	@return 1 si oui, 0 sinon, sous forme d'un caractere
*/
char humainAGauche(Terrain * pTerrain, Coordonnees * coordZombie);
/**
	@brief Verifie si le personnage a droite est un humain
	@param pTerrain Le terrain ou les coordonnées vont etre vérifiés
	@param coordZombie coordonnées du zombie qui va regarder si un humain se trouve a proximité
	@return 1 si oui, 0 sinon, sous forme d'un caractere
*/
char humainADroite(Terrain * pTerrain, Coordonnees * coordZombie);


/////////////////////////////////////////////////////////////////////////////
//ENTREES-SORTIES////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/**
	@brief Affiche la grille dans la console avec des caractère pour représenter les personnages et murs
*/
void afficherGrilleConsole(Terrain * pTerrain);
/**
	@brief Créer un fichier terrain à partir du pointeur vers terrain
	@param pTerrain Pointeur vers le terrain qui serra enregistré dans un fichier
*/
void terrainCreerFichier_terr (Terrain * pTerrain);
/**
	@brief Li le fichier terrain de nom spécifié et le retourne par un pointeur
	@param nomTerrain Nom du fichier terrain à lire
	@return Pointeur vers la structure lu dans le fichier
*/
Terrain * terrainLireFichier_terr (char nomTerrain[MAX_CHAR_NOM_TERRAIN]);
/**
	@brief Affiche la grille des champs dans la console avec des caractère pour représenter les représenter
*/
void afficherChamps(Terrain * pTerrain);

/////////////////////////////////////////////////////////////////////////////
//CHAMPS/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/**
	@brief Initialisé la grille des champs à 0 avec des marqueurs
*/
void initialisationMarqueurs(Terrain * pTerrain);

void propagationChamp(enum typePerso type, int idPerso, Coordonnees  * coordPerso, Terrain * pTerrain);

/////////////////////////////////////////////////////////////////////////////
//NON REGRESSION/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
/**
	@brief Fonctoin de test des fonction du module terrain
*/
void testFonctions_terr();

void initChampsTerrain(int nbZombie, int nbCitoyens, int nbPoliciers, Terrain * pTerrain);

#endif
