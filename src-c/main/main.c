#include "SDL.h"

static SDL_atomic_t main_should_exit = {SDL_FALSE};
void main_exit_application()
{
	SDL_AtomicSet(&main_should_exit, SDL_TRUE);
}

static void main_exit();
static void main_event_process(SDL_Event);
static void main_fatal_error(int, char *, char *);

int main()
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
		SDL_bool should_quit = SDL_FALSE;
		SDL_Event event = {0};
		do
		{
			if (SDL_WaitEvent(&event) == 0)
			{
				main_fatal_error(0, "Failed SDL_WaitEvent", SDL_GetError());
				main_exit();
				return 1;
			}

			should_quit = SDL_AtomicGet(&main_should_exit);
		} while (!should_quit);
	}

	{ // Exiting application.
		main_exit();
		return 0;
	}
}

static void main_fatal_error(int error_code, char *error_title, char *error_msg)
{
	SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "\nError code %d\nError Title: %s\nError Message: %s\n", error_code, error_title, error_msg);
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, error_title, error_msg, NULL);
}

static void main_exit()
{
	SDL_Quit();
}

static void main_event_process(SDL_Event event)
{
}

// g
// g
// G
// G
