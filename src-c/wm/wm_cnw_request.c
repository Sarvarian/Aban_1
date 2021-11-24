#include "SDL_mutex.h"
#include "wm.h"

static SDL_mutex *wm_request_mutex = NULL;
void wm_request_lock()
{
    if (wm_request_mutex == NULL)
    {
        wm_request_mutex = SDL_CreateMutex();
    }

    SDL_LockMutex(wm_request_mutex);
}
void wm_request_unlock()
{
    if (wm_request_mutex != NULL)
    {
        SDL_UnlockMutex(wm_request_mutex);
    }
}

#define MAX_CNW_REQUESTS 8
static WM_CNW_Request requests[MAX_CNW_REQUESTS];

int wm_request_create_new_window(WM_CNW_Request information)
{
    int res = 1;
    wm_request_lock();

    for (int i = 0; i < MAX_CNW_REQUESTS; i++)
    {
        if (requests[i].callback == NULL)
        {
            requests[i] = information;
            res = 0;
            break;
        }
    }

    wm_request_unlock();
    return res;
}

WM_CNW_Request wm_get_next_request()
{
    WM_CNW_Request next_request = {0};
    wm_request_lock();

    for (int i = 0; i < MAX_CNW_REQUESTS; i++)
    {
        if (requests[i].callback != NULL)
        {
            next_request = requests[i];
            requests[i].callback = NULL;
            break;
        }
    }

    wm_request_unlock();
    return next_request;
}

// g
// g
