#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"


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

        for (int i = 0; i < dimension; ++i) norm += pow(( x[i] - y[i] ) , p);
        norm = pow(norm, 1 / p);
    }

    return norm;
}