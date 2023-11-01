#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"


char *find_topo(Topology topo) {

    switch (topo) {

        case R:
            return "Rectangular";
            break;

        case L:
            return "Linear";
            break;

        default:
            return "Rectangular";
    }
}



double dist_p(unsigned int p, unsigned int dimension, const double x[], const double y[]) {


    if (p == 0) {

        fprintf(stderr, "p == 0.\n");
        exit(1);
    }

    double norm = 0;

    if (p == 1) {

        for (int i = 0; i < dimension; ++i) norm += fabs( x[i] - y[i] );
    } else {

        for (int i = 0; i < dimension; ++i) norm += pow(fabs( x[i] - y[i] ) , p);
        norm = pow(norm, 1.0 / p);
    }

    return norm;
}


