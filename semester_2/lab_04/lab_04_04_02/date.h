#ifndef _DATE_H_
#define _DATE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN   257 
#define WORD_LEN  17
#define ARR_WORD  16
#define MONTH     12
#define MONTH_LEN 10

#define STR_LEN_ERR        -1
#define STR_FULL_ERR       -2
#define STR_EMPTY_ERR      -3
#define WORD_FULL_ERR      -4
#define WORD_ARR_ERR       -5
#define WORD_EMPTY_ERR     -6

int gets_str(char *str, int n);

int split_word(char *str, char (*words)[WORD_LEN], int *n);

int check_months(char *str1, char (*str2)[MONTH_LEN]);

int my_isdigit(char *str);

int check_ndate(char *str, int max_day);

int check_year(char *str);

int char_to_int(char *str);

int check_high_grade_year(char *str);

int check_data_day(char *str);

#endif