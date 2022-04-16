#ifndef _CHECK_WORD_H_
#define _CHECK_WORD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 257
#define WORD_LEN 17
#define ARR_LEN  16

#define WORD_FULL_ERR  -2
#define STR_FULL_ERR   -3
#define STR_EMPTY_ERR  -4
#define STR_EMPTY_END  -5

int gets_str(char *str, int n);

int split_word(const char *str, char (*w)[WORD_LEN], size_t *n);

int check_words(const char *word_1, const char *word_2);

#endif 