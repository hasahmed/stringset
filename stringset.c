//
// Created by Hasan Yusuf Ahmed on 11/19/17.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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
void node_init(node *n, char *string, node *next){
    n->string = (char*)malloc(sizeof(char) * strlen(string));
    strcpy(n->string, string);
    n->next = next;
}


/**
 * Creates a new node with a string and next node
 * string: The character array to place in the new node
 * next:   The node that will come after this new node
 */
node* node_new(char *string, node *next){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->string = (char*)malloc((sizeof(char) * strlen(string) + 1)); //+1 needed for null character
    strcpy(newnode->string, string);
    newnode->next = next;
    return newnode;
}

/**
 * n: The node to free
 */
void node_free(node *n){
    free(n->string);
    free(n);
}

/** 
 * Frees nodes starting at n unitl it reaches a node whos next is NULL
 * n: The begining of a linked list of nodes
 */
void node_free_list(node *n){
    if(!n) //if n is null, no need to free
        return;
    if (!n->next) { //if head->next == NULL
        node_free(n);
    }
    else {
        node_free_list(n->next);
        node_free(n);
    }
}


//list wise operations
node* list_insert_new_after(node *node_to_go_after, char *string){
    node *newnode = node_new(string, node_to_go_after->next);
    node_to_go_after->next = newnode;
    return newnode;
}
node* list_insert_new_last(node *n, char *string){
    if(!n->next) //check for nullitude
        return list_insert_new_after(n, string);
    return list_insert_new_last(n->next, string);
}
void list_print(node *n){
    if (!n->next){
        printf("node->string: %s\n", n->string);
    } else {
        printf("node->string: %s\n", n->string);
        list_print(n->next);
    }
}
