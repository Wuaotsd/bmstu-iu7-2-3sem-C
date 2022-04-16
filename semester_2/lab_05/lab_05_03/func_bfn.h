#ifndef _FUNC_BFN_H_
#define _FUNC_BFN_H_

#include <stdio.h>
#include <stdlib.h>
#define ERR_PARAM       -1
#define NOT_FOUND_FILE  -2
#define FILE_IS_EMPTY   -3
#define ARGS_ERROR      -4
#define ERROR_IO        -5
#define ERR_READ        -6

int create_bfn(FILE *f);

int printf_bfn(FILE *f);

int sort_bfn(FILE *f);

int sizef(FILE *f, size_t *n);

int get_number_by_pos(FILE *f, int pos, int *num);

int put_number_by_pos(FILE *f, int pos, int num);

#endif