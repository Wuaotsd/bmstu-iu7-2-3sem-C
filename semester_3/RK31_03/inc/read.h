#ifndef _READ_H_
#define _READ_H_

#include <stdio.h>
#include <stdlib.h>

int get_size_square_matrix(FILE *f, int *n, int *m);
int read_element_matrix(FILE *f, int **data, int n, int m);

#endif