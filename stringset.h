//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//

#ifndef STRINGSET_STRINGSET_H
#define STRINGSET_STRINGSET_H
/*
struct element{
    char *string;
    int length;
};
 */
//typedef struct element set_element;

typedef struct node{
    char *string;
    struct node *next;
} node;

struct string_set{
    int node_array_length;
    int num_elements; //the actual number of elements allocated
    node **node_array; //array of nodes
};
typedef struct string_set stringset;

/**
 *
 * @param initial_size the size of the array that will hold the elements initially
 * @return returns a pointer to the stringset object allocated
 */
stringset* stringset_new(unsigned int initial_size);
void stringset_free(stringset *str_set);
unsigned long hash_code(char *str);

//node functions
node* node_new(char *string, node *next);
void node_free(node *n);
void node_free_list(node *n);
void node_init(node *n, char *string, node *next);
node* node_null();


//list functions
node* list_insert_new_after(node *node_to_go_after, char *string);
node* list_insert_new_last(node *n, char *string);
void list_print(node *n);
node* list_init();

#endif //STRINGSET_STRINGSET_H
