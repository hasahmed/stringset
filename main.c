#include <stdlib.h>
#include <stdio.h>
#include "stringset.h"

int main() {
    stringset *s = stringset_new(STRSET_DEFAULT, STRSET_DEFAULT);
    int i = 0;
    for (i = 0; i < 10000; i++)
        stringset_add(&s, "hello");
    // printf("%d\n", stringset_contains(&s, "hello"));
    // printf("%d\n", stringset_contains(&s, "llo"));
    // strll_free(s->strll_array[0]);
    // printf("%d\n", s->num_buckets);
    // strll_free(s->strll_array[0]);
    // free(s);
    stringset_free(&s);
    return 0;
}
