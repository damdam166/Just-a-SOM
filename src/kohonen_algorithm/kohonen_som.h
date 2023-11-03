#ifndef _KOHONEN_SOM_H_
#define _KOHONEN_SOM_H_

    #include "../voronoi_space/lattice.h"


    // Find winner
    int find_winner(int p, Lattice la, double *X); // X is an input data


    // Adaptation
    void update_single_node(Node pt_nd, int ind_vector, int winner, double learning_rate, double standard_deviation);


#endif