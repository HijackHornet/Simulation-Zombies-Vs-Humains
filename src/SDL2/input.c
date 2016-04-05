#include "../defs.h"
#include "input.h"

void getInput(Input *input)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {

            case SDL_QUIT:
                exit(0);
            break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;

                    case SDLK_LEFT:
                        input->left_key = 1;
                    break;

                    case SDLK_RIGHT:
                        input->right_key = 1;
                    break;

                    case SDLK_DOWN:
                        input->down_key = 1;
                    break;

                    case SDLK_UP:
                        input->up_key = 1;
                    break;

                    case SDLK_RETURN:
                        input->return_key = 1;
                    break;


                    default:
                    break;
                }
            break;

            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        exit(0);
                    break;

                    case SDLK_LEFT:
                        input->left_key = 0;
                    break;

                    case SDLK_RIGHT:
                        input->right_key = 0;
                    break;

                    case SDLK_DOWN:
                        input->down_key = 0;
                    break;

                    case SDLK_UP:
                        input->up_key = 0;
                    break;

                    case SDLK_RETURN:
                        input->return_key = 0;
                    break;


                    default:
                    break;
                }
            break;

        }

    }
}
