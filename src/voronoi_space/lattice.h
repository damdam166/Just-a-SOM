#ifndef _LATTICE_H_
#define _LATTICE_H_

    #include "../functions/functions.h"


    typedef struct Lattice_Element {

        int lines;
        int rows;
        int dimension;
        Topology topology;
        double **tab_w_vectors;
    }Lattice_Element, *Lattice;

    Lattice new_lattice(int lines, int rows, int dim, Topology topo);
    Bool is_lattice_empty(Lattice la);

    void print_lattice(Lattice la);
    void clear_lattice(Lattice la);

#endif