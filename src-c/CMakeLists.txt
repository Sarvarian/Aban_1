add_executable(Aban "../main.c"
					"mm.c"
					"os/os.c"
					"pc.c"
)

target_include_directories(Aban PUBLIC
								"os/"
)


set(SDL_DIR "${CMAKE_CURRENT_LIST_DIR}/sdl/")
add_library(SDL2 STATIC IMPORTED)
add_library(SDL2main STATIC IMPORTED)
set_target_properties(SDL2 PROPERTIES IMPORTED_LOCATION "${SDL_DIR}/lib/x64/SDL2.lib")
set_target_properties(SDL2main PROPERTIES IMPORTED_LOCATION "${SDL_DIR}/lib/x64/SDL2main.lib")
target_link_libraries(Aban PUBLIC SDL2 SDL2main)
target_include_directories(Aban PUBLIC "${SDL_DIR}/include")