#include <stdio.h>
#include <stdlib.h>
#include "../functions/functions.h"
#include "lattice.h"


Lattice new_lattice(unsigned int lines, unsigned int rows, unsigned int dim, Topology topo) {

    Lattice_Element *la = (Lattice_Element *)malloc(sizeof(Lattice_Element));

    if (la == NULL) {

        fprintf(stderr, "Dynamic Allocation Error.\n");
        exit(EXIT_FAILURE);
    }

    la->lines = lines;
    la->rows = rows;
    la->dimension = dim;
    la->topology = topo;

    unsigned int number_w_vectors = lines * rows;

    la->tab_w_vectors = (Node *)malloc(number_w_vectors * sizeof(Node));

    if (la->tab_w_vectors == NULL) {

        fprintf(stderr, "Dynamic Allocation Error.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < number_w_vectors; ++i) {

        la->tab_w_vectors[i] = (Node)malloc(dim * sizeof(Node));

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


Lattice initialize_weights(Lattice la, Node_Element *tab_min, Node_Element *tab_max) {

    // need to use for the randomization srand(time(NULL));
    for (int i_w = 0; i_w < la->lines * la->rows; ++i_w) {

        for (int i_dim = 0; i_dim < la->dimension; ++i_dim) {

            la->tab_w_vectors[i_w][i_dim].w_vector = RANDOM_VALUE_FUNCTION(tab_min[i_dim].w_vector, tab_max[i_dim].w_vector);
        }
    }

    return la;
}


void print_lattice(Lattice la) {

    if (is_empty_lattice(la)) return ;

    printf("Dimension of the lattice : %d x %d = %d \n\n", la->lines, la->rows, la->lines * la->rows);

    printf("Dimension of vectors : %d\n\n", la->dimension);

    printf("The topology is : %s\n\n", find_topo(la->topology));
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