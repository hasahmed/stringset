//
// Created by Hasan Yusuf Ahmed on 12/28/17.
//

#ifndef STRINGSET_UTIL_H
#define STRINGSET_UTIL_H

#include "stringset.h"

unsigned long hash_code(stringset *str_set, const char *str);
void my_strcpy(char *dest, const char *src);
int my_strlen(const char *str);

#endif //STRINGSET_UTIL_H
