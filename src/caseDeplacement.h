/**
   @file caseDeplacement.h
   @brief  Définit une case sur lesquels les personnages vont pouvoir se déplacer
*/

#ifndef _CASE_H
#define _CASE_H


#include "coordonnees.h"
#include "personnage.h"


enum env {VIDE, MUR};

typedef struct McaseDeplacement{
    enum env envCase;
    struct MPerso * persoCase;
    short champZombies[250];
    short champCitoyens[250];
    short champPoliciers[250];
    char marqueur;
} caseDeplacement;

////////////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/**
	@brief Recupère le type de case d'une case de deplacement
	@param caseDep Pointeur sur la case de déplacement à étudier
	@return Le type de case
*/
enum env getEnvCase(caseDeplacement * caseDep);
/**
	@brief Recupère le personnage sur la case de déplacement
	@param caseDep Pointeur sur la case de déplacement à étudier
	@return Pointeur vers le personnage sur la case de déplacement
*/
Perso * getPersoCase(caseDeplacement * caseDep);
/**
	@brief Modifie le type de case d'une case de deplacement
	@param caseDep Pointeur sur la case de déplacement à étudier
	@param valeurEnv Le type de case
*/
void setEnvCase(caseDeplacement * caseDep, enum env valeurEnv);
/**
	@brief Modifie le personnage sur la case de déplacement
	@param caseDep Pointeur sur la case de déplacement à étudier
	@param pPerso Pointeur vers le personnage a mettre sur la case de déplacement
*/
void setPersoCase(caseDeplacement * caseDep, Perso * pPerso);
/**
	@brief Crée et initialise une case de deplacement avec un type de case et un personnage dessus
	@param envCase Type de case
	@param pPerso Pointeur vers un personnage
	@return Pointeur vers cette case de deplacement
*/
caseDeplacement * initCase(enum env envCase, Perso * pPerso);
/**
	@brief Détruit et libère une case de deplacement
	@param caseDep Pointeur vers la case a detruire et liberer
*/
void testamentCase(caseDeplacement * caseDep);
/**
	@brief Change la valeur du marqueur de champ de la case de deplacement
	@param valeur valeur du marqueur
	@param caseDep Pointeur vers la case de deplacement a modifier
*/
void setMarqueur(char valeur, caseDeplacement * caseDep);

unsigned short getChamp(enum typePerso type, int idPerso, caseDeplacement * caseDep);

void setChamp(unsigned short intensite, enum typePerso type, int idPerso, caseDeplacement * caseDep);

#endif
