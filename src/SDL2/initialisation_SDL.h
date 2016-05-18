#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 1035 //1035
#define SCREEN_HEIGHT 495 //495
#define RENDERERSCALE 0.3 //0.3
#define FULLSCREEN_WIDTH 1920 //1300
#define FULLSCREEN_HEIGHT 1080 //500
#define FULLSCREEN_RENDERERSCALE 0.5 //0.5
#define DELAYREFRESH 300 //300

////////////////////////////////////////////////////////////////////
//ACCESSEUR  ///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
/**
	@brief Recupère le renderer actuellement utilisé
	@return Pointeur vers le SDL_Renderer utilisé
*/
SDL_Renderer *getrenderer();


////////////////////////////////////////////////////////////////////
//INITIALISATION ET LIBERATION  ////////////////////////////////////
////////////////////////////////////////////////////////////////////

/**
	@brief Initilialise une fenetre avec le nom donné et les dimension définie dans le define pour la fenetre de simulation
	@param title Chaine de caractères du nom de la fenetre a initiliser
*/
void init(char *title);
/**
	@brief Initilialise une fenetre avec le nom donné et les dimension définie dans le define pour la fenetre de l'editeur
	@param title Chaine de caractères du nom de la fenetre a initiliser
*/
void initEditeur(char *title);
/**
	@brief Detruit la fenetre, le rendu et ferme SDL
*/
void cleanup();

