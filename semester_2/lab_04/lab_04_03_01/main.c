#include "func_str.h"

int main(void)
{
    setbuf(stdout, NULL);
    char words[ARR_WORDS][WORD_LEN], str[STR_LEN], new_str[STR_LEN] = { 0 };
    int nword = 0, rc = EXIT_SUCCESS;
    printf("Input str: ");
    rc = gets_str(str, STR_LEN);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == STR_LEN_ERR)
            printf("STR_ERROR! The string is incorrect!");
        if (rc == STR_FULL_ERR)
            printf("STR_ERROR! The string lenght is upper 256 chars!");
        if (rc == STR_EMPTY_ERR)
            printf("STR_ERROR! The string wasn't entered!");
        return rc;
    }
    rc = split_word(str, words, &nword);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == WORD_FULL_ERR)
            printf("WORD_ERROR! The word lenght is upper 16 chars!");
        if (rc == WORD_ARR_ERR)
            printf("ARR_ERROR! The words is upper 16!");
        if (rc == WORD_EMPTY_ERR)
            printf("WORD_ERROR! Only end-signs of words are entered!");
        if (rc == WORD_ONE_ERR)
            printf("WORD_ERROR! Entered only one word!");
        return rc;
    }
    rc = make_new_str(words, nword, new_str);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == WORDS_SAME_ERR)
            printf("WORD_ERROR! The words is same!");
        return rc;
    }
    printf("Result: %s\n", new_str);
    return rc;
}