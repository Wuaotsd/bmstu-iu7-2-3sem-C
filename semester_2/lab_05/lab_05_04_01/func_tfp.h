#ifndef _FUNC_TFP_H_
#define _FUNC_TFP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define L_N 25
#define F_N 10
#define N 4
#define SIZE_ARR 10

#define ERR_PARAMS     -1
#define ERR_MEM        -2
#define ERR_IO         -3
#define NOT_FOUND_FILE -4
#define FILE_IS_EMPTY  -5
#define INCORECT_ST    -6

typedef struct
{
    char lastname[L_N + 1];
    char firstname[F_N + 1];
    uint32_t marks[N];
} st;
// в файле read_st.c
int read_student_info(FILE *f, st *student);

int read_students(FILE *f, st *arr, int *n);

void print_st_info_file(FILE *f, st *student);

void printf_st(FILE *f, st *arr, int n);

int surname_fstr(FILE *f, st *arr, int n, char *str);
// в файле sort_st.c 
void sort_students(st *arr, int n);
// в файле del_st.c
float average_calc(st *arr, int n, float *mas_avr);

void del_student(st *arr, float *mas_avr, int *n, float s_sr);

#endif