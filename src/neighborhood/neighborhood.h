#ifndef _NEIGHBORHOOD_H_
#define _NEIGHBORHOOD_H_

    #include "../functions/functions.h"
    #include "../voronoi_space/lattice.h"


    void find_neighbors_for_one_neuron(Lattice la, int ind_neuron);
    void find_neighbors_for_all_neurons(Lattice la);


    Bool are_neurons_neighbors(Lattice la, int ind_neuron_1, int ind_neuron_2);


#endif