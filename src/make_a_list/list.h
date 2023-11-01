#ifndef _LIST_H_
#define _LIST_H_

    #include "../functions/functions.h"

    typedef struct List_Element {

        double value;
        double *next;
    }List_Element, *List;


    List new_list(int x);
    Bool is_empty_list(List li);
    List add_right_element(List li, double x);
    List pop_right_element(List li);
    void print_list(List li);
    void clear_list(List li);

#endif