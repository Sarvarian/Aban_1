set(HERE ${CMAKE_CURRENT_LIST_DIR})

add_subdirectory("${HERE}/main")
add_subdirectory("${HERE}/input")
add_subdirectory("${HERE}/rtp")

set(SDL_DIR "${HERE}/sdl/")
add_subdirectory(${SDL_DIR})
target_link_libraries(Aban SDL2 SDL2main)
target_include_directories(Aban PUBLIC "${SDL_DIR}/include")