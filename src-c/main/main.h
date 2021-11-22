// Do not read it. Just set it to 1 or True when you want to exit the whole application.
extern char main_should_exit;
inline void main_exit_application()
{
    main_should_exit = SDL_TRUE;
}