#include "../simulation.h"
#include "initialisation_SDL.h"
#include "affichage_SDL.h"

////////////////////////////////////////////////////////////////////
//INPUTS  //////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

/**
	@brief Fontion de gestion des Input pour la fenetre de simulation
*/
void EventClavier();
/**
	@brief Fontion de gestion des Input pour la fenetre de l'�diteur
*/
void EventClavierEditeur(Terrain * pTerrain);


////////////////////////////////////////////////////////////////////
//EXECUTIONS////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

/**
	@brief Fait tourner toutes les phases de la simulation et lance les fontions d'affichage
	@param pSim Pointeur vers la simulation � lancer dans Sdl
*/
void lancerSimulationSDL2 (Simulation * pSim);
/**
	@brief Fait tourner les fonction de l'�diteur de niveau et lance les fonctions d'affichage de celui-ci
*/
void lancerSimulationSDL2Editeur();