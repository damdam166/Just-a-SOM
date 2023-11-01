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




// Distances
double dist_2(unsigned int dimension, const double x[], const double y[]) {

    double norm = 0;

    for (int i = 0; i < dimension; ++i) norm += pow( ( x[i] - y[i] ), 2);

    return sqrt(norm);
}


double dist_infinite(unsigned int dimension, const double x[], const double y[]) {

    double norm = 0;

    for (int i = 0; i < dimension; ++i) {

        double norm_temp = fabs( x[i] - y[i] );

        if (norm < norm_temp) norm = norm_temp;
    }

    return norm;
}


double dist_1(unsigned int dimension, const double x[], const double y[]) {

    double norm = 0;

    for (int i = 0; i < dimension; ++i) norm += fabs( x[i] - y[i] );

    return norm;
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




// Neighborhood function
double standard_deviation_function(int t) {

    return exp(- NEIGHBORHOOD_RADIUS * t);
}


double gaussian_n_function(double norm_w_k, double standard_deviation) {

    // norm_w_k is the norm between the winner and the neighbor number k

    return exp(- norm_w_k * norm_w_k / (2 * standard_deviation * standard_deviation) );
}




// Learning rate function
double learning_rate_function(int t) {

    return exp(- LEARNING_RATE_PARAMETER * t);
}


