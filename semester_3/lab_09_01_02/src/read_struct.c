#include "read_struct.h"

#define BUFF_SIZE 8

void default_subject(subject_t *subject)
{
    subject->name_subject = NULL;
    subject->weight = 0.0;
    subject->volume = 0.0;
}

int get_size_string(FILE *f)
{
    char buff_symbol;
    int count = 0;
    while ((buff_symbol = (char) fgetc(f)) != '\n' && buff_symbol != EOF)
        count++;

    return count;
}

int get_size_struct(FILE *f, size_t *size)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL || *size != 0)
        rc = PARAMS_ERR;
    else
    {
        int count = 0;
        double buff_d;
        char buff_c;
        int count_name = 0;
        while ((buff_c = fgetc(f)) != EOF && rc == EXIT_SUCCESS)
        {
            count_name = 0;
            while ((buff_c = fgetc(f)) != '\n' && buff_c != EOF)
                count_name++;
            if (count_name == 0)
                rc = STRUCT_ERROR;
            else
            {
                if (fscanf(f, "%lf", &buff_d) != 1)
                    rc = STRUCT_ERROR;
                else if (buff_d <= 0)
                    rc = NEGATIVE_DATA;
                else
                {
                    if (fscanf(f, "%lf", &buff_d) != 1)
                        rc = STRUCT_ERROR;
                    else if (buff_d <= 0)
                        rc = NEGATIVE_DATA;
                    else
                    {
                        while ((buff_c = fgetc(f)) != '\n' && buff_c != EOF);
                        count++;
                    }
                }
            }
        }
        if (count == 0 && rc == EXIT_SUCCESS)
            rc = FILE_IS_EMPTY;
        if (rc == EXIT_SUCCESS)
            *size = count;
    }
    return rc;
}

void trim_beg_end_str(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (isspace(str[i]))
            str[i] = ' ';
        if ((isspace(str[i]) && i == 0) || (isspace(str[i]) && !(isspace(str[i - 1]) == 0 && isspace(str[i + 1]) == 0)))
        {
            str_shift_left(str, i);
            i--;
        }
    }
}

void str_shift_left(char *str, size_t i)
{
    for (size_t j = i; str[j] != '\0'; j++)
        str[j] = str[j + 1];
}

int read_struct_info(FILE *f, subject_t *subject, size_t count_st)
{
    int len;
    char buf[BUFF_SIZE];
    int rc = EXIT_SUCCESS;
    if (f == NULL)
        rc = PARAMS_ERR;
    else
    {
        int size = 0;
        size = get_size_string(f);
        if (size > 0)
        {
            fseek(f, 0, SEEK_SET);
            for (int i = 0; i < count_st; i++)
            {
                double buff;
                char buff_c;
                while ((buff_c = fgetc(f)) != '\n' && buff_c != EOF);
                fscanf(f, "%lf", &buff);
                fscanf(f, "%lf", &buff);
                while ((buff_c = fgetc(f)) != '\n' && buff_c != EOF);
            }
            subject->name_subject = allocate_malloc_string(size + 1);
            if (!subject->name_subject)
                rc = MEMORY_ERR;
            else
            {
                if (fgets(subject->name_subject, size + 1, f) == NULL)
                    rc = ERR_IO;
                else
                {
                    trim_beg_end_str(subject->name_subject);
                    len = strlen(subject->name_subject);
                    if (subject->name_subject[len - 1] == '\n')
                        subject->name_subject[len - 1] = '\0';
                    if (len <= 0)
                        rc = STRUCT_ERROR;
                    else
                    {
                        if (fscanf(f, "%lf", &subject->weight) != 1)
                            rc = STRUCT_ERROR;
                        if (fscanf(f, "%lf", &subject->volume) != 1)
                            rc = STRUCT_ERROR;
                        if (subject->weight <= 0 || subject->volume <= 0)
                            rc = NEGATIVE_DATA;
                        fgets(buf, sizeof(buf), f);
                    }
                }
            }
        }
        else
            rc = ERR_IO;
    }

    return rc;
}

int read_struct(FILE *f, subject_t **arr, size_t *n)
{
    int rc = EXIT_SUCCESS;
    if (f == NULL || *arr != NULL || arr == NULL || *n != 0)
        rc = PARAMS_ERR;
    else
    {
        subject_t cur;
        int i = 0;

        rc = get_size_struct(f, n);
        if (rc == EXIT_SUCCESS)
        {
            rewind(f);

            *arr = allocate_malloc_structs(*n);
            if (!*arr)
                rc = MEMORY_ERR;
            else
                for (size_t i = 0; i < *n; i++)
                    default_subject((*arr + i));
            while (rc == EXIT_SUCCESS)
            {
                rc = read_struct_info(f, &cur, i);
                if (rc == EXIT_SUCCESS)
                {
                    *(*arr + i) = cur;
                    i++;
                }
            }
            if (rc == ERR_IO)
                rc = EXIT_SUCCESS;
        }
    }

    return rc;
}

