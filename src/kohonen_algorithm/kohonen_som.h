#ifndef _KOHONEN_SOM_H_
#define _KOHONEN_SOM_H_

    #include "../voronoi_space/lattice.h"


    // Find winner
    int find_winner(unsigned int p, Lattice la, double *x); // x is an input data vector


    // Adaptation
    void update_single_node(unsigned int dimension, double learning_rate, double standard_deviation, unsigned int p, Node pt_nd, Node pt_winner, double *x);
    void update_for_one_iteration(unsigned int iteration, unsigned int p, Lattice la, double *x);


#endif