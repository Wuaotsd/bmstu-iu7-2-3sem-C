#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARAM_ERR        1
#define NOT_FOUND_FILE   2
#define FILE_IS_EMPTY    3
#define STOP_ERR         4
#define INCORRECT_FILE   5
#define STRING_OVERFLOW  6
#define ARRAY_OVERFLOW   7

#define LENGHT_STRING  20
#define LENGHT_ARRAY   15

typedef struct 
{
    char name[LENGHT_STRING + 1];
    int numbers;
} item;

int my_read_file(FILE *f, item *items, size_t *n);

void print_data(item *items, size_t n);

void buble_sort_string(item *items, size_t n);
#endif