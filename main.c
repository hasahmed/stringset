#include <stdio.h>
#include <stdlib.h>
#include "stringset.h"

int main() {
    int (*add)(stringset*, const char*) = &stringset_add;
    int (*rm)(stringset*, const char*) = &stringset_remove;
    int (*chk)(stringset*, const char*) = &stringset_check;
    node *n = NULL;
    node_free_list(n);
    stringset *s = stringset_new(5, NULL);
    // TODO: make it so that the string set doesn't need node_new to be called on every node before stringset_add is called
    int i = 0;
    stringset_add(s, "I love my wife Katherine Inez Ahmed");
    stringset_add(s, "I love my wife Katherine Inez Ahmed");
    stringset_add(s, "air heads");
//    stringset_remove(s, "air heads");
//    stringset_remove(s, "air heads");
//    i = stringset_remove(s, "I love my wife Katherine Inez Ahmed");
//    i = stringset_remove(s, "I love my wife Katherine Inez Ahmed");
    i = add(s, "tacos");
    i = add(s, "monster taco lettuce butt");
    i = stringset_check(s, "monster taco lettuce butt");
    i = stringset_check(s, "monster taco lettuce butt");
    i = stringset_check(s, "monster taco lettuce butt");
    i = stringset_check(s, "fart butt monkey cheese");
    printf("%d\n", s->num_elements);
    stringset_free(s);
    return 0;
}
