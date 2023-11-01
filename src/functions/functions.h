#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_

    #include <math.h>


    typedef enum {

        FALSE, // 0
        TRUE // 1
    }Bool;


    typedef enum {

        R, // Rectangular
        L // Linear
    }Topology;


    char *find_topo(Topology topo);


    // Distances
    #define DIST_2(dimension, x, y) \
    ({ \
        double norm = 0; \
        for (int i = 0; i < (dimension); ++i) \
            norm += pow((x)[i] - (y)[i], 2); \
        sqrt(norm); \
    })

    #define DIST_INFINITE(dimension, x, y) \
    ({                                     \
        double norm = 0; \
        for (int i = 0; i < (dimension); ++i) { \
            double norm_temp = fabs((x)[i] - (y)[i]); \
            if (norm < norm_temp) norm = norm_temp; \
        }\
        norm; \
    })

    #define DIST_1(dimension, x, y) \
    ({ \
        double norm = 0; \
        for (int i = 0; i < (dimension); ++i) \
            norm += fabs((x)[i] - (y)[i]); \
        norm; \
    })


    double dist_1(unsigned int dimension, const double x[], const double y[]);
    double dist_p(unsigned int p, unsigned int dimension, const double x[], const double y[]);


    // Neighborhood function
    #define NEIGHBORHOOD_RADIUS 0.01
    #define STANDARD_DEVIATION_FUNCTION(t) exp( - (NEIGHBORHOOD_RADIUS) * (double)(t) )

    // norm_w_k is the norm between the winner and the neighbor number k
    #define GAUSSIAN_N_FUNCTION(norm_w_k, standard_deviation) \
    exp( - (double)(norm_w_k) * (double)(norm_w_k) / ( 2 * (double)(standard_deviation) * (double)(standard_deviation) ) )


    // Learning rate function
    #define LEARNING_RATE_PARAMETER 0.001
    #define LEARNING_RATE_FUNCTION(t) exp( ( - (LEARNING_RATE_PARAMETER) * (double)(t)) )


#endif