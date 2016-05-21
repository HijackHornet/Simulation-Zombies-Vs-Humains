#include <SDL.h>
#include <SDL_image.h>

#include "../simulation.h"
#include "initialisation_SDL.h"

void delay(unsigned int frameLimit);
SDL_Texture *loadImage(char *name);
/**
	@brief Dessine la SDL_Texture au coordon�e XY
	@param image Pointeur vers la SDL_texture a dessiner
	@param x Coordonn�es en X ou dessiner
	@param y Coordonn�es en Y ou dessiner
*/
void drawImage(SDL_Texture *image, int x, int y); 
/**
	@brief Dessine les personnage de la simulation sur la fenetre
	@param pSim Pointeur vers la simulation � afficher
*/
void afficherParamFenetre(Simulation * pSim);
/**
	@brief Dessine le terrain de la simulation sur la fenetre
	@param pSim Pointeur vers la simulation � afficher
*/
void affichageFenetre(Simulation * pSim);
/**
	@brief Dessine le terrain  vierge pour l'editeur sur la fenetre
*/
void affichageFenetreEditeur();


