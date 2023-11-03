#ifndef _KOHONEN_SOM_H_
#define _KOHONEN_SOM_H_

    #include "../voronoi_space/lattice.h"


    // Find winner
    int find_winner(int p, Lattice la, double *X); // X is an input data


    // Adaptation
    void update_single_node(int dimension, double learning_rate, double standard_deviation, int p, Node pt_nd, Node pt_winner, double *X);
    void update_for_one_iteration(Lattice la, int iteration);


#endif