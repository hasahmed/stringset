//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//

#ifndef STRINGSET_STRINGSET_H
#define STRINGSET_STRINGSET_H
struct element{
    char *string;
    int length;
};
typedef struct element set_element;
struct string_set{
    set_element **element_array; //array of set_elements
    int element_array_length;
    int num_elements; //the actual number of elements allocated
};
typedef struct string_set stringset;

/**
 *
 * @param initial_size the size of the array that will hold the elements initially
 * @return returns a pointer to the stringset object allocated
 */
stringset* stringset_new(unsigned int initial_size);
void stringset_free(stringset *str_set);

#endif //STRINGSET_STRINGSET_H
