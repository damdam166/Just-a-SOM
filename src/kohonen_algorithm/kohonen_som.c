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
void update_single_node(Node pt_nd, int ind_vector, int winner, double learning_rate, double standard_deviation) {

    if (is_empty_node(pt_nd)) return ;





}