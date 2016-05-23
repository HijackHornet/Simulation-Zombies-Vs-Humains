/**
   @file coordonnees.h
   @brief  Définit les coordonnées atomiques du terrain et ses accesseurs
*/

#ifndef _COORDONNEES
#define _COORDONNEES

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

/** @struct MCoordonnees
 *  @brief Structure definissant des coordonnees en deux dimension (pour des entitées)
 *  @var MCoordonnees::xCoord
 *  Position sur l'axe des X
 *  @var MCoordonnees::yCoord
 *  Position sur l'axe des Y
 */
typedef struct MCoordonnees{
    int xCoord;
    int yCoord;
} Coordonnees;


///////////////////////////////////////////////////////////////////////
//ACCESSEURS///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

/**
	@brief Edition de xCoord dans la structure
	@param x Valeur sur l'axe des x
	@param pCoord Pointeur sur la structure Coordonnees à editer
*/
void setXCoord_Coord(int x, Coordonnees * pCoord);
/**
	@brief Edition de yCoord dans la structure
	@param y Valeur sur l'axe des y
	@param pCoord Pointeur sur la structure Coordonnees à editer
*/
void setYCoord_Coord(int y, Coordonnees * pCoord);
/**
	@brief Edition de xCoord et de yCoord dans la structure
	@param xCoord Valeur sur l'axe des x
	@param yCoord Valeur sur l'axe des y
	@param pCoord Pointeur sur la structure Coordonnees à editer
*/
void setXYCoord_Coord (int x, int y, Coordonnees * pCoord);
/**
	@brief Recupère xCoord
	@param pCoord Pointeur sur la structure Coordonnees à lire
	@return La valeur de xCoord
*/
int getXCoord_Coord(Coordonnees * pCoord);
/**
	@brief Recupère yCoord
	@param pCoord Pointeur sur la structure Coordonnees à lire
	@return La valeur de YCoord
*/
int getYCoord_Coord(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la case en dessous des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la case en dessous
*/
Coordonnees getCoordCaseBasByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la case à droite des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la case à droite
*/
Coordonnees getCoordCaseDroiteByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la case à gauche des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la case à gauche
*/
Coordonnees getCoordCaseGaucheByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la case en haut des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la case en haut
*/
Coordonnees getCoordCaseHautByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la case en dessous d'une structure de coordonnée
	@param coord Pointeur sur les coordonnées de reference
	@return Les coordonnées de la case en dessous
*/
Coordonnees getCoordCaseBasByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la case en haut d'une structure de coordonnée
	@param coord Pointeur sur les coordonnées de reference
	@return Les coordonnées de la case en haut
*/
Coordonnees getCoordCaseHautByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la case à gauche d'une structure de coordonnée
	@param coord Pointeur sur les coordonnées de reference
	@return Les coordonnées de la case à gauche
*/
Coordonnees getCoordCaseGaucheByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la case à droite d'une structure de coordonnée
	@param coord Pointeur sur les coordonnées de reference
	@return Les coordonnées de la case à droite
*/
Coordonnees getCoordCaseDroiteByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la 2eme case à droite des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la 2eme case à droite
*/
Coordonnees getCoordCase2DroiteByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la 2eme case à gauche des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la 2eme case à gauche
*/
Coordonnees getCoordCase2GaucheByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la 2eme case en haut des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la 2eme case en haut
*/
Coordonnees getCoordCase2HautByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la 2eme case en bas des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la 2eme case en bas
*/
Coordonnees getCoordCase2BasByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la case en haut à droite des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la case en haut à droite 
*/
Coordonnees getCoordCaseHDByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la case en bas à droite des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la case en bas à droite 
*/
Coordonnees getCoordCaseBDByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la case en bas à gauche des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la case en bas à gauche 
*/
Coordonnees getCoordCaseBGByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la case en haut à gauche des coordonnées X/Y
	@param x La coordonnées en X
	@param y La coordonnées en Y
	@return Les coordonnées de la case en haut à gauche 
*/
Coordonnees getCoordCaseHGByXY_terr(int x, int y);
/**
	@brief Retourne des coordonnées de la 2eme case en bas à partir de coordonnées
	@param coord Pointeur vers les coordonnées de référence
	@return Les coordonnées de la 2eme case en bas
*/
Coordonnees getCoordCase2BasByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la 2eme case à droite à partir de coordonnées
	@param coord Pointeur vers les coordonnées de référence
	@return Les coordonnées de la 2eme case à droite
*/
Coordonnees getCoordCase2DroiteByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la 2eme case à gauche à partir de coordonnées
	@param coord Pointeur vers les coordonnées de référence
	@return Les coordonnées de la 2eme case à gauche
*/
Coordonnees getCoordCase2GaucheByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la 2eme case en haut à partir de coordonnées
	@param coord Pointeur vers les coordonnées de référence
	@return Les coordonnées de la 2eme case en haut
*/
Coordonnees getCoordCase2HautByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la case en haut à droite à partir de coordonnées
	@param coord Pointeur vers les coordonnées de référence
	@return Les coordonnées de la 2eme case en haut à droite
*/
Coordonnees getCoordCaseHDByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la case en bas à droite à partir de coordonnées
	@param coord Pointeur vers les coordonnées de référence
	@return Les coordonnées de la 2eme case en bas à droite
*/
Coordonnees getCoordCaseBDByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la case en bas à gauche à partir de coordonnées
	@param coord Pointeur vers les coordonnées de référence
	@return Les coordonnées de la 2eme case en bas à gauche
*/
Coordonnees getCoordCaseBGByCoord_terr(Coordonnees * pCoord);
/**
	@brief Retourne des coordonnées de la case en haut à gauche à partir de coordonnées
	@param coord Pointeur vers les coordonnées de référence
	@return Les coordonnées de la 2eme case en haut à gauche
*/
Coordonnees getCoordCaseHGByCoord_terr(Coordonnees * pCoord);

/////////////////////////////////////////////////////////////////////////
//INITIALISATIONS-TESTAMENTS/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

/**
	@brief Crée et initialise des coordonnées avec les valeur XY
	@param x Entier de valeur de X
	@param y Entier de valeur de Y
	@return Des coordonnées initialisées
*/
Coordonnees * initCoordonnees_coord(int x, int y);
/**
	@brief Détruit et libère des coordonnées
	@param coord Les coordonnées a liberer et détruire
*/
void testamentCoord(Coordonnees * pCoord);

/////////////////////////////////////////////////////////////////////////
//CALCULS////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

/**
	@brief Retourne la distance entre deux Coordonnees
	@param coord1 Coordonnees de la premier entitée
	@param coord2 Coordonnees de la seconde entitée
	@return float représentant la distance entre ses deux coordonnées
*/
float distanceEntreDeuxCoordonnees_Coord (Coordonnees * pCoord1, Coordonnees * pCoord2);

/**
	@brief Vérifie si deux Coordonnees donné sont identiques.
	@param coord1 Coordonnees de la premier entitée
	@param coord2 Coordonnees de la seconde entitée
	@return Retourne 1 si elles sont identique, 0 sinon
*/
int sontEgale_Coord (Coordonnees * pCoord1, Coordonnees * pCoord2);

///////////////////////////////////////////////////////////////////////////
//NON REGRESSION///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

/**
	@brief Fontion de test des fonctions du module Coordonnees
*/
void testFonctions_Coord();


#endif
