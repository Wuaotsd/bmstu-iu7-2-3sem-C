#include "my_funcs.h"

int main(void)
{
    setbuf(stdout, NULL);
    
    int count = 0, rc = EXIT_SUCCESS;
    fprintf(stdout, "Введите последовательность, оканчивающимся концевым признаком (не цифра):\n");
    rc = proccess(stdin, &count);
    if (rc != EXIT_SUCCESS)
    {
        if (rc == PARAM_ERR)
            fprintf(stderr, "Warning! Неправильные параметры функции!");
        if (rc == INPUT_ERR)
            fprintf(stderr, "Warning! Последовательность должна быть состоит больше чем 1 число или введен просто концевой признак!");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "Наибольшее количество чисел схожие другом с другом в последовательноти - %d.", count);
    return EXIT_SUCCESS;
}