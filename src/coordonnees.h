/**
   @file coordonnes.h
   @brief  Définit les coordonnées atomiques du terrain et ses accesseurs
*/

#ifndef _COORDONNEES
#define _COORDONNEES


/** @struct Coordonnes
 *  @brief Structure definissant des coordonnees en deux dimension (pour des entitées)
 *  @var coordonnees::xCoord
 *  Position sur l'axe des X
  * @var coordonnees::yCoord
 *  Position sur l'axe des Y
 */
typedef struct Mcoordonnees{
    int xCoord;
    int yCoord;
} Coordonnees;


///////////////////////////////////////////////////////////////////////
//ACCESSEURS///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

void setXCoord_Coord(int x, Coordonnees * pCoord);

void setYCoord_Coord(int y, Coordonnees * pCoord);

/**
	@brief Edition de xCoord et de yCoord dans la structure
	@param xCoord Valeur sur l'axe des x
	@param yCoord Valeur sur l'axe des y
	@param pCoord Pointeur sur la structure Coordonnees a editer
*/
void setXYCoord_Coord (int x, int y, Coordonnees * pCoord);
/**
	@brief Recupère xCoord
	@param pCoord Pointeur sur la structure Coordonnees a lire
	@return La valeur de xCoord
*/
int getXCoord_Coord(Coordonnees * pCoord);
/**
	@brief Recupère yCoord
	@param pCoord Pointeur sur la structure Coordonnees a lire
	@return La valeur de YCoord
*/
int getYCoord_Coord(Coordonnees * pCoord);

Coordonnees getCoordCaseBasByXY_terr(int x, int y);

Coordonnees getCoordCaseDroiteByXY_terr(int x, int y);

Coordonnees getCoordCaseGaucheByXY_terr(int x, int y);

Coordonnees getCoordCaseHautByXY_terr(int x, int y);

Coordonnees getCoordCaseBasByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCaseHautByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCaseGaucheByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCaseDroiteByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCase2DroiteByXY_terr(int x, int y);

Coordonnees getCoordCase2GaucheByXY_terr(int x, int y);

Coordonnees getCoordCase2HautByXY_terr(int x, int y);

Coordonnees getCoordCase2BasByXY_terr(int x, int y);

Coordonnees getCoordCaseHDByXY_terr(int x, int y);

Coordonnees getCoordCaseBDByXY_terr(int x, int y);

Coordonnees getCoordCaseBGByXY_terr(int x, int y);

Coordonnees getCoordCaseHGByXY_terr(int x, int y);

Coordonnees getCoordCaseBasByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCaseDroiteByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCaseGaucheByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCase2BasByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCase2HautByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCase2DroiteByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCase2GaucheByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCaseHDByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCaseBDByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCaseBGByCoord_terr(Coordonnees * coord);

Coordonnees getCoordCaseHGByCoord_terr(Coordonnees * coord);

/////////////////////////////////////////////////////////////////////////
//INITIALISATIONS-TESTAMENTS/////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

Coordonnees * initCoordonnees_coord(int x, int y);

void testamentCoord(Coordonnees * coord);

/////////////////////////////////////////////////////////////////////////
//CALCULS////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/**
	@brief Retourne la distance entre deux Coordonnees
	@param coord1 Coordonnees de la premier entitée
	@param coord2 Coordonnees de la seconde entitée
	@return float représentant la distance entre ses deux coordonnées
*/
float distanceEntreDeuxCoordonnees_Coord (Coordonnees * coord1, Coordonnees * coord2);

/**
	@brief Vérifie si deux Coordonnees donné sont identiques.
	@param coord1 Coordonnees de la premier entitée
	@param coord2 Coordonnees de la seconde entitée
	@return Retourne 1 si elles sont identique, 0 sinon
*/
int sontEgale_Coord (Coordonnees * coord1, Coordonnees * coord2);

/**
	@brief Teste le module coordonnees et ses fonctions
*/

///////////////////////////////////////////////////////////////////////////
//TESTS////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////


void testFonctions_Coord();


#endif
