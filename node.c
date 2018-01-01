//
// Created by Hasan Yusuf Ahmed on 12/28/17.
//

#include <stdlib.h>
//#include <string.h>
#include <stdio.h>
#include "node.h"
#include "util.h"

void node_init(node *n, char *string, node *next){
    n->string = (char*)malloc(sizeof(char) * my_strlen(string));
    my_strcpy(n->string, string);
    n->next = next;
}
/**
 * Creates a new node with a string and next node
 * string: The character array to place in the new node
 * next:   The node that will come after this new node
 */
node* node_new(const char *string, node *next){
    node *newnode = (node*)malloc(sizeof(node));
    newnode->string = (char*)malloc((sizeof(char) * my_strlen(string) + 1)); //+1 needed for null character
    my_strcpy(newnode->string, string);
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
//node list stuff
/**
 * Frees nodes starting at n unitl it reaches a node whos next is NULL
 * n: The begining of a linked list of nodes
 */
void node_free_list(node *n){
    node *tmp = n;
    while(tmp != NULL){
        node *current = tmp;
        tmp = tmp->next;
        node_free(current);
    }
}

node* list_insert_new_after(node *node_to_go_after, const char *string){
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
void list_remove_node(node *prev, node *to_be_removed, const char *string) {
    prev->next = to_be_removed->next;
    node_free(to_be_removed);
}
