target_sources(Aban
PRIVATE
"main/main.c"
"input/input.c"
"wm/wm.c"
PUBLIC
"main/main.h"
"input/input.h"
"wm/wm.h"
)

target_include_directories(Aban
PUBLIC
"main"
"input"
"wm"
)

set(SDL_DIR "${CMAKE_CURRENT_LIST_DIR}/sdl/")
add_subdirectory(${SDL_DIR})
target_link_libraries(Aban SDL2 SDL2main)
target_include_directories(Aban PUBLIC "${SDL_DIR}/include")