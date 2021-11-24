#include "SDL_events.h"
#include "main.h"

void input_event_process(SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_QUIT:
        main_exit_application();
        break;

    default:
        break;
    }
}