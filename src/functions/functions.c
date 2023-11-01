#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "functions.h"


char *find_topo(Topology topo) {

    switch (topo) {

        case R:
            return "Rectangular";
            break;

        case L:
            return "Linear";
            break;

        default:
            return "Rectangular";
    }
}

