include_directories(inc)

add_library(api_library STATIC
    src/api.c
    src/drawgradient.c
    src/drawgradient.h
    src/drawstar.c
    src/drawstar.h
    src/rgbtograyscale.c
    src/rgbtograyscale.h
    src/rotate.c
    src/rotate.h
    src/rotate90.c
    src/rotate90.h
    src/rotatebilinear.c
    src/rotatebilinear.h
    src/sobel.c
    src/sobel.h
    src/sobelhorizontal.c
    src/sobelhorizontal.h
    src/sobelvertical.c
    src/sobelvertical.h
    src/rotateincomplete.c
    src/rotateincomplete.h)

export(TARGETS api_library FILE api_library.cmake)
