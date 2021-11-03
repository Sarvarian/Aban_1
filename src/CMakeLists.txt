cmake_minimum_required(VERSION 3.10)
project(Aban VERSION 0.1.0)

add_executable(Aban "main.c"
                    "mm/mm.c"
                    "os/os.c"
                    "pc/pc.c"
)
