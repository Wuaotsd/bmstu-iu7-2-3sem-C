#include "print_countries.h"

void fprint_country(FILE *f, country_t *country)
{
    fprintf(f, "%s\n", country->name_country);
    fprintf(f, "%s\n", country->name_capital);
    fprintf(f, "%ld\n", country->population);
}

void fprint_countries(FILE *f, country_t *countries, int n)
{
    if (f == NULL)
        printf("Запись неуспешна!\n");
    else if (countries == NULL)
        printf("Записей нет!\n");
    else
        for (int i = 0; i < n; i++)
            fprint_country(f, countries + i);
}

void print_error(int rc)
{
    switch (rc)
    {
        case PARAMS_ERROR:
            printf("Ошибка! Параметры переданные в функции не верны!\n");
            break;
        case FILE_NOT_FOUND:
            printf("Ошибка! Файл не найден!\n");
            break;
        case FILE_IS_EMPTY:
            printf("Ошибка! Файл пуст!\n");
            break;
        case RESULT_FILE:
            printf("Ошибка! Название файла для записи не корректное!\n");
            break;
        case ACTION_ERROR:
            printf("Ошибка! Программа не выполняет действие по такому ключу!\n");
            break;
        case ARGC_ERROR:
            printf("Ошибка! Командная стркоа не заполнена или переполнена данными!\n");
            break;
        case MEMORY_ERROR:
            printf("Ошибка! При выполнения операции память не удалось выделить!\n");
            break;
        case FIND_OVERFLOW:
            printf("Ошибка! В файла искомого элемента должен быть только одня запись!\n");
            break;
        case STRUCT_ERROR:
            printf("Ошибка! В файле неизвестная или некорректная запись!\n");
            break;
    }
}