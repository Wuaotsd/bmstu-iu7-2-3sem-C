#include "func_str.h"
// чтение строки с использование  
int gets_str(char *str, int n)
{
    int len;
    if (fgets(str, n + 2, stdin) == NULL)
        return STR_LEN_ERR;
    len = strlen(str); 
    if (len == n + 1)
        return STR_FULL_ERR;
    if (len == 1)
        return STR_EMPTY_ERR;
    if (str[len - 1] == '\n')
        str[len - 1] = '\0';
    return EXIT_SUCCESS;
}
// Проверка строки на перевполнение буфера в массиве слова
int check_str(char *str)
{
    int i = 0, j = 0;
    while (str[i] != '\0')
    {
        if (strchr(" ,;:-.!?", str[i]) != NULL)
            j = 0;
        else
            j++;
            
        if (j > WORD_LEN - 1)
            return WORD_FULL_ERR;
        i++;
    }
    return EXIT_SUCCESS;
}