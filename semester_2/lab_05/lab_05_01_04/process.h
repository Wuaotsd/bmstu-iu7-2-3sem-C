#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <stdio.h>
#include <stdlib.h>
#define ERR_PARAMS -1
#define SEQUENCE_EMPTY_END -2
#define NOT_FOUND_FIGURES -3

int process(FILE *f, int *count);
#endif 