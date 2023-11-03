#ifndef _LATTICE_H_
#define _LATTICE_H_

    #include "../functions/functions.h"


    typedef struct Node_Element {

        int left_n; // Neighbor from left
        int up_n; // Neighbor from up
        int right_n; // Neighbor from right
        int bottom_n;

        double *vector;
    }Node_Element, *Node;


    typedef struct Lattice_Element {

        unsigned int lines;
        unsigned int rows;
        unsigned int dimension;
        Topology topology;
        Node_Element *tab_w_vectors;
    }Lattice_Element, *Lattice;


    Lattice new_lattice(unsigned int lines, unsigned int rows, unsigned int dim, Topology topo);
    Bool is_empty_lattice(Lattice la);
    Lattice initialize_weights(Lattice la, double *tab_min, double *tab_max);
    void print_lattice(Lattice la);
    void clear_lattice(Lattice la);


#endif