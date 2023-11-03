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
    find_neighbors_for_all_vectors(la);

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

            if (la->tab_w_vectors[i].vector != NULL) free(la->tab_w_vectors[i].vector);
        }

        free(la->tab_w_vectors);
    }

    free(la);
}




// To initialize the neighborhood
void find_neighbors_for_one_vector(Lattice la, int ind_vector) {

    if (is_empty_lattice(la)) return ;


    // For the left neuron
    if (ind_vector % la->rows == 0) la->tab_w_vectors[ind_vector].left_n = -1;

    else la->tab_w_vectors[ind_vector].left_n = ind_vector - 1;


    // For the right neuron
    if ((ind_vector + 1) % la->rows == 0) la->tab_w_vectors[ind_vector].right_n = -1;

    else la->tab_w_vectors[ind_vector].right_n = ind_vector + 1;


    // For the upper neuron
    if (ind_vector < la->lines) la->tab_w_vectors[ind_vector].up_n = -1;

    else la->tab_w_vectors[ind_vector].up_n = ind_vector - la->rows;


    // For the bottom neuron
    if (la->rows * (la->lines - 1) <= ind_vector) la->tab_w_vectors[ind_vector].bottom_n = -1;

    else la->tab_w_vectors[ind_vector].bottom_n = ind_vector + la->rows;
}


void find_neighbors_for_all_vectors(Lattice la) {

    if (is_empty_lattice(la)) return ;

    for (int i_w = 0; i_w < la->rows * la->lines; ++i_w) find_neighbors_for_one_vector(la, i_w);
}


// To compare 2 vectors
Bool are_vectors_neighbors(Lattice la, int ind_vector_1, int ind_vector_2) {

    if (is_empty_lattice(la)) return FALSE;

    if (la->tab_w_vectors[ind_vector_1].left_n == ind_vector_2) return TRUE;

    else if (la->tab_w_vectors[ind_vector_1].right_n == ind_vector_2) return TRUE;

    else if (la->tab_w_vectors[ind_vector_1].up_n == ind_vector_2) return TRUE;

    else if (la->tab_w_vectors[ind_vector_1].bottom_n == ind_vector_2) return TRUE;

    return FALSE;
}