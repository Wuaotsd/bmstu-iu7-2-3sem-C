#ifndef _MEMORY_H
#define _MEMORY_H

#include <stdlib.h>
#include "struct_subject.h"

char *allocate_malloc_string(size_t len);
void free_string(char **str);

subject_t *allocate_malloc_structs(size_t n);
void free_structs(subject_t **arr, size_t n);

#endif //_MEMORY_H

