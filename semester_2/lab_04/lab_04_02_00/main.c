#include "check_word.h"

void process(char (*words)[WORD_LEN], size_t n, char (*meet_words)[WORD_LEN], int num_meet_words[WORD_LEN], size_t *n_w);

void print_result(char (*meet_words)[WORD_LEN], int num_meet_words[WORD_LEN], size_t n_w);

int main(void)
{
    char string[STR_LEN], words[ARR_LEN][WORD_LEN], meet_words[ARR_LEN][WORD_LEN]; // массив для слов meet_words по одному вхождению в строку
    int num_meet_words[WORD_LEN]; // массив для количеств слов
    int rc;
    size_t n = 0, n_w = 0;
	
    setbuf(stdout, NULL);
    printf("Input str: ");
    rc = gets_str(string, STR_LEN);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == STR_FULL_ERR)
            printf("STR_ERR! The string lenght is upper 256 chars!");
        if (rc == STR_EMPTY_ERR)
            printf("STR_ERR! The string wasn't entered!");
        return rc;
    }
    rc = split_word(string, words, &n);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == WORD_FULL_ERR)
            printf("WORD_ERR! The word lenght is upper 16 chars!");
        if (rc == STR_EMPTY_END)
            printf("STR_ERR! The string was entered with only the symbols of end-words!");
        return rc;
    }
    process(words, n, meet_words, num_meet_words, &n_w);
    //printf("%zu", n_w);
    printf("Result: ");
    print_result(meet_words, num_meet_words, n_w);
    return rc;
}

void process(char (*words)[WORD_LEN], size_t n, char (*meet_words)[WORD_LEN], int num_meet_words[WORD_LEN], size_t *n_w)
{
    size_t i = 0, g = 0, k = 0, size = 0;
    int num, flag; 
    while (i < n)
    {
        num = 0;
        g = 0;
        flag = 0;
        k = 0;
        while (k < i)
        {
            if (check_words(words[i], words[k]))
            {
                flag = 1;
                break;
            }
            k++;
        }
        if (flag == 1)
        {
            i++;
            continue;
        }
		
        while (g < n)
        {
            if (check_words(words[i], words[g]))
                num++;
            g++;
        }
        size_t j = 0;
        while (words[i][j] != '\0')
        {
            meet_words[size][j] = words[i][j];
            j++;
        }
        meet_words[size][j] = '\0';
        num_meet_words[size] = num;
        i++;
        size++;
    }
    (*n_w) = size;
}

void print_result(char (*meet_words)[WORD_LEN], int num_meet_words[WORD_LEN], size_t n_w)
{
    size_t i = 0;
    while (i < n_w)
    {
        printf("%s", meet_words[i]);
        //for (size_t j = 0; meet_words[i][j] != '\0'; j++)
        //    printf("%c", meet_words[i][j]);
        printf(" %d\n", num_meet_words[i]);
        i++;
    }
}