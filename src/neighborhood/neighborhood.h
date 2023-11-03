#ifndef _NEIGHBORHOOD_H_
#define _NEIGHBORHOOD_H_

    #include "../voronoi_space/lattice.h"


    void find_neighbors_for_one_vector(Lattice la, int ind_vector);
    void find_neighbors_for_all_vectors(Lattice la);

    Bool are_vectors_neighbors(Lattice la, int ind_vector_1, int ind_vector_2);


#endif