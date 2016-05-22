/**
   @file simulation_SDL2.h
   @brief  Définit les boucles de de la simulation sous SDL
*/
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
	@brief Fontion de gestion des Input pour la fenetre de l'éditeur
*/
void EventClavierEditeur(Terrain * pTerrain);


////////////////////////////////////////////////////////////////////
//EXECUTIONS////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

/**
	@brief Fait tourner toutes les phases de la simulation et lance les fontions d'affichage
	@param pSim Pointeur vers la simulation à lancer dans Sdl
*/
void lancerSimulationSDL2 (Simulation * pSim);
/**
	@brief Fait tourner les fonction de l'éditeur de niveau et lance les fonctions d'affichage de celui-ci
*/
void lancerSimulationSDL2Editeur();