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

    int number_w_vectors = lines * rows;

    la->tab_w_vectors = (double **)malloc(number_w_vectors * sizeof(double *));

    if (la->tab_w_vectors == NULL) {

        fprintf(stderr, "Dynamic Allocation Error.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < number_w_vectors; ++i) {

        la->tab_w_vectors[i] = (double *)malloc(dim * sizeof(double));

        if (la->tab_w_vectors[i] == NULL) {

            fprintf(stderr, "Dynamic Allocation Error.\n");
            exit(EXIT_FAILURE);
        }
    }

    return la;
}


Bool is_empty_lattice(Lattice la) {

    if (la == NULL) return TRUE;

    return FALSE;
}







void clear_lattice(Lattice la) {

    if (is_empty_lattice(la)) return ;

    if (la->tab_w_vectors != NULL) {

        for (int i = 0; i < la->rows * la->lines; ++i) {

            if (la->tab_w_vectors[i] != NULL) free(la->tab_w_vectors[i]);
        }

        free(la->tab_w_vectors);
    }

    free(la);
}