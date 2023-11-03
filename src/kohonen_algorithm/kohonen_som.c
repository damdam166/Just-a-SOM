#include <stdio.h>
#include <stdlib.h>

#include "kohonen_som.h"


// Find winner
int find_winner(unsigned int p, Lattice la, double *x) {

    if (is_empty_lattice(la)) return 0;

    int ind_temp = 0;
    double norm_temp = DIST_P(p, la->dimension, la->tab_w_vectors[ind_temp].vector, x);

    for (int i_w = 0; i_w < la->lines * la->rows; ++i_w) {

        if (DIST_P(p, la->dimension, la->tab_w_vectors[i_w].vector, x) <= norm_temp) ind_temp = i_w;
    }

    return ind_temp;
}


// Adaptation
void update_single_node(unsigned int dimension, double learning_rate, double standard_deviation, unsigned int p, Node pt_nd, Node pt_winner, double *x) {

    if (is_empty_node(pt_nd)) return ;


    // Calculus of the neighborhood function for winner and ind_vector
    double norm_w_i = DIST_P(p, dimension, pt_nd->vector, pt_winner->vector);
    double h_w_i = GAUSSIAN_N_FUNCTION(norm_w_i, standard_deviation);


    // Calculus of the difference
    double delta = learning_rate * h_w_i;


    // Update by component
    for (int i_dim = 0; i_dim < dimension; ++i_dim)

        pt_nd->vector[i_dim] += delta * ( x[i_dim] - pt_nd->vector[i_dim] );
}


void update_for_one_iteration(unsigned int iteration, unsigned int p, Lattice la, double *x) {

    if (is_empty_lattice(la)) return ;


    // Calculus of useful parameters
    double learning_rate = LEARNING_RATE_FUNCTION(iteration);
    double standard_deviation = STANDARD_DEVIATION_FUNCTION(iteration);


    // Find the winner
    int ind_winner = find_winner(p, la, x);


    // Update
        // For the winner
    update_single_node(la->dimension, learning_rate, standard_deviation, p, &la->tab_w_vectors[ind_winner], &la->tab_w_vectors[ind_winner], x);

        // For the neighbor of the left
    if (la->tab_w_vectors[ind_winner].left_n != -1) update_single_node(la->dimension, learning_rate, standard_deviation, p, &la->tab_w_vectors[la->tab_w_vectors[ind_winner].left_n], &la->tab_w_vectors[ind_winner], x);

        // For the neighbor of up
    if (la->tab_w_vectors[ind_winner].up_n != -1) update_single_node(la->dimension, learning_rate, standard_deviation, p, &la->tab_w_vectors[la->tab_w_vectors[ind_winner].up_n], &la->tab_w_vectors[ind_winner], x);

        // For the neighbor of the right
    if (la->tab_w_vectors[ind_winner].right_n != -1) update_single_node(la->dimension, learning_rate, standard_deviation, p, &la->tab_w_vectors[la->tab_w_vectors[ind_winner].right_n], &la->tab_w_vectors[ind_winner], x);

        // For the neighbor of the bottom
    if (la->tab_w_vectors[ind_winner].bottom_n != -1) update_single_node(la->dimension, learning_rate, standard_deviation, p, &la->tab_w_vectors[la->tab_w_vectors[ind_winner].bottom_n], &la->tab_w_vectors[ind_winner], x);
}


void update_for_all_iterations(unsigned int p, unsigned int nb_input_data_vectors, unsigned int max_iterations, Lattice la, double **X) {

    if (is_empty_lattice(la)) return ;

    for (unsigned int i_iter = 0; i_iter < max_iterations; ++i_iter) {

        // Find a random input data vector
        int random_ind_input_data_vector = RANDOM_VALUE_FUNCTION(0, nb_input_data_vectors - 1);

        // Update
        update_for_one_iteration(i_iter, p, la, X[random_ind_input_data_vector]);
    }
}


