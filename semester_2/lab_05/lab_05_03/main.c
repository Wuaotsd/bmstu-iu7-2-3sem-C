/*
Для работы с целыми числами был выбран тип int, упорядочение 
файла осуществляется по возрастанию чисел и сортировка используется пузырькова
*/
#include <string.h>
#include "func_bfn.h"

int main(int argc, char **argv)
{
    if (argc != 3)
        return ARGS_ERROR;
    int rc = EXIT_SUCCESS;
    if (strcmp(argv[1], "c") == 0)
    {
        FILE *new_f;
        new_f = fopen(argv[2], "wb");
        rc = create_bfn(new_f);
        fclose(new_f);
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        FILE *read_f;
        read_f = fopen(argv[2], "rb");
        if (read_f == NULL)
            return NOT_FOUND_FILE;
        rc = printf_bfn(read_f);
        fclose(read_f);
    }
    else if (strcmp(argv[1], "s") == 0)
    {
        FILE *sort_f;
        sort_f = fopen(argv[2], "r+b");
        if (sort_f == NULL)
            return NOT_FOUND_FILE;
        rc = sort_bfn(sort_f);
    
        fclose(sort_f);
    }
    else
        rc = ARGS_ERROR;
    return rc;
}