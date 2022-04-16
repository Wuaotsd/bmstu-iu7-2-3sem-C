#ifndef _MEMORY_COUNTRIES_H
#define _MEMORY_COUNTRIES_H

#include <stdio.h>
#include <stdlib.h>

#include "struct_country.h"
#include "errors.h"

char *allocate_name_str(int len);
void free_name_str(char **str);

country_t *allocate_struct_country(int size);
void free_struct_country(country_t **data, int *n);

#endif //_MEMORY_COUNTRIES_H
