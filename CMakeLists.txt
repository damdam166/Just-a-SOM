cmake_minimum_required(VERSION 3.26)
project(Just_a_SOM)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/functions)
include_directories(src/kohonen_algorithm)

add_executable(Just_a_SOM
        src/functions/functions.c
        src/functions/functions.h
        src/kohonen_algorithm/kohonen_som.c
        src/kohonen_algorithm/kohonen_som.h
        src/compiling.sh
        src/main.c
        LICENSE
        README.md
        src/voronoi_space/lattice.c
        src/voronoi_space/lattice.h
        src/node/node.c
        src/node/node.h
        src/neighborhood/neighborhood.c
        src/neighborhood/neighborhood.h
)
