#include <stdio.h>
#include <stdlib.h>
#include "../functions/functions.h"
#include "lattice.h"


Lattice new_lattice(int lines, int rows, int dim, Topology topo) {

    Lattice_Element *la = (Lattice_Element *)malloc(sizeof(Lattice_Element));

    if (la == NULL) {

        fprintf(stderr, "Dynamic Allocation Error.\n");
        exit(EXIT_FAILURE);
    }

    la->lines = lines;
    la->rows = rows;
    la->dimension = dim;
    la->topology = topo;





    return la;
}


