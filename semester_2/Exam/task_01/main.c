#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 15
#define ARR_LEN 100

#define ARR_FULL -1;
#define WORD_FULL -2;
#define NUM_NOT -3;
#define NOT_FILE -4;

int fscanf_words(FILE *f, char (*words)[WORD_LEN], int *num, size_t *n)
{
    size_t i = 0, len;
    int r_w = 1, r_n = 1, rc = 0;
    while (!feof(f) && r_w == 1 && r_n == 1)
    {
        if (i >= ARR_LEN)
        {
            rc = ARR_FULL;
            break;
        }
        r_w = fscanf(f, "%s", words[i]);
        //puts(words[i]);
        len = strlen(words[i]);
        if (len > WORD_LEN)
        {
            r_w = 0;
            rc = WORD_FULL;
        }
        r_n = fscanf(f, "%d", &num[i]);
        if (r_n == 0)
            rc = NUM_NOT;
        i++;
    }
    *n = i;
    //printf("%d\n", rc);
    return rc;
}

int check_word(char *str)
{
    int i = 0;
    int glas = 0;
    int sogl = 0;
    while (str[i] != '\0')
    {
        if (str[i] == 'A' || str[i] == 'a' || 
        str[i] == 'Y' || str[i] == 'y' || 
        str[i] == 'E' || str[i] == 'e' || 
        str[i] == 'I' || str[i] == 'i' || 
        str[i] == 'O' || str[i] == 'o' ||
        str[i] == 'U' || str[i] == 'u')
            glas++;
        else
            sogl++;
        
        i++;
    }
    //printf("%d, %d", glas, sogl);
    if (glas > sogl)
        return 1;
    return 0;
}

void sum_num_word(char (*words)[WORD_LEN], int *num,  size_t n, int *sum)
{
    size_t i = 0;
    while (i < n)
    {
        if (check_word(words[i]))
            (*sum) += num[i];
        i++;
    }
}

int main(void)
{
    FILE *f_in;
    int rc = EXIT_SUCCESS;
    int num[ARR_LEN];
    char words[ARR_LEN][WORD_LEN];
    size_t n;
    int sum = 0;
    
    f_in = fopen("in.txt", "r");
    if (f_in == NULL)
        return NOT_FILE;
    rc = fscanf_words(f_in, words, num, &n);
    fclose(f_in);
    if (rc != EXIT_SUCCESS)
        return rc;
    sum_num_word(words, num, n, &sum);
    printf("Sum = %d\n", sum);
    return rc;
}