#include "check_memory.h"
#include "errors.h"
#include "struct_subject.h"
#include "memory.h"

void default_subject(subject_t *subject);

// TESTING - char *allocate_malloc_string(size_t len)
int tests_allocate_and_free_malloc_string(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 2, test_pos = 2;

    {
        char *str = NULL;
        size_t len = 5;
        str = allocate_malloc_string(len + 1);
        if (str == NULL)
            pos_cnt++;

        free_string(&str);
        if (str != NULL)
            pos_cnt++;

        str = allocate_malloc_string(0);
        if (str != NULL)
            neg_cnt++;

        free_string(&str);
        if (str != NULL)
            neg_cnt++;
    }

    printf("===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return neg_cnt + pos_cnt;
}

// TESTING - char *allocate_malloc_structs(size_t n)
int tests_allocate_and_free_malloc_structs(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 2, test_pos = 2;

    {
        subject_t *arr = NULL;
        size_t n = 10;
        arr = allocate_malloc_structs(n);
        if (arr == NULL)
            pos_cnt++;
        else
            for (size_t i = 0; i < n; i++)
                default_subject(&arr[i]);

        free_structs(&arr, n);
        if (arr != NULL)
            pos_cnt++;

        arr = allocate_malloc_structs(0);
        if (arr != NULL)
            neg_cnt++;

        free_structs(&arr, 0);
        if (arr != NULL)
            neg_cnt++;
    }

    printf("===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return neg_cnt + pos_cnt;
}
