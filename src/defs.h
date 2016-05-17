
#ifndef DEF_DEFS
#define DEF_DEFS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#ifdef _WIN32
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

#include "coordonnees.h"
#include "terrain.h"
#include "simulation.h"
//#include "simulation_ncurses.h"
#include "simulation_gtk.h"

// Taille de la fenêtre : 1030*500
#define SCREEN_WIDTH 1030 //1300
#define SCREEN_HEIGHT 500 //500
#define FULLSCREEN_WIDTH 1920 //1920
#define FULLSCREEN_HEIGHT 1080//1080
#define RENDERERSCALE 0.3 //0.3
#define FULLSCREEN_RENDERERSCALE 0.5//0.6
#define DELAYREFRESH 300 //300
#endif
