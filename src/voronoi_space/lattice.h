#ifndef _LATTICE_H_
#define _LATTICE_H_

    #include "../node/node.h"


    typedef struct Lattice_Element {

        unsigned int lines;
        unsigned int rows;
        unsigned int dimension;
        Topology topology;
        Node_Element *tab_w_vectors;
    }Lattice_Element, *Lattice;


    Lattice new_lattice(unsigned int lines, unsigned int rows, unsigned int dim, Topology topo);
    Bool is_empty_lattice(Lattice la);


    #include "../neighborhood/neighborhood.h"
    Lattice initialize_weights(Lattice la, double *tab_min, double *tab_max);
    void print_lattice(Lattice la);
    void clear_lattice(Lattice la);


#endif