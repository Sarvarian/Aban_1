#include "SDL_events.h"
#include "SDL_log.h"
#include "wm.h"
#include "main.h"

#define MAX_WINDOWS 8

static int wm_create_new_window(const char *, int, int, int, int, Uint32);

static SDL_Window *windows[MAX_WINDOWS];

int wm_init()
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
            if (windows[i] == NULL)
            {
                continue;
            }

            const Uint32 id = SDL_GetWindowID(windows[i]);
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
    do
    {
        WM_CNW_Request wm_get_next_request();
        WM_CNW_Request request = wm_get_next_request();

        if (request.callback == NULL)
        {
            return;
        }

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

static void wm_process_window_event(SDL_Window *window, SDL_WindowEvent *event)
{
    if (event->event == SDL_WINDOWEVENT_CLOSE)
    {
        static void wm_close_window_w_ptr(SDL_Window *);
        wm_close_window_w_ptr(window);
    }
}

static int wm_create_new_window(const char *title, int x, int y, int w, int h, Uint32 flags)
{
    for (Uint8 i = 0; i < MAX_WINDOWS; i++)
    {
        if (windows[i] == NULL)
        {
            SDL_Window *new_window = SDL_CreateWindow(title, x, y, w, h, flags);
            if (new_window == NULL)
            {
                return -1;
            }
            else
            {
                windows[i] = new_window;
                return i;
            }
        }
    }

    return -1;
}

static void wm_close_window_w_ptr(SDL_Window *window)
{
    for (Uint8 i = 0; i < MAX_WINDOWS; i++)
    {
        if (windows[i] == window)
        {
            SDL_DestroyWindow(window);
            windows[i] = NULL;
            return;
        }
    }
}

// g
// g
