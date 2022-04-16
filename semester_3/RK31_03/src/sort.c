#include "errors.h"
#include "sort.h"

void matrix_in_array(int **data, int *arr, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            arr[i * m + j] = data[i][j];
}
void swap_arr_element(int *arr, int i_1, int i_2)
{
    int buff = arr[i_1];
    arr[i_1] = arr[i_2];
    arr[i_2] = buff;
}

void buble_sort_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] > arr[j])
                swap_arr_element(arr, i, j);
}
int sort_by_snake_left_down(int **data, int n, int m)
{
    int rc = EXIT_SUCCESS;
    int *arr;
    arr = malloc(n * m * sizeof(int));
    if (!arr)
        rc = MEMORY_SORT_ERR;
    else
    {
        matrix_in_array(data, arr, n, m);
        buble_sort_array(arr, n * m);

        int arr_i = n * m - 1;
        int i_ind = 0, j_ind = m - 1, step_beg = 0, step_next = 1, num_move = 1;
        data[i_ind][j_ind] = arr[arr_i--];
        while (num_move < n * m)
        {
            if (step_next % 2 == 0)
            {
                if (step_beg == 0)
                {
                    if (j_ind != 0)
                    {
                        j_ind--;
                        step_beg = 1;
                    }
                    else
                    {
                        i_ind++;
                        step_beg = 2;
                    }
                }
                else
                {
                    if (i_ind != n - 1)
                    {
                        i_ind++;
                        step_beg = 2;
                    }
                    else
                    {
                        j_ind--;
                        step_beg = 1;
                    }
                }
                data[i_ind][j_ind] = arr[arr_i--];
                num_move++;
            }
            else
            {
                if ((step_next >> 1) % 2 != 0)
                {

                    while (i_ind < n - 1 && j_ind < n - 1)
                    {
                        i_ind++;
                        j_ind++;
                        step_beg = 3;
                        data[i_ind][j_ind] = arr[arr_i--];
                        num_move++;
                    }
                }
                else
                {
                    while (i_ind > 0 && j_ind > 0)
                    {
                        i_ind--;
                        j_ind--;
                        step_beg = 0;
                        data[i_ind][j_ind] = arr[arr_i--];
                        num_move++;
                    }
                }
            }
            step_next++;
        }
    }

    return rc;
}