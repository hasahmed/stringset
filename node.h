//
// Created by Hasan Yusuf Ahmed on 12/28/17.
//

#ifndef STRINGSET_NODE_H
#define STRINGSET_NODE_H
typedef struct node{
    char *string;
    struct node *next;
} node;
typedef struct node LinkedList;
//node functions
node* node_new(const char *string, node *next);
void node_free(node *n);
void node_free_list(node *n);
void node_list_insert_before(node *node_to_insert, node *node_to_go_before);


//node list functions
/**
 * Returns a pointer to 
 */
LinkedList* list_new();
node* list_insert_new_after(node *node_to_go_after, const char *string);
node* list_insert_new_last(node *n, char *string);
void list_remove_node(node *prev, node *current, const char *string);
void list_print(node *n);
#endif //STRINGSET_NODE_H
