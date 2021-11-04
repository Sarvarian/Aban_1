// Welcome to the Aban Operating System module.
//
// Purpose of this module is to abstract Operating System
// functionalities and make a platform-agnostic API
// to get used by other modules.
//
// For now, I decided to use SDL2 and Allegro 5.
// SDL2 because of its features and steam and controller support.
// Allegro just because I felt good about it.
//
// I wanted to have direct Win32 support as well but
// the differences between SDL2 and Win32 API is too much and
// make things a lot more complicated. So maybe later.
// 
// Right now, I'm working on SDL2 support. Allegro 5 maybe later.
// 
// Mohammad Jamal Sarvarian - Aban 2580
// Sarvarian@Hotmail.com
// 
// gg


// Import 'SDL.h' to initialize and abstaracted.
#include <SDL.h>

// One of 'main.c' essential subroutines.
int os_init(const int argc, const char* argv[])
{
	// Initialize SDL2 and store its returned data.
	int err = SDL_Init(SDL_INIT_EVERYTHING);

	// Check if SDL_Init failed.
	if (err != 0)
	{
		// What's happend?
		static const char* msg = "SDL_Init() Failed!";

		// SDL What's happend?
		const char* sdl_msg = SDL_GetError();

		// Log our message to the console, hopefully.
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "%s - SDL Error: %s\n", msg, sdl_msg);

		// Attempt to show a MessageBox and notify the user.
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, msg, sdl_msg, NULL);

		// Return error code.
		return err;
	}
	else
	{
		// Return successfuly. 'err' should be 0.
		return err;
	}
}

// One of 'main.c' essential subroutines.
void os_exit()
{
	// Shutdown SDL.
	SDL_Quit();
}

// One of 'main.c' essential subroutines.
void os_error(int error_code, char* error_msg)
{
	// Log error to the console.
	SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Error code %d: %s", error_code, error_msg);
	
	// Show a MessageBox.
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error!", error_msg, NULL);
}