#include "SDL_events.h"
#include "SDL_log.h"
#include "stdio.h"
#include "wm.h"

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
        SDL_Window *window = windows[i];
        if (window != NULL)
        {
            SDL_DestroyWindow(window);
            windows[i] = NULL;
        }
    }
}

void wm_event_process(SDL_Event *event)
{
    static void wm_process_cnw_requests();
    static void wm_process_window_event(SDL_Window * window, SDL_WindowEvent * event);

    wm_process_cnw_requests();

    if (event->type == SDL_WINDOWEVENT)
    {
        for (Uint8 i = 0; i < MAX_WINDOWS; i++)
        {
            const Uint32 id = SDL_GetWindowID(windows[0]);
            if (id == 0)
            {
                SDL_LogError(SDL_LOG_PRIORITY_ERROR, "In processing an window event in Window Manager module, Failed to get Window ID. SDL Error: %s", SDL_GetError());
            }

            if (id == (event->window).windowID)
            {
                wm_process_window_event(windows[i], &(event->window));
                return;
            }
        }
    }
}

static void wm_process_cnw_requests()
{
}

static void wm_process_window_event(SDL_Window *window, SDL_WindowEvent *event)
{
    do
    {
        WM_CNW_Request wm_get_next_request();
        WM_CNW_Request request = wm_get_next_request();

        if (request.callback == NULL)
        {
            return;
        }

        static int wm_create_new_window(const char *, int, int, int, int, Uint32);
        int res = wm_create_new_window(
            request.title,
            request.x,
            request.y,
            request.w,
            request.h,
            request.flags);

        request.callback(res);

    } while (1);
}

static int wm_create_new_window(const char *title, int x, int y, int w, int h, Uint32 flags)
{
    for (int i = 0; i < MAX_WINDOWS; i++)
    {
        if (windows[i] == NULL)
        {
            windows[i] = SDL_CreateWindow(title, x, y, w, h, flags);
            return i;
        }
    }

    return -1;
}

// g
// g
