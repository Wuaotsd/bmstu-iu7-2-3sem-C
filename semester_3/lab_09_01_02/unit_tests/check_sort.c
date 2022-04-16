#include "check_sort.h"
#include "struct_subject.h"
#include "read_struct.h"
#include "sort_struct.h"
#include "memory.h"

#define EPS 1e-8
#define UNIT_TESTS_FILE "unit_test.txt"
#define WRITE_SEQUENCE(fd, sequence) \
    rewind((fd));                    \
    fprintf((fd), sequence);         \
    rewind((fd));


// TESTING - void sort_array_by_density(subject_t *arr, size_t n)
int test_sort_array_by_density(void)
{
    int pos_cnt = 0, test_pos = 2;

    {
        int rc = EXIT_SUCCESS;
        subject_t *arr = NULL, *result = NULL;
        size_t n_arr = 0, n_res = 0;

        FILE *f = fopen(UNIT_TESTS_FILE, "w+");
        WRITE_SEQUENCE(f, "Maggi\n"
                          "67.0\n"
                          "45.0\n"
                          "AKVA\n"
                          "100\n"
                          "0.5\n"
                          "CLEAR Men\n"
                          "30\n"
                          "0.4\n"
                          "Genius\n"
                          "50\n"
                          "0.2\n"
                          "Genius\n"
                          "7\n"
                          "0.1\n"
                          "Geros\n"
                          "10\n"
                          "7\n");

        rc = read_struct(f, &arr, &n_arr);
        if (rc == EXIT_SUCCESS)
        {
            WRITE_SEQUENCE(f, "Geros\n"
                              "10.000000\n"
                              "7.000000\n"
                              "Maggi\n"
                              "67.000000\n"
                              "45.000000\n"
                              "Genius\n"
                              "7.000000\n"
                              "0.100000\n"
                              "CLEAR Men\n"
                              "30.000000\n"
                              "0.400000\n"
                              "AKVA\n"
                              "100.000000\n"
                              "0.500000\n"
                              "Genius\n"
                              "50.000000\n"
                              "0.200000\n");

            rc = read_struct(f, &result, &n_res);
            if (rc == EXIT_SUCCESS)
            {
                sort_array_by_density(arr, n_arr);
                int eq = 0;
                for (int i = 0; i < n_arr; i++)
                    if (strcmp(arr[i].name_subject, result[i].name_subject) != 0  || fabs(arr[i].weight - result[i].weight) >= EPS || fabs(arr[i].volume - result[i].volume) >= EPS)
                        eq = 1;

                if (eq)
                    pos_cnt++;
            }
            free_structs(&result, n_res);
        }
        free_structs(&arr, n_arr);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    {
        int rc = EXIT_SUCCESS;
        subject_t *arr = NULL, *result = NULL;
        size_t n_arr = 0, n_res = 0;

        FILE *f = fopen(UNIT_TESTS_FILE, "w+");
        WRITE_SEQUENCE(f, "Maggi\n"
                          "67.0\n"
                          "45.0\n"
                          "Maggi\n"
                          "67.0\n"
                          "45.0\n"
                          "Maggi\n"
                          "67.0\n"
                          "45.0\n"
                          "Maggi\n"
                          "67.0\n"
                          "45.0\n"
                          "Maggi\n"
                          "67.0\n"
                          "45.0\n"
                          "Maggi\n"
                          "67.0\n"
                          "45.0\n");

        rc = read_struct(f, &arr, &n_arr);
        if (rc == EXIT_SUCCESS)
        {
            rewind(f);
            rc = read_struct(f, &result, &n_res);
            if (rc == EXIT_SUCCESS)
            {
                sort_array_by_density(arr, n_arr);
                int eq = 0;
                for (int i = 0; i < n_arr; i++)
                    if (strcmp(arr[i].name_subject, result[i].name_subject) != 0  || fabs(arr[i].weight - result[i].weight) >= EPS || fabs(arr[i].volume - result[i].volume) >= EPS)
                        eq = 1;

                if (eq)
                    pos_cnt++;
            }
            free_structs(&result, n_res);
        }
        free_structs(&arr, n_arr);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return pos_cnt;
}
