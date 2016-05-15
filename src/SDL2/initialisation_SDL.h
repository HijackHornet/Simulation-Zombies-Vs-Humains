#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 1030 //1300
#define SCREEN_HEIGHT 500 //500
#define RENDERERSCALE 0.3 //0.3
#define DELAYREFRESH 300 //300

void init(char *title);
void cleanup();
SDL_Renderer *getrenderer(void);
