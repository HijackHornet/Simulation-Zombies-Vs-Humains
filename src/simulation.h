/**
   @file simulation.h
   @brief  Définit la simulation, ses parametres et ses accesseurs
*/
#ifndef _SIMULATION
#define _SIMULATION

#include <glib.h>

#include "terrain.h"
#include "personnage.h"

/** @struct MSimulation
 *	@brief Structure definissant une simulation et ses attributs
 *	@var MSimulation::pTerrain
 *	Pointeur vers un terrain associé à la simulation
 *	@var MSimulation::nbZombies
 *	Nombres de Zombies
 *	@var MSimulation::nbCitoyens
 *	Nombre de citoyens
 *	@var MSimulation::nbPoliciers
 *	Nombre de policiers
 *	@var MSimulation::zombies
 *	Tableau des zombies
 *	@var MSimulation::citoyens
 *	Tableau des citoyens
 *	@var MSimulation::policiers
 *	Tableau des policiers
 */
typedef struct MSimulation{
    Terrain * pTerrain;
    int nbZombies;
    int nbCitoyens;
    int nbPoliciers;
    GArray *  zombies;
    GArray * citoyens;
    GArray * policiers;
} Simulation;

////////////////////////////////////////////////////////////////////
//ACCESSEURS////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
/**
	@brief Recupère le terrain associé à une Simulation
	@param pSim La simulation a étudier
	@return Pointeur vers le terrain récupéré
*/
Terrain * getTerrain_sim(Simulation * pSim);

/**
	@brief Recupère la grille de zombie associé à une Simulation
	@param pSim La simulation a étudier
	@return Pointeur vers la grille de zombies
*/
GArray * getZombies_sim(Simulation * pSim);
/**
	@brief Recupère la grille de Citoyens associé à une Simulation
	@param pSim La simulation a étudier
	@return Pointeur vers la grille de Citoyens
*/
GArray * getCitoyens_sim(Simulation * pSim);
/**
	@brief Recupère la grille de Policiers associé à une Simulation
	@param pSim La simulation a étudier
	@return Pointeur vers la grille de Policiers
*/
GArray * getPoliciers_sim(Simulation * pSim);
/**
	@brief Recupère le nombre de zombie associé à une Simulation
	@param pSim La simulation a étudier
	@return Entier  du nombre de zombie dans la Simulation
*/

int getNbZombies_sim(Simulation * pSim);
/**
	@brief Recupère le nombre de Citoyens associé à une Simulation
	@param pSim La simulation a étudier
	@return Entier  du nombre de Citoyens dans la Simulation
*/
int getNbCitoyens_sim(Simulation * pSim);
/**
	@brief Recupère le nombre de Policiers associé à une Simulation
	@param pSim La simulation a étudier
	@return Entier  du nombre de Policiers dans la Simulation
*/
int getNbPoliciers_sim(Simulation * pSim);

