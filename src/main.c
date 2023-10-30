#include <stdio.h>
#include <stdlib.h>


#include "functions/functions.h"
#include "kohonen_algorithm/kohonen_som.h"


int main(int argc, char **argv) {

    double x[] = {1, 2}, y[] = {2, 1};

    double norm = norm_2(2, x, y);
    printf("%lf\n", norm);

    printf("Hello World !\n");
    return 0;
}