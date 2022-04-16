#include "func_tfp.h"

int fgets_st(char *str, int n, FILE *f)
{
    int i = 0, error = EXIT_SUCCESS;
    char ch;
    while ((ch = fgetc(f)) != '\n' && ch != EOF)
    {
        if (i > n - 1)
        {
            error = ERR_MEM;
            break;
        }
        str[i++] = ch;
    }
    if (i == 0)
        error = ERR_IO;

    if (error == EXIT_SUCCESS)
        str[i++] = '\0';
    return error;
}

int read_student_info(FILE *f, st *student)
{
    int i = 0, num;
    //char buf[8];
    int rc = EXIT_SUCCESS;
    if (f == NULL)
        return ERR_PARAMS;
    int len;
    if ((rc = fgets_st(student->lastname, sizeof(student->lastname), f)) != EXIT_SUCCESS)
        return rc;
    len = strlen(student->lastname);
    if (student->lastname[len - 1] == '\n')
        student->lastname[len - 1] = '\0';
    
    if ((rc = fgets_st(student->firstname, sizeof(student->firstname), f)) != EXIT_SUCCESS)
        return rc;
    len = strlen(student->firstname);
    if (student->firstname[len - 1] == '\n')
        student->firstname[len - 1] = '\0';
    //if (fscanf(f, "%u%u%u%u", &student->marks[0], &student->marks[1], &student->marks[2], &student->marks[3]) != 4)
    //    return INCORECT_ST;
    while (fscanf(f, "%d", &num) == 1)
    {    
        if (i > N - 1 || num < 0)
        {
            rc = INCORECT_ST;
            break;
        }
        student->marks[i] = num;
        i++;
    }
    if (i < N)
        rc = INCORECT_ST;
    //fgets(buf, sizeof(buf), f);
    return rc;
}

int read_students(FILE *f, st *arr, int *n)
{
    if (f == NULL || arr == NULL || n == NULL || !(*n == 0))
       return ERR_PARAMS;
       
    st cur;
    int i = 0;
    int rc = EXIT_SUCCESS;
    while (rc == EXIT_SUCCESS)
    {
        rc = read_student_info(f, &cur);
        if (rc == EXIT_SUCCESS)
        {
            if (i <= SIZE_ARR)
            {
                arr[i] = cur;
                i++;
            }
            else
                rc = ERR_MEM;
        }
        *n = i;
    }
    if (i <= 0)
        return FILE_IS_EMPTY;
    if (rc == ERR_IO)
        rc = EXIT_SUCCESS;
    return rc;
}

void print_st_info_file(FILE *f, st *student)
{
    fprintf(f, "%s\n", student->lastname);
    fprintf(f, "%s\n", student->firstname);
    fprintf(f, "%u %u %u %u\n", student->marks[0], student->marks[1], student->marks[2], student->marks[3]);
}

void printf_st(FILE *f, st *arr, int n)
{
    for (int i = 0; i < n; i++)
        print_st_info_file(f, &arr[i]);
}

int surname_fstr(FILE *f, st *arr, int n, char *str)
{   
    int j = 0;
    for (int i = 0; i < n; i++)
        if (strstr(arr[i].lastname, str) != NULL)
        {
            print_st_info_file(f, &arr[i]);
            j++;
        }
    return j;
}