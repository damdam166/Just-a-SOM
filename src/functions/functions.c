#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"


// norms
double euclidean_norm(unsigned int dimension, double x[], double y[]) {

    int norm = 0;

    for (int i = 0; i < dimension; ++i) norm += pow( ( x[i] - y[i] ), 2);

    return sqrt(norm);
}

