#include <stdio.h>
#include "stringset.h"

int main() {
//    int (*add)(stringset*, const char*) = &stringset_add;
//    int (*rm)(stringset*, const char*) = &stringset_remove;
//    int (*chk)(stringset*, const char*) = &stringset_check;
    stringset *s = stringset_new(100, 0.0);
    printf("%d\n", s->num_elements);
//    int i = 0;
    stringset_add(s, "I love my wife Katherine Inez Ahmed");
//    printf("%d\n", s->num_elements);
//    stringset_add(s, "I love my wife Katherine Inez Ahmed");
//    printf("%d\n", s->num_elements);
//    stringset_add(s, "air heads");
//    add(s, "tacos");
//    add(s, "monster taco lettuce butt");
//    stringset_check(s, "monster taco lettuce butt");
//    stringset_check(s, "monster taco lettuce butt");
//    stringset_check(s, "monster taco lettuce butt");
//    i = stringset_check(s, "fart butt monkey cheese");
//    stringset_remove(s, "monster taco lettuce butt");
//    stringset_remove(s, "I love my wife Katherine Inez Ahmed");
//    stringset_remove(s, "air heads");
//    stringset_remove(s, "tacos");
//    printf("%u\n", s->node_array_length);
    stringset_free(s);
    return 0;
}
