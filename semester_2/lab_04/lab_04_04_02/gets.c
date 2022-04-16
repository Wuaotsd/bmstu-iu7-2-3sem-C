#include "date.h"

int gets_str(char *str, int n)
{
    int i = 0, rc = EXIT_SUCCESS;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        if (isspace(ch))
            ch = ' ';
        str[i++] = ch;
        if (i > n - 1)
        {
            rc = STR_FULL_ERR;
            break;
        }
    }	
    if (i == 0)
        rc = STR_EMPTY_ERR;

    if (rc == EXIT_SUCCESS)
        str[i++] = '\0';
    return rc;
}

int split_word(char *str, char (*words)[WORD_LEN], int *n)
{
    int rc = EXIT_SUCCESS;
    int i = 0, j;
    char *word;
    word = strtok(str, " ");
    if (word == NULL)
        return STR_EMPTY_ERR;
    while (word != NULL)
    {
        j = 0;
        while (word[j++] != '\0');
        if (j > WORD_LEN - 1)
            return WORD_FULL_ERR;

        if (i > ARR_WORD)
            return WORD_ARR_ERR;
        strcpy(words[i++], word);
        word = strtok(NULL, " ");
    }
    *n = i;
    return rc;
}