
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
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#endif

#include "coordonnees.h"
#include "terrain.h"
#include "simulation.h"
#include "simulation_ncurses.h"
#include "simulation_gtk.h"

// Taille de la fenêtre : 800x480 pixels
#define SCREEN_WIDTH 1030 //1300
#define SCREEN_HEIGHT 500 //500
#define RENDERERSCALE 0.3 //0.3
#define DELAYREFRESH 300 //300
#endif
