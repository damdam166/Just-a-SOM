#include <stdio.h>
#include <stdlib.h>

#include "kohonen_som.h"


// Find winner
int find_winner(int p, Lattice la, double *X) {

    if (is_empty_lattice(la)) return 0;

    int ind_temp = 0;
    double norm_temp = DIST_P(p, la->dimension, la->tab_w_vectors[ind_temp].vector, X);

    for (int i_w = 0; i_w < la->lines * la->rows; ++i_w) {

        if (DIST_P(p, la->dimension, la->tab_w_vectors[i_w].vector, X) <= norm_temp) ind_temp = i_w;
    }

    return ind_temp;
}


// Adaptation
void update_single_node(int dimension, double learning_rate, double standard_deviation, int p, Node pt_nd, Node pt_winner, double *X) {

    if (is_empty_node(pt_nd)) return ;


    // Calculus of the neighborhood function for winner and ind_vector
    double norm_w_i = DIST_P(p, dimension, pt_nd->vector, pt_winner->vector);
    double h_w_i = GAUSSIAN_N_FUNCTION(norm_w_i, standard_deviation);


    // Calculus of the difference
    double delta = learning_rate * h_w_i;


    // Update by component
    for (int i_dim = 0; i_dim < dimension; ++i_dim)

        pt_nd->vector[i_dim] += delta * ( X[i_dim] - pt_nd->vector[i_dim] );
}


void update_for_one_iteration(Lattice la, int iteration) {



}