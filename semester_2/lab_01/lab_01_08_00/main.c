#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdint.h>
#include <limits.h>

void printbits(uint32_t num)
{
    int temp;
    uint32_t res;
    uint32_t rev;

    rev = 0;
    res = num;
    for (int i = 0; i < 32; i++)
    {
        temp = res % 2;
        res = res / 2;
        if (temp == 1)
        {
            rev = rev + 1;
        }
        if (i < 31)
        {
            rev = rev * 2;
        }
    }
    res = rev;
    for (int i = 0; i < 32; i++)
    {
        temp = res % 2;
        res = res / 2;
        printf("%d", temp);
    }
}

uint32_t encryption(uint32_t num, int n)
{
    uint32_t res;
    res = num >> n;
    return res;
}

int main()
{
    setbuf(stdout, NULL);
    uint32_t res;
    int64_t num;
    int n;

    printf("Введите безнаковое число длиной 4 байта: ");
    if (scanf("%lld", &num) != 1)
    {
        printf("Error: Число должно быть безнаковое.");
        return -1;
    }
    printf("Введите число для сдвига: ");
    if (scanf("%d", &n) != 1)
    {
        printf("Error: Число некорректно.");
        return -1;
    }
    res = encryption((uint32_t) num, n);
    printf("Result: ");
    printbits(res);
    return 0;
}
