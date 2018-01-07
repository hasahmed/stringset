#include <stdio.h>
#include "stringset.h"

int main() {
//    int (*add)(stringset*, const char*) = &stringset_add;
//    int (*rm)(stringset*, const char*) = &stringset_remove;
//    int (*chk)(stringset*, const char*) = &stringset_check;
    stringset *s = stringset_new(1, 0);
//    printf("%d\n", s->num_elements);
//    int i = 0;
    stringset_add(s, "I love my wife Katherine Inez Ahmed");
    stringset_add(s, "lettuce");
//    printf("%d\n", s->num_elements);
//    stringset_add(s, "I love my wife Katherine Inez Ahmed");
//    printf("%d\n", s->num_elements);
    stringset_add(s, "air heads");
    stringset_add(s, "ir heads");
    stringset_add(s, "r heads");
    stringset_add(s, " heads");
    int i = stringset_add(s, " heads");
    printf("result: %d\n", i);
    printf("elements: %u\n", s->num_elements);
    printf("length: %u\n", s->node_array_length);
    printf("load value: %f\n", stringset_load_value(s));
//    stringset_add(s, "heads");
//    stringset_add(s, "eads");
//    stringset_add(s, "ads");
//    stringset_add(s, "ds");
//    stringset_add(s, "s");
//    stringset_add(s, " ");
//    stringset_add(s, "j");
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
