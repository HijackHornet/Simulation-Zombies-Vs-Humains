/**
   @file personnage.h
   @brief  Définit les type de personnage et leurs accesseurs
*/
#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "coordonnees.h"
#include "assert.h"
#include "time.h"

#include <stdlib.h>
#include <stdio.h>
/** Les différents type de personnages */
enum typePerso {POLICIER, ZOMBIE, CITOYEN};
/** @struct MPerso
 *  @brief Structure definissant un personnage et ses attributs
 *  @var MPerso::id
 *	id D'un personnage servant à l'identifier
 *	@var MPerso::coord
 *	Coordonnées associé à se personnage
 *	@var MPerso::type
 *	Type du personnage zombie,citoyen ou humain
 */
typedef struct MPerso {
    int id;
    Coordonnees * pCoord;
    enum typePerso type;
} Perso;

////////////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/**
	@brief Retourne des coordonnées d'un personnage
	@param pPerso Personnage dont on veut les coordonnées
	@return Un pointeur vers les coordonnées du personnage
*/
Coordonnees * getCoordonneesPerso_perso(Perso * pPerso);
/**
	@brief Retourne les coordonnées  X d'un personnage
	@param pPerso Personnage dont on veut les coordonnées
	@return Un entier des coordonnées en X
*/
int getXPerso_perso(Perso * pPerso);
/**
	@brief Retourne les coordonnées  Y d'un personnage
	@param pPerso Personnage dont on veut les coordonnées
	@return Un entier des coordonnées en Y
*/
int getYPerso_perso(Perso * pPerso);
/**
	@brief Change les coordonnées  X d'un personnage
	@param pPerso Personnage dont on veut changer les coordonnées
	@param xPerso Un entier des coordonnées en X à changer
*/
void setXPerso_perso(Perso * pPerso, int xPerso);
/**
	@brief Change les coordonnées  Y d'un personnage
	@param pPerso Personnage dont on veut changer les coordonnées
	@param yPerso Un entier des coordonnées en Y à changer
*/
void setYPerso_perso(Perso * pPerso, int yPerso);

Coordonnees * getCoordPerso(Perso * pPerso);

/**
	@brief Retourne le type de personnage d'un perso
	@param pPerso Personnage dont on veut le type
	@return Un enum qui dit le type du perso (zombie, citoyen, policier)
*/
enum typePerso getTypePerso(Perso * pPerso);
/**
	@brief Change le type de personnage d'un perso
	@param type Un enum qui dit le type du perso (zombie, citoyen, policier)
	@param pPerso Personnage dont on veut changer le type
*/
void setTypePerso_perso(enum typePerso type, Perso * pPerso);
/**
	@brief Change les coordonnées d'un personnage
	@param pCoord Pointeur vers des coordonnées
	@param pPerso Personnage dont on veut changer les coordonnées
*/
void setCoordPerso_perso(Coordonnees * pCoord, Perso * pPerso);
/**
	@brief Retourne l'Id d'un personnage pointé
	@param pPerso Le personnage dont on veut l'ID
	@return L'ID sous forme d'entier
*/
int getIdPerso(Perso * pPerso);
/**
	@brief Change l'Id d'un personnage pointé
	@param L'ID sous forme d'entier
	@param pPerso Le personnage dont on veut l'ID
*/
void setIdPerso(int idPerso, Perso * pPerso);


////////////////////////////////////////////////////////////////////////////
//CREATION PERSO////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/**
	@brief Créer et initialise un personnage et renvoie un pointeur vers lui
	@param pCoord Pointeur vers les coordonnées du personnage a creer
	@param type Type du personnage
	@param idPerso L'ID du personnage a creer
	@return Pointeur vers le personnage créé
	
*/
Perso * initPerso(Coordonnees * pCoord, enum typePerso typePerso, int idPerso);
/**
	@brief Detruit le personnage pointé et libère la mémoire
	@param pPerso Pointeur vers le personnage a détruire et liberer
*/
void testamentPerso(Perso * pPerso);

////////////////////////////////////////////////////////////////////////////
//NON REGRESSION////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/**
	@brief Fontion de test des fonctions du module Personnage
*/
void testFonctions_perso();

#endif
