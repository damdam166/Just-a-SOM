#ifndef _LATTICE_H_
#define _LATTICE_H_

    #include "../functions/functions.h"


    typedef struct Lattice_Element {

        unsigned int lines;
        unsigned int rows;
        unsigned int dimension;
        Topology topology;
        double **tab_w_vectors;
    }Lattice_Element, *Lattice;

    Lattice new_lattice(unsigned int lines, unsigned int rows, unsigned int dim, Topology topo);
    Bool is_empty_lattice(Lattice la);

    void print_lattice(Lattice la);
    void clear_lattice(Lattice la);

#endif