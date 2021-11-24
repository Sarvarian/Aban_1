#include "SDL_events.h"

int wm_init();
void wm_exit();
void wm_event_process(SDL_Event *event);

typedef struct WM_CNW_Request
{
    // Result wold be -1 if failed and a positive number as 'Window Manager' index of window.
    void (*callback)(int result);
    const char *title;
    int x;
    int y;
    int w;
    int h;
    Uint32 flags;
} WM_CNW_Request;

// Return 0 on success and 1 on failed. There is a limit to active requests.
int wm_request_create_new_window(WM_CNW_Request information);

// g
// g
