#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

    double tab_min[10] = {};

    for (int i = 0; i < 10; ++i) tab_min[i] = -1;

    double tab_max[10] = {1};

    for (int i = 0; i < 10; ++i) tab_max[i] = 1;

    srand(time(NULL));
	
    la = initialize_weights(la, tab_min, tab_max);


    print_lattice(la);
	
    int ind_winner = find_winner(2, la, tab_min);

    printf("%d\n\n", ind_winner);


    update_for_one_iteration(1, 2, la, tab_min);



    clear_lattice(la);

    return 0;
}
