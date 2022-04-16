#include "process.h"

int my_read_file(FILE *f, char (*words)[LENGHT_STRING + 1], size_t *n)
{
    int i = 0, rc = EXIT_SUCCESS;
    char end[] = "STOP";
    _Bool flag = 0;
    while (!feof(f) && rc == EXIT_SUCCESS)
    {
        if (i > LENGHT_ARRAY)
        {
            rc = ARRAY_OVERFLOW;
            break;
        }
        if (!fscanf(f, "%s", words[i]))
            rc = INCORRECT_FILE;
        if (strcmp(words[i], end) == 0)
        {
            flag = 1;
            break;
        }
        if (strlen(words[i]) > LENGHT_STRING + 1)
            rc = STRING_OVERFLOW;
        i++;
    }
    if (!flag && rc == EXIT_SUCCESS)
       rc = STOP_ERR;
    if (i == 0)
        rc = FILE_IS_EMPTY;
    *n = i;
    return rc;
}

void print_data(char (*words)[LENGHT_STRING + 1], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%s\n", words[i]);
}

void del_word(char (*words)[LENGHT_STRING + 1], size_t *n, size_t ii)
{
    for (size_t i = ii; i < (*n) - 1; i++)
        strcpy(words[i], words[i + 1]);
    (*n)--;
}

int stay_only_a_o_with_words(char (*words)[LENGHT_STRING + 1], size_t *n)
{
    int rc = EXIT_SUCCESS;
    for (size_t i = 0; i < *n; i++)
        if (strpbrk(words[i], "AOao") == NULL)
        {
            del_word(words, n, i);
            i--;
        }
    if (*n == 0)
        rc = EXIT_FAILURE;
    return rc;
}

int numbers_only_a_o_with_words(char (*words)[LENGHT_STRING + 1], size_t *n)
{
    int count = 0;
    for (size_t i = 0; i < *n; i++)
        if (strpbrk(words[i], "AOao") != NULL)
            count++;
    return count;
}
