#ifndef _LATTICE_H_
#define _LATTICE_H_

    #include "../functions/functions.h"


    typedef struct Weight_Vectors_Element {

        int nb_w_vectors;
        int dimension;
        double **tab_w_vectors;
    }Weight_Vectors_Element, *Weight_Vectors;




#endif