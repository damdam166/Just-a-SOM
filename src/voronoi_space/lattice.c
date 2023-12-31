#include <stdio.h>
#include <stdlib.h>


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

    la->tab_w_vectors = (Node_Element *)malloc(number_w_vectors * sizeof(Node_Element));

    if (la->tab_w_vectors == NULL) {

        fprintf(stderr, "Dynamic Allocation Error.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < number_w_vectors; ++i) {

        la->tab_w_vectors[i].vector = (double *)malloc(dim * sizeof(double));

        if (la->tab_w_vectors[i].vector == NULL) {

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


Lattice initialize_weights(Lattice la, double *tab_min, double *tab_max) {

    // need to use for the randomization srand(time(NULL));
    for (int i_w = 0; i_w < la->rows * la->lines; ++i_w) {

        // Random initialization of the weights
        for (int i_dim = 0; i_dim < la->dimension; ++i_dim) {

            la->tab_w_vectors[i_w].vector[i_dim] = RANDOM_VALUE_FUNCTION(tab_min[i_dim], tab_max[i_dim]);
        }
    }

    // Initialize the neighborhood of each vectors
    initialize_neighbors_for_all_vectors(la);

    return la;
}


void print_lattice(Lattice la) {

    if (is_empty_lattice(la)) return ;

    int size_map = la->rows * la->lines;

    printf("Dimension of the lattice : %d x %d = %d \n\n", la->lines, la->rows, size_map);

    printf("Dimension of vectors : %d\n\n", la->dimension);

    printf("The topology is : %s\n\n", find_topo(la->topology));

    for (int i = 0; i < size_map; ++i) {

        printf("Node number %d: \n", i);
        print_node(la->tab_w_vectors[i], la->dimension);
        printf("\n\n");
    }
}


void clear_lattice(Lattice la) {

    if (is_empty_lattice(la)) return ;

    if (la->tab_w_vectors != NULL) {

        for (int i = 0; i < la->rows * la->lines; ++i) {

            if (la->tab_w_vectors[i].vector != NULL) free(la->tab_w_vectors[i].vector);
        }

        free(la->tab_w_vectors);
    }

    free(la);
}


