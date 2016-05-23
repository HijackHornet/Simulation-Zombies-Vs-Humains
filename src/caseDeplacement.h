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
typedef enum env env;
/** @struct MCaseDeplacement
 *  @brief Structure definissant les cases de déplacement (champs d'influences et environement)
 *  @var MCaseDeplacement::envCase
 *  Type de case, mur ou sol
 *	@var MCaseDeplacement::persoCase
 *  Pointeur vers un eventuel personnage sur la case
 *	@var MCaseDeplacement::champZombies[250]
 *  Champs des zombies présents sur le terrain en cette case
 *	@var MCaseDeplacement::champCitoyens[250]
 *  Champs des citoyens présents sur le terrain en cette case
 *	@var MCaseDeplacement::champPoliciers[250]
 *  Champs des policiers présents sur le terrain en cette case
 */
typedef struct MCaseDeplacement{
    env envCase;
    struct MPerso * persoCase;
    unsigned short champZombies[250];
    unsigned short champCitoyens[250];
    unsigned short champPoliciers[250];
} caseDeplacement;

////////////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////

/**
	@brief Recupère le type de case d'une case de deplacement
	@param pCaseDep Pointeur sur la case de déplacement à étudier
	@return Le type de case
*/
enum env getEnvCase(caseDeplacement * pCaseDep);
/**
	@brief Recupère le personnage sur la case de déplacement
	@param pCaseDep Pointeur sur la case de déplacement à étudier
	@return Pointeur vers le personnage sur la case de déplacement
*/
Perso * getPersoCase(caseDeplacement * pCaseDep);
/**
	@brief Modifie le type de case d'une case de deplacement
	@param pCaseDep Pointeur sur la case de déplacement à étudier
	@param valeurEnv Le type de case
*/
void setEnvCase(caseDeplacement * pCaseDep, enum env valeurEnv);
/**
	@brief Modifie le personnage sur la case de déplacement
	@param pCaseDep Pointeur sur la case de déplacement à étudier
	@param pPerso Pointeur vers le personnage a mettre sur la case de déplacement
*/
void setPersoCase(caseDeplacement * pCaseDep, Perso * pPerso);
/**
	@brief Crée et initialise une case de deplacement avec un type de case et un personnage dessus
	@param envCase Type de case
	@param pPerso Pointeur vers un personnage
	@return Pointeur vers cette case de deplacement
*/
caseDeplacement * initCase(enum env envCase, Perso * pPerso);
/**
	@brief Récupère la valeur du champ du perso défini par son type et son id sur une case
	@param type Type du perso (ZOMBIE, POLICIER, CITOYEN)
	@param idPerso Id du perso dont on veut connaitre le champ
	@param pCaseDep Pointeur vers la case a detruire et liberer
*/
unsigned short getChamp(enum typePerso type, int idPerso, caseDeplacement * pCaseDep);

/**
	@brief Définit la valeur du champ du perso défini par son type et son id sur une case
	@param intensite La valeur du champs en pCaseDep
	@param type Type du perso (ZOMBIE, POLICIER, CITOYEN)
	@param idPerso Id du perso dont on veut connaitre le champ
	@param pCaseDep Pointeur vers la case a detruire et liberer
*/
void setChamp(unsigned short intensite, enum typePerso type, int idPerso, caseDeplacement * pCaseDep);


//void initChamps(int nbZombies, int nbCitoyens, int nbPoliciers, caseDeplacement * caseDep);

#endif
