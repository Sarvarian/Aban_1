#include "SDL_events.h"

// Belong to main module. other modules should not call this.
int wm_init();
// Belong to main module. other modules should not call this.
void wm_exit();
// Belong to main module. other modules should not call this.
void wm_event_process(SDL_Event *event);

// WARNING: Only call this in main thread. This routing is not thread safe.
int wm_create_new_window(const char *title, int x, int y, int w, int h, Uint32 flags);

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
// This routing is thread safe.
int wm_request_create_new_window(WM_CNW_Request information);

// g
// g
// G
// G
