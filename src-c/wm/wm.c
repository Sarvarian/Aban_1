#include "SDL_events.h"
#include "SDL_log.h"
#include "stdio.h"
#define MAX_WINDOWS 8
static SDL_Window *windows[MAX_WINDOWS];

int wm_init()
{
    return 0;
}

void wm_exit()
{
    for (Uint8 i = 0; i < MAX_WINDOWS; i++)
    {
        SDL_WindowEvent *window = windows[i];
        if (window != NULL)
        {
            SDL_DestroyWindow(window);
            windows[i] = NULL;
        }
    }
}

void wm_close_window()
{
}

void wm_window_event(SDL_WindowEvent *event)
{
    static process_window_event(SDL_Window * window, SDL_Event * event);

    for (Uint8 i = 0; i < MAX_WINDOWS; i++)
    {
        const Uint32 id = SDL_GetWindowID(windows[0]);
        if (id == 0)
        {
            SDL_LogError(SDL_LOG_PRIORITY_ERROR, "In processing an window event in Window Manager module, Failed to get Window ID. SDL Error: %s", SDL_GetError());
        }

        if (id == event->windowID)
        {
            process_window_event(windows[i], event);
            return;
        }
    }
}

static process_window_event(SDL_Window *window, SDL_Event *event)
{
}