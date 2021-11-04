add_executable(Aban "../main.c"
					"mm.c"
					"os/os.c"
					"pc.c"
)

target_include_directories(Aban PUBLIC
								"os/"
)


set(SDL_DIR "${CMAKE_CURRENT_LIST_DIR}/sdl/")
add_subdirectory(${SDL_DIR})
target_link_libraries(Aban SDL2 SDL2main)
target_include_directories(Aban PUBLIC "${SDL_DIR}/include")