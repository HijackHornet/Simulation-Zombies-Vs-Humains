/**
   @file coordonnees.h
   @brief  Définit les coordonnées atomiques du terrain et ses accesseurs
*/

#ifndef _COORDONNEES
#define _COORDONNEES


/** @struct coordonnees
 *  @brief Structure definissant des coordonnees en deux dimension (pour des entitées)
 *  @var coordonnees::Xcord
 *  Position sur l'axe des X
  *  @var coordonnees::Ycord
 *  Position sur l'axe des Y
 */
typedef struct Mcoordonnees{
    int Xcord;
	int Ycord;
} coordonnees;


/**
	@brief Edition de XCord et de YCord dans la structure
	@param Xcord Valeur sur l'axe des x
	@param ycord Valeur sur l'axe des y
	@param laCord Pointeur sur la structure coordonnees a editer
*/
void setXYcord_Cord (int x, int y, coordonnees * laCord);
/**
	@brief Recupère Xcord
	@param laCord Pointeur sur la structure coordonnees a lire
	@return La valeur de Xcord
*/
int getXcord_Cord(coordonnees * laCord);
/**
	@brief Recupère Ycord
	@param laCord Pointeur sur la structure coordonnees a lire
	@return La valeur de Ycord
*/
int getYcord_Cord(coordonnees * laCord);

/**
	@brief Retourne la distance entre deux coordonnes
	@param cord1 Coordonnees de la premier entitée
	@param cord2 Coordonnees de la seconde entitée
	@return float représentant la distance entre ses deux coordonnées
*/
float distanceEntreDeuxCoordonnees_Cord (coordonnees * cord1, coordonnees * cord2);

/**
	@brief Vérifie si deux coordonnees donné sont identiques.
	@param cord1 Coordonnees de la premier entitée
	@param cord2 Coordonnees de la seconde entitée
	@return Retourne 1 si elles sont identique, 0 sinon
*/
int sontEgale_Cord (coordonnees * cord1, coordonnees * cord2);


#endif