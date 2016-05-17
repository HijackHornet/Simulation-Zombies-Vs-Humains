#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 1035 //1300
#define SCREEN_HEIGHT 495 //500
#define RENDERERSCALE 0.3 //0.3
#define FULLSCREEN_WIDTH 1920 //1300
#define FULLSCREEN_HEIGHT 1080 //500
#define FULLSCREEN_RENDERERSCALE 0.5 //0.3
#define DELAYREFRESH 300 //300

void init(char *title);
void initEditeur(char *title);
void cleanup();
SDL_Renderer *getrenderer(void);
