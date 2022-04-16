#ifndef _SORT_H
#define _SORT_H

#include <stdio.h>
#include <stdlib.h>

void buble_sort_array(int *arr, int size);
void swap_arr_element(int *arr, int i_1, int i_2);
void matrix_in_array(int **data, int *arr, int n, int m);
int sort_by_snake_left_down(int **data, int n, int m);

#endif