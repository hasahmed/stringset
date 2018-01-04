//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//

#ifndef STRINGSET_STRINGSET_H
#define STRINGSET_STRINGSET_H

#include "node.h"

struct string_set{
    int node_array_length;
    int num_elements; //the actual number of elements allocated
    node **node_array; //array of nodes
};
typedef struct string_set stringset;
stringset* stringset_new(unsigned int initial_size, unsigned int load_factor);
void stringset_free(stringset *str_set);
int stringset_add(stringset *str_set, const char* string);
int stringset_remove(stringset *str_set, const char* string);
int stringset_check(stringset *str_set, const char *str);

#endif //STRINGSET_STRINGSET_H
