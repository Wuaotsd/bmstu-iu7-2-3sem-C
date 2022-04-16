#include "func_str.h"

// разделение строки на слова
int split_word(char *str, char (*words)[WORD_LEN], int *n)
{
    int rc = EXIT_SUCCESS;
    rc = check_str(str);
    if (rc != EXIT_SUCCESS)
        return rc;
    
    char *word;
    int i = 0;
    word = strtok(str, " ,;:-.!?");
    
    while (word != NULL)
    {
        if (i > ARR_WORDS - 1)
            return WORD_ARR_ERR;

        strcpy(words[i], word);
        i++;
        word = strtok(NULL, " ,;:-.!?");
    }
    if (i <= 0)
        return WORD_EMPTY_ERR;
    if (i < WORDS_LIMIT)
        return WORD_ONE_ERR;
    *n = i;
    return rc;
}

void stroc(char *str, char *stro)
{
    int i = 1, j = 1;
    stro[0] = str[0];
    stro[1] = '\0';
    while (str[i] != '\0')
    {
        if (strchr(stro, str[i]) == NULL)
        {
            stro[j] = str[i];
            stro[j + 1] = '\0';
            j++;
        }
        i++;
    }
}

int make_new_str(char (*words)[WORD_LEN], int n, char *new_str)
{
    char word[WORD_LEN] = { 0 };
    int count = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (strcmp(words[i], words[n - 1]) != 0)
        {
            if (i != n - 2)
                strcat(new_str, " ");
            stroc(words[i], word);
            strcat(new_str, word);
            count++;
        }
    }
    if (count <= 0)
        return WORDS_SAME_ERR;
    return EXIT_SUCCESS;
}