#include <SDL.h>

int os_init(const int argc, const char *argv[])
{
    SDL_Init(0);
    return 0;
}

void os_exit()
{
    SDL_Quit();
}
void os_error() {}