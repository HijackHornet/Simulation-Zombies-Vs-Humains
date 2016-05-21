#ifndef _SIMULATION
#define _SIMULATION

#include <glib.h>

#include "terrain.h"
#include "personnage.h"


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
	@brief Recup�re le terrain associ� � une Simulation
	@param pSim La simulation a �tudier
	@return Pointeur vers le terrain r�cup�r�
*/
Terrain * getTerrain_sim(Simulation * pSim);

/**
	@brief Recup�re la grille de zombie associ� � une Simulation
	@param pSim La simulation a �tudier
	@return Pointeur vers la grille de zombies
*/
GArray * getZombies_sim(Simulation * pSim);
/**
	@brief Recup�re la grille de Citoyens associ� � une Simulation
	@param pSim La simulation a �tudier
	@return Pointeur vers la grille de Citoyens
*/
GArray * getCitoyens_sim(Simulation * pSim);
/**
	@brief Recup�re la grille de Policiers associ� � une Simulation
	@param pSim La simulation a �tudier
	@return Pointeur vers la grille de Policiers
*/
GArray * getPoliciers_sim(Simulation * pSim);
/**
	@brief Recup�re le nombre de zombie associ� � une Simulation
	@param pSim La simulation a �tudier
	@return Entier  du nombre de zombie dans la Simulation
*/

int getNbZombies_sim(Simulation * pSim);
/**
	@brief Recup�re le nombre de Citoyens associ� � une Simulation
	@param pSim La simulation a �tudier
	@return Entier  du nombre de Citoyens dans la Simulation
*/
int getNbCitoyens_sim(Simulation * pSim);
/**
	@brief Recup�re le nombre de Policiers associ� � une Simulation
	@param pSim La simulation a �tudier
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
	@brief Initialise la simulation avec le fichier de nom sp�cifi�
	@param nomFich Chaine de caract�re de nom du fichier
	@param pSim La simulation a initialiser
*/
void terrainInit_sim(char * nomFic, Simulation * pSim);
/**
	@brief Initialise la simulation avec le fichier de nom sp�cifi�, le nombre de zombies, de citoyens et de policier, en appelant les fonctions sp�cifiques
	@param pSim La simulation a initialiser
	@param nbZombies Nombres de zombies a initialiser dans la Simulation
	@param nbCitoyens Nombres de Citoyens a initialiser dans la Simulation
	@param nbPoliciers Nombres de Policiers a initialiser dans la Simulation
	@param nomFich Chaine de caract�re de nom du fichier
*/
void initSimulation_sim(Simulation * pSim, int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic);
/**
	@brief Creer la simulation avec le fichier de nom sp�cifi�, le nombre de zombies, de citoyens et de policier, en appelant les fonctions sp�cifiques, et l'initialise
	@param nbZombies Nombres de zombies a creer dans la Simulation
	@param nbCitoyens Nombres de Citoyens a creer dans la Simulation
	@param nbPoliciers Nombres de Policiers a creer dans la Simulation
	@param nomFich Chaine de caract�re de nom du fichier
	@return pSim Pointeur vers la Simulation cr�e
*/
Simulation * creerSimulation_sim(int nbZombies, int nbCitoyens, int nbPoliciers, char * nomFic);

///////////////////////////////////////////////////////////////////////////////
//EXECUTION////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/**
	@brief Executes les deplacement des policiers de mani�re al�atoire
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacerPoliciers_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des Citoyens de mani�re al�atoire
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacerCitoyens_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des Zombies de mani�re al�atoire
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacerZombies_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des personnages de mani�re al�atoire
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacerPerso_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des zombies de mani�re intelligente et en regard des champs
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacementIntelZombies_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des Citoyens de mani�re intelligente et en regard des champs
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacementIntelCitoyens_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des Policiers de mani�re intelligente et en regard des champs
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacementIntelPoliciers_sim(Simulation * pSim);
/**
	@brief Executes les deplacement des personnages de mani�re intelligente et en regard des champs
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacementIntelPersos(Simulation * pSim);

///////////////////////////////////////////////////////////////////////////////
//INTERACTIONS/////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
/**
	@brief Executes les instruction de contamination des policier et citoyens par les zombies
	@param pSim La simulation dans laquelle tout est effectu�
*/
void contaminations(Simulation * pSim);
/**
	@brief Executes les instruction de tirs des policiers sur les zombies
	@param pSim La simulation dans laquelle tout est effectu�
*/
void tirs(Simulation * pSim);

////////////////////////////////////////////////////////////////////////////
//CHAMPS////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
/**
	@brief Propage les champs des personnages dans la simulation
	@param pSim La simulation dans laquelle tout est effectu�
*/
void propagerChampsPersos(Simulation * pSim);
/**
	@brief Executes les instruction de deplacement intteligent d'un Zombie
	@param pPerso Pointeur vers l'entit� qui va etre d�plac� intelligement
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacementIntelZombie(Perso * pPerso, Simulation * pSim);
/**
	@brief Executes les instruction de deplacement intteligent d'un Citoyen
	@param pPerso Pointeur vers l'entit� qui va etre d�plac� intelligement
	@param pSim La simulation dans laquelle tout est effectu�
*/
void deplacementIntelCitoyen(Perso * pPerso, Simulation * pSim);
/**
	@brief Executes les instruction de deplacement intteligent d'un Policier
	@param pPerso Pointeur vers l'entit� qui va etre d�plac� intelligement
	@param pSim La simulation dans laquelle tout est effectu�
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
