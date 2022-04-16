#include "sort_struct.h"

void swap_struct(subject_t *subject_1, subject_t *subject_2)
{
    subject_t buff = *subject_1;
    *subject_1 = *subject_2;
    *subject_2 = buff;
}

void sort_array_by_density(subject_t *arr, size_t n)
{
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = i + 1; j < n; j++)
            if ((arr[i].weight / arr[i].volume) > (arr[j].weight / arr[j].volume))
                swap_struct(&arr[i], &arr[j]);
}
