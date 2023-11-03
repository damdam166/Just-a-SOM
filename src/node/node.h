#ifndef _NODE_H_
#define _NODE_H_

    #include "../functions/functions.h"


    typedef struct Node_Element {

        int left_n; // Neighbor from left
        int up_n; // Neighbor from up
        int right_n; // Neighbor from right
        int bottom_n; // Neighbor from the bottom

        double *vector;
    }Node_Element, *Node;


    Bool is_empty_node(Node pt_nd);
    void print_node(Node_Element nd, int dim);


#endif