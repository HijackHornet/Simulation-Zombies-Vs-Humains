#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "coordonnees.h"
#include "assert.h"
#include "time.h"

#include <stdlib.h>
#include <stdio.h>

enum typePerso {POLICIER, ZOMBIE, CITOYEN};

typedef struct MPerso {
    int id;
    Coordonnees * coord;
    enum typePerso type;
} Perso;

////////////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/**
	@brief Retourne des coordonn�es d'un personnage
	@param pPerso Personnage dont on veut les coordonn�es
	@return Un pointeur vers les coordonn�es du personnage
*/
Coordonnees * getCoordonneesPerso_perso(Perso * pPerso);
/**
	@brief Retourne les coordonn�es  X d'un personnage
	@param pPerso Personnage dont on veut les coordonn�es
	@return Un entier des coordonn�es en X
*/
int getXPerso_perso(Perso * pPerso);
/**
	@brief Retourne les coordonn�es  Y d'un personnage
	@param pPerso Personnage dont on veut les coordonn�es
	@return Un entier des coordonn�es en Y
*/
int getYPerso_perso(Perso * pPerso);
/**
	@brief Change les coordonn�es  X d'un personnage
	@param pPerso Personnage dont on veut changer les coordonn�es
	@param xPerso Un entier des coordonn�es en X � changer
*/
void setXPerso_perso(Perso * pPerso, int xPerso);
/**
	@brief Change les coordonn�es  Y d'un personnage
	@param pPerso Personnage dont on veut changer les coordonn�es
	@param yPerso Un entier des coordonn�es en Y � changer
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
	@brief Change les coordonn�es d'un personnage
	@param coord Pointeur vers des coordonn�es
	@param pPerso Personnage dont on veut changer les coordonn�es
*/
void setCoordPerso_perso(Coordonnees * coord, Perso * pPerso);
/**
	@brief Retourne l'Id d'un personnage point�
	@param pPerso Le personnage dont on veut l'ID
	@return L'ID sous forme d'entier
*/
int getIdPerso(Perso * pPerso);
/**
	@brief Change l'Id d'un personnage point�
	@param L'ID sous forme d'entier
	@param pPerso Le personnage dont on veut l'ID
*/
void setIdPerso(int idPerso, Perso * pPerso);


////////////////////////////////////////////////////////////////////////////
//CREATION PERSO////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
/**
	@brief Cr�er et initialise un personnage et renvoie un pointeur vers lui
	@param coord Pointeur vers les coordonn�es du personnage a creer
	@param type Type du personnage
	@param idPerso L'ID du personnage a creer
	@return Pointeur vers le personnage cr�e
	
*/
Perso * initPerso(Coordonnees * coord, enum typePerso typePerso, int idPerso);
/**
	@brief Detruit le personnage point� et lib�re la m�moire
	@param pPerso Pointeur vers le personnage a d�truire et liberer
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
