//
// Created by Hasan Yusuf Ahmed on 12/28/17.
//

#include "util.h"
#include "stringset.h"

unsigned long hash_code(stringset *str_set, const char *str) { /* copied djb2 hashing algorithm */
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash % str_set->node_array_length;
}

void my_strcpy(char *dest, const char *src) {
    int i = 0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
}

int my_strlen(const char *str){
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}
