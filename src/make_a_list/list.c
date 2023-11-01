#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "../functions/functions.h"


List new_list(int x) {

    List_Element *li = (List_Element *)malloc(sizeof(List_Element));

    if (li == NULL) {

        fprintf(stderr, "Dynamic allocation error.\n");
        exit(EXIT_FAILURE);
    }

    li->value = x;
    li->next = NULL;

    return li;
}