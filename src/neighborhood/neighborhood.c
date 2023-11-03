#include <stdio.h>
#include <stdlib.h>


#include "neighborhood.h"


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