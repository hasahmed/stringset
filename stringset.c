//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//
#include <stdlib.h>
#include <stdio.h>

#include "node.h"
#include "stringset.h"
#include <string.h>
#include "util.h"

stringset* stringset_new(unsigned int initial_size){
    stringset *str_set = (stringset*) malloc(sizeof(stringset)); //allocate the pointer for the whole string set
    str_set->node_array = (node**)malloc((sizeof(node*) * initial_size)); // allocate the pointer for the node_array
    str_set->node_array_length = initial_size;
    unsigned int i = 0;
    for(i = 0; i < initial_size; i++){
        str_set->node_array[i] = NULL; //initialize every pointer to null
    }
    str_set->num_elements = 0; //all that has been allocated is the pointer to the first element
    return str_set;
}

void stringset_free(stringset *str_set){
    int i = 0;
    for (i = 0; i < str_set->node_array_length; i++){
        node_free_list(str_set->node_array[i]);
    }
    free(str_set->node_array);
    free(str_set);
}

int stringset_add(stringset *str_set, const char *str){
    unsigned long hashcode = hash_code(str) % str_set->node_array_length;
    node *tmp = str_set->node_array[hashcode];
    while(tmp->next != NULL){
        if (strcmp(tmp->string, str) == 0)
            return 0;
        tmp = tmp->next;
    }
    if (strcmp(tmp->string, str) == 0)
        return 0;
    list_insert_new_after(tmp, str);
    return 1;
}

int stringset_remove(stringset *str_set, const char *str) {
    unsigned long hashcode = hash_code(str) % str_set->node_array_length;
    node *tmp = str_set->node_array[hashcode];
    node *prev = NULL;
    while(tmp != NULL){
        if(strcmp(tmp->string, str) == 0) {
            if (prev == NULL){
                str_set->node_array[hashcode] = tmp->next;
                node_free(tmp);
                return 1;
            }

            list_remove_node(prev, tmp, str);
            return 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return 0; // no such element existed, and hence was not removed
}
