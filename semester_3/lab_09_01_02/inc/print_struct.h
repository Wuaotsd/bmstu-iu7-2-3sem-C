#ifndef _PRINT_STRUCT_H
#define _PRINT_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_subject.h"
#include "errors.h"

void print_struct_info(FILE *f, subject_t *subject);
void printf_struct(FILE *f, subject_t *arr, size_t n);
int print_struct_begining_string(FILE *f, subject_t *arr, size_t n, char *str);

#endif //_PRINT_STRUCT_H