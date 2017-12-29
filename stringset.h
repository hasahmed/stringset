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
stringset* stringset_new(unsigned int initial_size);
void stringset_free(stringset *str_set);
int stringset_add(const char* string);
int stringset_remove(const char* string);
int stringset_contains(const char* string);
unsigned long hash_code(char *str);



#endif //STRINGSET_STRINGSET_H
