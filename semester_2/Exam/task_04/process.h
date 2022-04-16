#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define ARR_WORD 21
#define WORD_LEN 16

#define ARR_FULL_ERR   1
#define WORD_FULL_ERR  2
#define INCORRECT_ERR  3
#define PARAM_ERR      4
#define NOT_FOUND_FILE 5

typedef struct 
{
    char name[WORD_LEN];
    size_t mark;
} student;

int my_fscanf(FILE *f, student *arr, size_t *n);
void my_print_avg(student *arr, size_t n, int avg);
int find_avta(student *arr, size_t n);
#endif