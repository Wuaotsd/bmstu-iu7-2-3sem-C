#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_strcspn.h"
#define STR_LEN 257

int main(void)
{
    setbuf(stdout, NULL);
    char string[STR_LEN] = { 0 }; //= "Hello World!";
    char symbols[STR_LEN] = { 0 }; //= "1234567!/";
    fgets(string, STR_LEN, stdin);
    fgets(symbols, STR_LEN, stdin);
    
    size_t n = strcspn(string, symbols);
    size_t my_n = my_strcspn(string, symbols);
    if (n != my_n)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}