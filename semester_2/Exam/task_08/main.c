#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define L_S 256
#define STRING_OVERFLOW 1
#define ARRAY_OVERFLOW  2
#define STRING_EMPTY    3


int split_word(char *str, char (*words)[L_S + 1], size_t *n)
{
    int rc = EXIT_SUCCESS;
    char *word;
    int i = 0;
    word = strtok(str, " ,;:-.!?");
    while (word != NULL)
    {
        if (i > L_S)
            return ARRAY_OVERFLOW;

        strcpy(words[i], word);
        i++;
        word = strtok(NULL, " ,;:-.!?");
    }
    if (i <= 0)
        return STRING_EMPTY;
    *n = i;
    return rc;
}

int gets_str(char *str)
{
    if (fgets(str, L_S + 2, stdin) == NULL)
        return -1;
    int len = strlen(str);
    if (len > L_S)
        return STRING_OVERFLOW;
    if (len == 1)
        return STRING_EMPTY;
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
    return EXIT_SUCCESS;
}

void del_word(char (*words)[L_S + 1], size_t *n, size_t ii)
{
    for (size_t i = ii; i < (*n) - 1; i++)
        strcpy(words[i], words[i + 1]);
    (*n)--;
}

void del_duplicate_words(char (*words)[L_S + 1], size_t *n)
{
    for (size_t i = 0; i < (*n) - 1; i++)
        for (size_t j = i + 1; j < *n; j++)
            if (strcmp(words[i], words[j]) == 0)
            {
                del_word(words, n, j);
                j--;
            }
}

void print_words(char (*words)[L_S + 1], size_t n)
{
    for (size_t i = 0; i < n; i++)
        puts(words[i]);
}
int main()
{
    int rc = EXIT_SUCCESS;
    char str[L_S + 1] = { 0 };
    char words[L_S][L_S + 1];
    size_t n;
    rc = gets_str(str);
    if (rc != EXIT_SUCCESS)
        return rc;
    rc = split_word(str, words, &n);
    if (rc != EXIT_SUCCESS)
       return rc;
    del_duplicate_words(words, &n);
    //printf("%zu\n", n);
    print_words(words, n);
    return rc;
}