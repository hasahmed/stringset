#include <stdio.h>
#include <stdlib.h>
#include "stringset.h"

int main() {
    int (*add)(stringset*, const char*) = &stringset_add;
//    int (*rm)(stringset*, const char*) = &stringset_remove;
//    int (*chk)(stringset*, const char*) = &stringset_check;
    node *n = NULL;
    node_free_list(n);
    stringset *s = stringset_new(5, 0);
    // TODO: make it so that the string set doesn't need node_new to be called on every node before stringset_add is called
    int i = 0;
    stringset_add(s, "I love my wife Katherine Inez Ahmed");
    stringset_add(s, "I love my wife Katherine Inez Ahmed");
    stringset_add(s, "air heads");
    add(s, "tacos");
    add(s, "monster taco lettuce butt");
    stringset_check(s, "monster taco lettuce butt");
    stringset_check(s, "monster taco lettuce butt");
    stringset_check(s, "monster taco lettuce butt");
    i = stringset_check(s, "fart butt monkey cheese");
    stringset *s_copy = stringset_new(s->node_array_length, s->load_factor);
    stringset_copy(s_copy, s);
//    add(s_copy, "Katherine is my love");
    printf("%d\n", s_copy->num_elements);
    stringset_free(s);
//    stringset_free(s_copy);
    return 0;
}
