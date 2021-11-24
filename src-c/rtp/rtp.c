#include "SDL_thread.h"
#include "SDL_log.h"
#include "main.h"
#include "wm.h"

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
    SDL_Log("Hello!");

    void rtp_cnw_request_callback(int result);
    WM_CNW_Request info = {
        &rtp_cnw_request_callback,
        "My Window",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        600,
        800,
        SDL_WINDOW_SHOWN,
    };
    wm_request_create_new_window(info);
    // main_exit_application();
    return 0;
}

void rtp_cnw_request_callback(int result)
{
    SDL_Log("Create New Window Request Result: %d", result);
}

// g
// g
