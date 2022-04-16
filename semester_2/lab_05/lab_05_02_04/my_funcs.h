#ifndef _MY_FUNCS_H_
#define _MY_FUNCS_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PARAM_ERR      1
#define INCORRECT_FILE 2
#define NOT_FOUND_FILE 3
#define NOT_AVG_ERR    4
#define EPS            1e-8

int proccess(FILE *f, double *avg);

#endif