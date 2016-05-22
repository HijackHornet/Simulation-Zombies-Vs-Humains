#include <SDL.h>
#include <SDL_image.h>
#include "../simulation.h"

#define RENDERERSCALE 0.3 //0.3
#define DELAYREFRESH 300 //300

////////////////////////////////////////////////////////////////////
//ACCESSEUR  ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
/**
	@brief Recup�re le renderer actuellement utilis�
	@return Pointeur vers le SDL_Renderer utilis�
*/
SDL_Renderer *getrenderer();


////////////////////////////////////////////////////////////////////
//INITIALISATION ET LIBERATION  ////////////////////////////////////
////////////////////////////////////////////////////////////////////

/**
	@brief Initilialise une fenetre avec le nom donn� et les dimension d�finie dans le define pour la fenetre de simulation
	@param title Chaine de caract�res du nom de la fenetre a initiliser
	@param pSim Pointeur vers la simulation
*/
void init(char *title,Simulation * pSim);
/**
	@brief Initilialise une fenetre avec le nom donn� et les dimension d�finie dans le define pour la fenetre de l'editeur
	@param title Chaine de caract�res du nom de la fenetre a initiliser
	@param pTerrain Pointeur vers le terrain � afficher
*/
void initEditeur(char *title, Terrain * pTerrain);
/**
	@brief Detruit la fenetre, le rendu et ferme SDL
*/
void cleanup();

