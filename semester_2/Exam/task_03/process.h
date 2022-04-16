#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define ARR_WORD 21
#define WORD_LEN 16

#define ARR_FULL_ERR  1
#define WORD_FULL_ERR 2
#define INCORRECT_ERR 3
#define PARAM_ERR     4
#define NOT_FOUND_ERR 5

int my_fscanf(FILE *f, char (*words)[WORD_LEN], int *boolsign, size_t *n);

void my_prinf(char (*words)[WORD_LEN], int *boolsign, size_t n);

void my_swap(char *str_1, char * str_2);

void sort_words_sign(char (*words)[WORD_LEN], int *boolsign, size_t n);

#endif