////////////////////////////////////////////////////////////////////
//CREATION-INITALISATION////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
/**
	@brief Initialise la simulation avec un nombre de zombies
	@param nbZombies Nombres de zombies a initialiser dans la Simulation
	@param pSim La simulation a initialiser
*/
void zombiesInit_sim(int nbZombies, Simulation * pSim);
/**
	@brief Initialise la simulation avec un nombre de Citoyens
	@param nbCitoyens Nombres de Citoyens a initialiser dans la Simulation
	@param pSim La simulation a initialiser
*/
void citoyensInit_sim(int nbCitoyens, Simulation * pSim);
/**
	@brief Initialise la simulation avec un nombre de Policier
	@param nbPoliciers Nombres de Policiers a initialiser dans la Simulation
	@param pSim La simulation a initialiser
*/
void policiersInit_sim(int nbPoliciers, Simulation * pSim);
/**
	@brief Initialise la simulation avec le fichier de nom spécifié
	@param nomFic Chaine de caractère de nom du fichier
	@param pSim La simulation a initialiser
*/
void terrainInit_sim(char * nomFic, Simulation * pSim);
/**
	@brief Initialise la simulation avec le fichier de nom spécifié, le nombre de zombies, de citoyens et de policier, en appelant les fonctions spécifiques
	@param pSim La simulation a initialiser
	@param nbZombies Nombres de zombies a initialiser dans la Simulation
	@param nbCitoyens Nombres de Citoyens a initialiser dans la Simulation
	@param nbPoliciers Nombres de Policiers a initialiser dans la Simulation
	@param nomFic Chaine de caractère de nom du fichier
*/
void initSimulation_sim(Simulation * pSim, int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic);
/**
	@brief Creer la simulation avec le fichier de nom spécifié, le nombre de zombies, de citoyens et de policier, en appelant les fonctions spécifiques, et l'initialise
	@param nbZombies Nombres de zombies a creer dans la Simulation
	@param nbCitoyens Nombres de Citoyens a creer dans la Simulation
	@param nbPoliciers Nombres de Policiers a creer dans la Simulation
	@param nomFic Chaine de caractère de nom du fichier
	@return pSim Pointeur vers la Simulation crée
*/
Simulation * creerSimulation_sim(int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic);

///////////////////////////////////////////////////////////////////////////////
//EXECUTION////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/**
	@brief Executes les deplacement des policiers de manière aléatoire
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacerPoliciers_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des Citoyens de manière aléatoire
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacerCitoyens_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des Zombies de manière aléatoire
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacerZombies_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des personnages de manière aléatoire
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacerPerso_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des zombies de manière intelligente et en regard des champs
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacementIntelZombies_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des Citoyens de manière intelligente et en regard des champs
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacementIntelCitoyens_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des Policiers de manière intelligente et en regard des champs
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacementIntelPoliciers_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des personnages de manière intelligente et en regard des champs
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacementIntelPersos(Simulation * pSim);

///////////////////////////////////////////////////////////////////////////////
//INTERACTIONS/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/**
	@brief Executes les instruction de contamination des policier et citoyens par les zombies
	@param pSim La simulation dans laquelle tout est effectué
*/
void contaminations(Simulation * pSim);
/**
	@brief Executes les instruction de tirs des policiers sur les zombies
	@param pSim La simulation dans laquelle tout est effectué
*/
void tirs(Simulation * pSim);

////////////////////////////////////////////////////////////////////////////
//CHAMPS////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
/**
	@brief Propage les champs des personnages dans la simulation
	@param pSim La simulation dans laquelle tout est effectué
*/
void propagerChampsPersos(Simulation * pSim);
/**
	@brief Executes les instruction de deplacement intteligent d'un Zombie
	@param pPerso Pointeur vers l'entité qui va etre déplacé intelligement
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacementIntelZombie(Perso * pPerso, Simulation * pSim);
/**
	@brief Executes les instruction de deplacement intteligent d'un Citoyen
	@param pPerso Pointeur vers l'entité qui va etre déplacé intelligement
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacementIntelCitoyen(Perso * pPerso, Simulation * pSim);
/**
	@brief Executes les instruction de deplacement intteligent d'un Policier
	@param pPerso Pointeur vers l'entité qui va etre déplacé intelligement
	@param pSim La simulation dans laquelle tout est effectué
*/
void deplacementIntelPolicier(Perso * pPerso, Simulation * pSim);

void supprimerCitoyen(Perso * pCitoyen, Simulation * pSim);

///////////////////////////////////////////////////////////////////////////////
//TEST/////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/**
	@brief Focntions de test des fonctions du module Simulation
*/
void testFonctions_sim();

////////////////////////////////////////////////////////////////////////////
//AUTRES////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
int compareTab2D(const void * a, const void * b);

void ajouterPerso(Coordonnees * pCoord, enum typePerso type, Simulation * pSim);

void contaminations(Simulation * pSim);

void supprimerPerso(Perso * pPerso, Simulation * pSim);

#endif
