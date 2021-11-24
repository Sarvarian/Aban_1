#include "SDL_thread.h"
#include "SDL_video.h"
#include "main.h"

static SDL_Thread *rtp_hThread = NULL;
static char rtp_should_exit = 0;
static SDL_Window *window = NULL;

int rtp_init()
{
    window = SDL_CreateWindow(
        "First Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        main_fatal_error_msg = SDL_GetError();
        return 1;
    }

    static int rtp_main(void *);
    rtp_hThread = SDL_CreateThread(rtp_main, "Real-Time-Process", NULL);
    if (rtp_hThread == NULL)
    {
        main_fatal_error_msg = SDL_GetError();
        return 1;
    }
    return 0;
}

void rtp_exit()
{
    rtp_should_exit = 1;
    int status = 0;
    SDL_WaitThread(rtp_hThread, &status);
}

static int rtp_main(void *_data)
{
    return 0;
}

// g
// g
// G
// G
