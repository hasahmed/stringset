//
// Created by Hasan Yusuf Ahmed on 12/28/17.
//

#ifndef STRINGSET_NODE_H
#define STRINGSET_NODE_H
typedef struct node{
    char *string;
    struct node *next;
} node;

//node functions
node* node_new(const char *string, node *next);
node* node_new_ptr();
node *node_new_duplicate(node *n, node *next);
void node_free(node *n);
void node_free_list(node *n);
node * node_copy(node *src);
void node_list_insert_before(node *node_to_insert, node *node_to_go_before);
void node_init(node *n, char *string, node *next);
node* node_null();


//node list functions
node* list_insert_new_after(node *node_to_go_after, const char *string);
node* list_insert_new_last(node *n, char *string);
void list_remove_node(node *prev, node *current, const char *string);
void list_print(node *n);
node* list_init();
#endif //STRINGSET_NODE_H
