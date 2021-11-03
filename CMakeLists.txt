cmake_minimum_required(VERSION 3.10)
project(Aban VERSION 0.1.0)

add_subdirectory(src-c)
list(APPEND LIBS
    AbanMM
    AbanOS
    AbanPC
)

add_executable(Aban "main.c")
target_link_libraries(Aban PUBLIC ${LIBS})
# target_include_directories(Aban PUBLIC ${INCLUDES})
