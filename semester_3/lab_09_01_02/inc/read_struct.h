#ifndef _READ_STRUCT_H
#define _READ_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct_subject.h"
#include "errors.h"
#include "memory.h"

void default_subject(subject_t *subject);

int get_size_string(FILE *f);
int get_size_struct(FILE *f, size_t *size);
void trim_beg_end_str(char *str);
void str_shift_left(char *str, size_t i);

int check_file(FILE *file);
int read_struct_info(FILE *f, subject_t *subject, size_t count_st);
int read_struct(FILE *f, subject_t **arr, size_t *n);

#endif //_READ_STRUCT_H