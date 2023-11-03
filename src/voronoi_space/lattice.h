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
    Lattice initialize_weights(Lattice la, double *tab_min, double *tab_max);
    void print_lattice(Lattice la);
    void clear_lattice(Lattice la);


    void find_neighbors_for_one_vector(Lattice la, int ind_vector);
    void find_neighbors_for_all_vectors(Lattice la);

    Bool are_vectors_neighbors(Lattice la, int ind_vector_1, int ind_vector_2);


#endif