cmake_minimum_required(VERSION 3.23)
project(ProjetInfoS3 C)

set(CMAKE_C_STANDARD 11)

include_directories(.
        Bitmaps)

add_executable(ProjetInfoS3
        header.h
        main.c
        source.c affichages.c initialisations.c demarrage.c sauvegardes.c tdg.c coorpixels.c actualisations.c verifications.c caavancedoucement.c ecrandejeu.c)

target_link_libraries(ProjetInfoS3 -lmingw32 -lalleg44)

