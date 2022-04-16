#ifndef _FUNC_STR_H_
#define _FUNC_STR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define STR_LEN 257 // длина строки с терминальным нулем
#define WORD_LEN 17 // длина слова с терминальным нулем
#define ARR_WORDS 16 // размер массива слова
#define WORDS_LIMIT 2 // лимит слов

#define STR_LEN_ERR        -1
#define STR_FULL_ERR       -2
#define STR_EMPTY_ERR      -3
#define WORD_FULL_ERR      -4
#define WORD_ARR_ERR       -5
#define WORD_EMPTY_ERR     -6
#define WORD_ONE_ERR       -7 
#define WORDS_SAME_ERR     -8

int gets_str(char *str, int n);

int check_str(char *str);

int split_word(char *str, char (*words)[WORD_LEN], int *n);

void stroc(char *str, char *stro);

int make_new_str(char (*words)[WORD_LEN], int len, char *new_str);

#endif 