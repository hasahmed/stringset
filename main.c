#include <stdio.h>
#include "stringset.h"

int main() {
    stringset *s = stringset_new(10);
    printf("Hello, World!\n");
    stringset_free(s);
    return 0;
}