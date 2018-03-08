#include <stdlib.h>
#include <stdio.h>
#include "stringset.h"

int main() {
    stringset *s = stringset_new(1, 0);
    stringset **ss = &s;
    // strll_free(s->strll_array[0]);
    // printf("%d\n", s->num_buckets);
    // strll_free(s->strll_array[0]);
    // free(s);
    stringset_free(ss);
    return 0;
}
