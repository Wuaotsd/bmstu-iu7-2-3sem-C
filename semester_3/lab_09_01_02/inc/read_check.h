#ifndef _READ_CHECK_H
#define _READ_CHECK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "struct_subject.h"
#include "errors.h"

int check_prefix(char *str, char *prefix);
int file_is_empty(FILE *f);

#endif //_READ_CHECK_H
