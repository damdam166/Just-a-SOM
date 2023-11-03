#include <stdio.h>
#include <stdlib.h>


#include "node.h"


Bool is_empty_node(Node pt_nd) {

    if (pt_nd == NULL) return TRUE;

    return FALSE;
}


void print_node(Node_Element nd, int dim) {

    printf("The vector is ; \n\n");
    PRINT_VECTOR(nd.vector, dim);
    printf("\n");

    printf("The neighbor from the left is : %d\n", nd.left_n);
    printf("The neighbor from up is : %d\n", nd.up_n);
    printf("The neighbor from the right is : %d\n", nd.right_n);
    printf("The neighbor from the bottom is : %d\n", nd.bottom_n);
}