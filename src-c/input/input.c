#include "SDL_events.h"
#include "main.h"
#include "wm.h"

void input_event_process(SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_QUIT:
        main_exit_application();
        break;

    case SDL_WINDOWEVENT:
        wm_window_event(event);
        break;

    default:
        break;
    }
}