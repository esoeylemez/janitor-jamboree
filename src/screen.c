/** @file screen.c
 * @ingroup   Screen
 * @defgroup  Screen
 * @brief     Screen/Window handler.
 * @author    Michael Fitzmayer
 * @copyright "THE BEER-WARE LICENCE" (Revision 42)
 */

#include "screen.h"

/**
 * @brief   
 * @param   width
 * @param   height
 * @param   fullscreen
 * @param   title
 * @return  
 * @ingroup Screen
 */
Screen *screenInit()
{
    static Screen *screen;
    screen = malloc(sizeof(struct ScreenType));

    if (-1 == SDL_Init(SDL_INIT_VIDEO))
    {
        fprintf(stderr, "Couldn't initialise SDL: %s\n", SDL_GetError());
        return NULL;
    }

    uint32_t flags = 0;
    if (SCREEN_FULLSCREEN) flags = SDL_WINDOW_FULLSCREEN;

    screen->window = SDL_CreateWindow(
        "Janitor Jamboree",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH,
        SCREEN_HEIGHT,
        flags);

    if (NULL == screen->window)
    {
        fprintf(stderr, "Couldn't set video mode: %s\n", SDL_GetError());
        return NULL;
    }

    return screen;
}

/**
 * @brief   
 * @param   screen
 * @ingroup Screen
 */
void screenTerminate(Screen *screen)
{
    SDL_DestroyWindow(screen->window);
    SDL_Quit();
}
