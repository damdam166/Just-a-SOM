#include <stdio.h>
#include <stdlib.h>


#include "functions/functions.h"
#include "kohonen_algorithm/kohonen_som.h"


int main(int argc, char **argv) {

    double sd = standard_deviation_function(10);
		
    printf("%lf\n", sd);

    double hkjt = gaussian_n_function(1, sd);

    printf("%lf\n", hkjt);
   
    List_Element *li = new_list(1);

    printf("%lf\n", li->value);
	
    clear_list(li);

    return 0;
}
