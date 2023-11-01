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


Bool is_empty_list(List li) {

    if (li == NULL) return TRUE;

    return FALSE;
}





void clear_list(List li) {

    if (is_empty_list(li)) return ;

    while(li != NULL) {

        List_Element *temp = li->next;
        free(li);
        li = temp;
    }
}