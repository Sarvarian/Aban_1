#include "SDL.h"

char main_should_exit = SDL_FALSE;

static void main_exit();
static void main_event_process(SDL_Event *);
static void main_fatal_error(const int, const char *, const char *);

int main(int argc, char *argv[])
{
	{ // Initialization process.
		int err = 0;
		err = SDL_Init(SDL_INIT_EVERYTHING);
		if (err != 0)
		{
			main_fatal_error(err, "Failed SDL_init", SDL_GetError());
			main_exit();
			return err;
		}
	}

	{ // Event loop.
		SDL_Event event = {0};
		do
		{
			if (SDL_WaitEvent(&event) == 0)
			{
				main_fatal_error(0, "Failed SDL_WaitEvent", SDL_GetError());
				main_exit();
				return 1;
			}

			main_event_process(&event);

		} while (main_should_exit == SDL_FALSE);
	}

	{ // Exiting application.
		main_exit();
		return 0;
	}
}

static void main_fatal_error(const int error_code, const char *error_title, const char *error_msg)
{
	SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "\nError code %d\nError Title: %s\nError Message: %s\n", error_code, error_title, error_msg);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, error_title, error_msg, NULL);
}

static void main_exit()
{
	SDL_Quit();
}

static void main_event_process(SDL_Event *event)
{
	SDL_Log("%d\n", event->type);
}

// g
// g
// G
// G
