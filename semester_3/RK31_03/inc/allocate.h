#ifndef _ALLOCATE_H_
#define _ALLOCATE_H_

#include <stdlib.h>

int **allocate_matrix(int n, int m);
void free_matrix(int ***data);

#endif