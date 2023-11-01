#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_


    typedef enum {

        FALSE, // 0
        TRUE // 1
    }Bool;


    typedef enum {

        R, // Rectangular
        L // Linear
    }Topology;


    char *find_topo(Topology topo);


    double dist_2(unsigned int dimension, const double x[], const double y[]);
    double dist_infinite(unsigned int dimension, const double x[], const double y[]);
    double dist_1(unsigned int dimension, const double x[], const double y[]);
    double dist_p(unsigned int p, unsigned int dimension, const double x[], const double y[]);


    #define NEIGHBORHOOD_RADIUS 0.01
    double standard_deviation_function(int t);
    double gaussian_n_function(double norm_w_k, double standard_deviation);


    #define LEARNING_RATE_PARAMETER 0.001
    double learning_rate_function(int t);


#endif