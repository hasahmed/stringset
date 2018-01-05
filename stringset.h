//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//

#ifndef STRINGSET_STRINGSET_H
#define STRINGSET_STRINGSET_H

#include "node.h"

struct string_set{
    unsigned int node_array_length;
    unsigned int num_elements; //the actual number of elements allocated
    node **node_array; //array of nodes
    float load_factor;
};
typedef struct string_set stringset;
stringset* stringset_new(unsigned int initial_size, float load_factor);
void stringset_free(stringset *str_set);
int stringset_add(stringset *str_set, const char* string);
int stringset_remove(stringset *str_set, const char* string);
int stringset_check(stringset *str_set, const char *str);
void stringset_rehash(stringset *str_set);
int stringset_copy(stringset *dest, stringset *src);
int stringset_deepcopy(stringset *dest, stringset *src);

#endif //STRINGSET_STRINGSET_H
