#include "func_tfp.h"

float average_calc(st *arr, int n, float *mas_avr)
{
    float s = 0; // среднее значение оценок каждого студента
    float s_sr = 0; // среднее значение среднего балла
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = 0; j < N; j++)
            s += arr[i].marks[j];
        mas_avr[i] = s / N;
        s_sr += mas_avr[i];
    }
    s_sr = s_sr / n;
    return s_sr;
}

void del_student(st *arr, float *mas_avr, int *n, float s_sr)
{
    int h = 0, i = 0;
    int n1 = *n;
    while (h < n1)
    {
        if (mas_avr[h] < s_sr)
        {
            for (int j = i; j < *n - 1; j++)
                arr[j] = arr[j + 1];
            *n -= 1;
        }
        else
            i++;
        h++;
    }
}