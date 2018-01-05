//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//
#include <stdlib.h>
#include <stdio.h>

#include "node.h"
#include "stringset.h"
#include <string.h>
#include "util.h"

stringset* stringset_new(unsigned int initial_size, float load_factor){
    stringset *str_set = (stringset*) malloc(sizeof(stringset)); //allocate the pointer for the whole string set
    str_set->node_array = (node**)malloc((sizeof(node*) * initial_size)); // allocate the pointer for the node_array
    str_set->node_array_length = initial_size;
    str_set->load_factor = load_factor;
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

int stringset_check(stringset *str_set, const char *str) {
    unsigned long hashcode = hash_code(str) % str_set->node_array_length;
    node *tmp = str_set->node_array[hashcode];
    while (tmp) {
        if (strcmp(tmp->string, str) == 0)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

int stringset_add(stringset *str_set, const char *str) {
    unsigned long hashcode = hash_code(str) % str_set->node_array_length;
    node *tmp = str_set->node_array[hashcode];
    if (tmp) {
        while (tmp->next != NULL) {
            if (strcmp(tmp->string, str) == 0)
                return 0;
            tmp = tmp->next;
        }
        if (strcmp(tmp->string, str) == 0)
            return 0;
        list_insert_new_after(tmp, str);
        str_set->num_elements++;
        return 1;
    } else {
        str_set->node_array[hashcode] = node_new(str, NULL);
        str_set->num_elements++;
        return 1;
    }
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
                str_set->num_elements--;
                return 1;
            }

            list_remove_node(prev, tmp, str);
            str_set->num_elements--;
            return 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return 0; // no such element existed, and hence was not removed
}
int stringset_deepcopy(stringset *dest, stringset *src) {
    if (dest->node_array_length <= src->node_array_length)
        return 0;

}

/**
 * Utility that copies one stringset's pointers into another one
 * *NOTE* This does not actually copy the string set's elements, just pointers to them,
 * use stringset_deepcopy if you want to actually copy the elements
 * @param dest pointer to the string set that we are going to copy into
 * @param src pointer to string set we are copying
 * @return 0 if the dest string set's size is smaller than the src's, 1 otherwise
 */
int stringset_copy(stringset *dest, stringset *src) {
    if (dest->node_array_length <= src->node_array_length)
        return 0;
    int i;
    for (i = 0; i < src->node_array_length; i++){
        dest->node_array[i] = src->node_array[i];
    }
}

/**
 * Doubles the size of the stringset and rehashes all of the elements inside it to fit the new size
 * @param str_set The string set to rehash
 */
void stringset_rehash(stringset *str_set) {
    stringset *new_str_set = stringset_new(str_set->node_array_length * 2,
                                           str_set->load_factor); //string set double the size


}
