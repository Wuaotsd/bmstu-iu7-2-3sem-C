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

int my_read_file(FILE *f, char (*words)[LENGHT_STRING + 1], size_t *n);

void print_data(char (*words)[LENGHT_STRING + 1], size_t n);
int stay_only_a_o_with_words(char (*words)[LENGHT_STRING + 1], size_t *n);
void del_word(char (*words)[LENGHT_STRING + 1], size_t *n, size_t ii);
int numbers_only_a_o_with_words(char (*words)[LENGHT_STRING + 1], size_t *n);
#endif