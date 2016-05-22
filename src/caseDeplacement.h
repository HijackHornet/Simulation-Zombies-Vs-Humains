/**
   @file caseDeplacement.h
   @brief  Définit une case sur lesquels les personnages vont pouvoir se déplacer
*/

#ifndef _CASE_H
#define _CASE_H


#include "coordonnees.h"
#include "personnage.h"

/** env défini soit un mur soit le sol (vide) */
enum env {VIDE, MUR};
/** @struct MCaseDeplacement
 *  @brief Structure definissant les cases de déplacement (champs d'influences et environement)
 *  @var MCaseDeplacement::envCase
 *  Type de case, mur ou sol
 *	@var MCaseDeplacement::persoCase
 *  Pointeur vers un eventuel personnage sur la case
 *	@var MCaseDeplacement::champZombies[250]
 *  EUHHHHH JE COMPREND PAS
 *	@var MCaseDeplacement::champCitoyens[250]
 *  EUHHHHH JE COMPREND PAS
 *	@var MCaseDeplacement::champPoliciers[250]
 *  EUHHHHH JE COMPREND PAS
 */
typedef struct MCaseDeplacement{
    enum env envCase;
    struct MPerso * persoCase;
    short champZombies[250];
    short champCitoyens[250];
    short champPoliciers[250];
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

unsigned short getChamp(enum typePerso type, int idPerso, caseDeplacement * caseDep);

void setChamp(unsigned short intensite, enum typePerso type, int idPerso, caseDeplacement * caseDep);

void initChamps(int nbZombies, int nbCitoyens, int nbPoliciers, caseDeplacement * caseDep);

#endif
