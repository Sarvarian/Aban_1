#include "SDL_thread.h"
#include "SDL_log.h"
#include "main.h"
#include "wm.h"

static struct InitialData
{
    Uint8 window_index;
} initial_data = {0};

static SDL_Thread *rtp_hThread = NULL;
static char rtp_should_exit = 0;

int rtp_init()
{
    int res = wm_create_new_window(
        "First Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 480,
        SDL_WINDOW_SHOWN);
    if (res == -1)
    {
        main_fatal_error_msg = SDL_GetError();
        return 1;
    }
    else
    {
        initial_data.window_index = res;
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
