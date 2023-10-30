#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"


// norms
double norm_2(unsigned int dimension, double x[], double y[]) {

    double norm = 0;

    for (int i = 0; i < dimension; ++i) norm += pow( ( x[i] - y[i] ), 2);

    return sqrt(norm);
}


double norm_infinite(unsigned int dimension, double x[], double y[]) {

    double norm = 0;

    for (int i = 0; i < dimension; ++i) {

        double norm_temp = fabs( x[i] - y[i] );

        if (norm < norm_temp) norm = norm_temp;
    }

    return norm;
}

double norm_1(unsigned int dimension, double x[], double y[]) {
    

}

