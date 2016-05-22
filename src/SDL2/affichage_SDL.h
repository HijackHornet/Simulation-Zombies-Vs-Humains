/**
   @file affichage_SDL.h
   @brief  Définit les fonctions d'affichage SDL
*/
#include <SDL.h>
#include <SDL_image.h>

#include "../simulation.h"
#include "initialisation_SDL.h"

void delay(unsigned int frameLimit);
SDL_Texture *loadImage(char *name);
/**
	@brief Dessine la SDL_Texture au coordonée XY
	@param image Pointeur vers la SDL_texture a dessiner
	@param x Coordonnées en X ou dessiner
	@param y Coordonnées en Y ou dessiner
*/
void drawImage(SDL_Texture *image, int x, int y); 
/**
	@brief Dessine les personnage de la simulation sur la fenetre
	@param pSim Pointeur vers la simulation à afficher
*/
void afficherParamFenetre(Simulation * pSim);
/**
	@brief Dessine le terrain de la simulation sur la fenetre
	@param pSim Pointeur vers la simulation à afficher
*/
void affichageFenetre(Simulation * pSim);
/**
	@brief Dessine le terrain  vierge pour l'editeur sur la fenetre
*/
void affichageFenetreEditeur();


