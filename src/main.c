#include <stdio.h>
#include <stdlib.h>


#include "functions/functions.h"
#include "kohonen_algorithm/kohonen_som.h"


int main(int argc, char **argv) {

    double sd = standard_deviation_function(10);
		
    printf("%lf\n", sd);

    double hkjt = gaussian_n_function(1, sd);

    printf("%lf\n", hkjt);
  	
    Lattice_Element *la = new_lattice(10, 10, 2, 0);

    print_lattice(la);

    clear_lattice(la);

    return 0;
}
