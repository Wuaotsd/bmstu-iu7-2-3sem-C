#ifndef _PRINT_STUDENTS_H_
#define _PRINT_STUDENTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void print_student(FILE *f, student_t *current);
void printf_students(FILE *f, node_t *studentlist);

#endif