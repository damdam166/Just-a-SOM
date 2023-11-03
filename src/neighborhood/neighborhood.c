#include <stdio.h>
#include <stdlib.h>


#include "../functions/functions.h"
#include "../voronoi_space/lattice.h"


// To initialize the neighborhood
void find_neighbors_for_one_neuron(Lattice la, int ind_neuron) {

    if (is_empty_lattice(la)) return ;


    // For the left neuron
    if (ind_neuron % la->rows == 0) la->tab_w_vectors[ind_neuron].left_n = -1;

    else la->tab_w_vectors[ind_neuron].left_n = ind_neuron - 1;


    // For the right neuron
    if ((ind_neuron + 1) % la->rows == 0) la->tab_w_vectors[ind_neuron].right_n = -1;

    else la->tab_w_vectors[ind_neuron].right_n = ind_neuron + 1;


    // For the upper neuron
    if (ind_neuron < la->lines) la->tab_w_vectors[ind_neuron].up_n = -1;

    else la->tab_w_vectors[ind_neuron].up_n = ind_neuron - la->rows;


    // For the bottom neuron
    if (la->rows * (la->lines - 1) <= ind_neuron) la->tab_w_vectors[ind_neuron].bottom_n = -1;

    else la->tab_w_vectors[ind_neuron].bottom_n = ind_neuron + la->rows;
}


void find_neighbors_for_all_neurons(Lattice la) {

    if (is_empty_lattice(la)) return ;

    for (int i_w = 0; i_w < la->rows * la->lines; ++i_w) find_neighbors_for_one_neuron(la, i_w);
}


// To compare 2 neurons
Bool are_neurons_neighbors(Lattice la, int ind_neuron_1, int ind_neuron_2) {

    if (is_empty_lattice(la)) return FALSE;

    if (la->tab_w_vectors[ind_neuron_1].left_n == ind_neuron_2) return TRUE;

    else if (la->tab_w_vectors[ind_neuron_1].right_n == ind_neuron_2) return TRUE;

    else if (la->tab_w_vectors[ind_neuron_1].up_n == ind_neuron_2) return TRUE;

    else if (la->tab_w_vectors[ind_neuron_1].bottom_n == ind_neuron_2) return TRUE;

    return FALSE;
}