//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//
#include <stdlib.h>
#include "stringset.h"
stringset* stringset_new(unsigned int initial_size){
    stringset *str_set = (stringset*) malloc(sizeof(stringset));
    str_set->element_array = (set_element**) malloc(sizeof(set_element*));
    str_set->element_array_length = initial_size;
    str_set->num_elements = 0; //all that has been allocated is the pointer to the first element
    return str_set;

}
void stringset_free(stringset *str_set){
    int i = 0;
    for (i = 0; i < str_set->num_elements; i++){
        free(str_set->element_array[i]);
    }
    free(str_set->element_array);
    free(str_set);
}

