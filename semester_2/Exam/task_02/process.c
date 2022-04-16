#include "process.h"

int my_fscanf(FILE *f, char (*words)[WORD_LEN], int *boolsign, size_t *n)
{
    size_t i = 0, len;
    int r_w = 1, r_n = 1, rc = EXIT_SUCCESS;
    char end[] = "STOP";
    while (!feof(f) && r_n && r_w)
    {
        if (i >= ARR_WORD - 1)
        {
            rc = ARR_FULL_ERR;
            break;
        }
        r_w = fscanf(f, "%s", words[i]);
        if (r_w == 0)
        {
            rc = INCORRECT_ERR;
            break;
        }
        if (strcmp (words[i], end) == 0)
            break;
        len = strlen(words[i]);
        words[i][len] = '\0';
        if (len > WORD_LEN - 1)
        {
            rc = WORD_FULL_ERR;
            break;
        }
        r_n = fscanf(f, "%d", &boolsign[i]);
        if (r_n != 1 || (boolsign[i] != 0 && boolsign[i] != 1))
        {
            rc = INCORRECT_ERR;
            break;
        }
        i++;
    }
    *n = i;
    return rc;
}

void my_prinf(char (*words)[WORD_LEN], int *boolsign, size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%s %d\n", words[i], boolsign[i]);
}

void my_swap(char *str_1, char * str_2)
{
    size_t i = 0;
    for (i = 0; str_2[i] != '\0' ; i++)
        str_1[i] = str_2[i];
    str_1[i] = '\0';
}

void sort_words(char (*words)[WORD_LEN], int *boolsign, size_t n)
{
    char buff_c[WORD_LEN];
    int buff_b;
    
    //printf("%zu\n", n);
    for (size_t i = 0; i < n; i++)
        for (size_t j = i + 1; j < n; j++)
        {
            //printf("%s , %s\n\n", words[i], words[j]);
            if (strcmp(words[i], words[j]) > 0)
            {
                
                my_swap(buff_c, words[i]);
                my_swap(words[i], words[j]);
                my_swap(words[j], buff_c);
                
                buff_b = boolsign[j];
                boolsign[j] = boolsign[i];
                boolsign[i] = buff_b;
            }
        }
}

