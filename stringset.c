//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//
#include <stdlib.h>

#include "node.h"
#include "stringset.h"

stringset* stringset_new(unsigned int initial_size){
    stringset *str_set = (stringset*) malloc(sizeof(stringset));
    str_set->node_array = (node**)malloc((sizeof(node*) * initial_size)); //array of node pointers
    str_set->node_array_length = initial_size;
    unsigned int i = 0;
    for(i = 0; i < initial_size; i++){
        str_set->node_array[i] = NULL; //initialize every pointer to null
    }
    str_set->num_elements = 0; //all that has been allocated is the pointer to the first element
    return str_set;
}
unsigned long hash_code(char *str) { /* copied djb2 hashing algorithm */
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}

void stringset_free(stringset *str_set){
    int i = 0;
    for (i = 0; i < str_set->node_array_length; i++){
        node_free_list(str_set->node_array[i]);
    }
    free(str_set->node_array);
    free(str_set);
}
