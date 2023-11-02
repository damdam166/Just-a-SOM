#include <stdio.h>
#include <stdlib.h>


#include "functions/functions.h"
#include "kohonen_algorithm/kohonen_som.h"


int main(int argc, char **argv) {

    double sd = STANDARD_DEVIATION_FUNCTION(10);
		
    printf("%lf\n", sd);
	
    double x[] = {1, 2}, y[] = {2, 1};

    double d_2 = DIST_2(2, x, y);

    printf("%lf\n", d_2);

    double hkjt = GAUSSIAN_N_FUNCTION(1, sd);

    printf("%lf\n", hkjt);
  	
    Lattice_Element *la = new_lattice(10, 10, 2, 0);
	
    print_lattice(la);

    clear_lattice(la);

    double rd = RANDOM_VALUE_FUNCTION(1.3, 1.8);
			
    printf("%lf\n", rd);

    return 0;
}
