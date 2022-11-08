cmake_minimum_required(VERSION 3.23)
project(ProjetInfoS3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(ProjetInfoS3
        header.h
        main.c
        source.c)

target_link_libraries(ProjetInfoS3 -lmingw32 -lalleg44)

