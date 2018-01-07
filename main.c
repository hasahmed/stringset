#include <stdio.h>
#include "stringset.h"

int main() {
    int (*add)(stringset*, const char*) = &stringset_add;
//    int (*rm)(stringset*, const char*) = &stringset_remove;
//    int (*chk)(stringset*, const char*) = &stringset_check;
    stringset *s = stringset_new(5, 0.0);
//    stringset_add(s, "hello");
//    int i = 0;
//    i = stringset_check(s, "hello");
//    printf("%d\n", i);
//    stringset_rehash(s);
//    stringset_add(s, "hellos");
//    i = stringset_check(s, "hello");
//    printf("%d\n", i);
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
    printf("%d\n", s->num_elements);
    stringset_remove(s, "monster taco lettuce butt");
    stringset_remove(s, "I love my wife Katherine Inez Ahmed");
    stringset_remove(s, "air heads");
    stringset_remove(s, "tacos");
    printf("%d\n", s->node_array_length);
    printf("%d\n", s->num_elements);
    stringset_rehash(s);
    printf("%d\n", s->node_array_length);
    stringset_free(s);
    return 0;
}
