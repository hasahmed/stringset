#include <stdio.h>
#include "stringset.h"

int main() {
    node *n = NULL;
    node_free_list(n);
    stringset *s = stringset_new(5);
    int i = 0;
    for (i = 0; i < s->node_array_length; i++) {
        s->node_array[i] = node_new("hello", NULL);
    }
    /*list_print(*s->node_array);*/
    stringset_free(s);
//    stringset *s = stringset_new(10);
//    node *node_list = list_init();
//    node_init(node_list, "hello", NULL);
    char strbuf[1000];
//    for (i = 0; i < 1000; i++){
//        sprintf(strbuf, "%d", i);
//        node *n = list_insert_new_last(node_list, strbuf);
//        printf("%lu\n", hash_code(n->string));
//    }
//    list_print(node_list);
//    stringset_free(s);
//    node_free_list(node_list);
    return 0;
}
