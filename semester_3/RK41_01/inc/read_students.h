#ifndef _READ_STUDENTS_H_
#define _READ_STUDENTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "list_op.h"
#include "errors.h"

int read_student(FILE *f, student_t *student);
int read_students(FILE *f, node_t **studentlist);

#endif