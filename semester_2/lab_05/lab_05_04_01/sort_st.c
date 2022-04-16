#include "func_tfp.h"

void sort_students(st *arr, int n)
{   
    st buff;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(arr[i].lastname, arr[j].lastname) > 0)
            {
                buff = arr[i];
                arr[i] = arr[j];
                arr[j] = buff;
            }
            else
            {
                if (strcmp(arr[i].lastname, arr[j].lastname) == 0)
                    if (strcmp(arr[i].firstname, arr[j].firstname) > 0)
                    {
                        buff = arr[i];
                        arr[i] = arr[j];
                        arr[j] = buff;
                    }
            }
        }
}