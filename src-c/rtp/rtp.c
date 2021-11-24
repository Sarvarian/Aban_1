#include "SDL_thread.h"

static SDL_Thread *rtp_hThread = NULL;
static char rtp_should_exit = 0;

int rtp_init()
{
    static int rtp_main(void *);
    rtp_hThread = SDL_CreateThread(rtp_main, "Real-Time-Process", NULL);
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