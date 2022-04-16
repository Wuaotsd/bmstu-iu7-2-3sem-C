#include "check_read.h"
#include "struct_subject.h"
#include "read_struct.h"
#include "read_check.h"
#include "memory.h"
#include "errors.h"

#define UNIT_TESTS_FILE "unit_test.txt"
#define WRITE_SEQUENCE(fd, sequence) \
    rewind((fd));                    \
    fprintf((fd), sequence);         \
    rewind((fd));

#define EPS 1e-8

// TESTING - int check_prefix(char *str, char *prefix)
int tests_check_prefix(void)
{
    int pos_cnt = 0, test_pos = 5;

    {
        int rc = 0;
        rc = check_prefix("Maggi", "ALL");
        if (rc == 1)
            pos_cnt++;

        rc = check_prefix("Mag", "ALL");
        if (rc == 1)
            pos_cnt++;

        rc = check_prefix("all", "ALL");
        if (rc == 0)
            pos_cnt++;

        rc = check_prefix("All", "ALL");
        if (rc == 0)
            pos_cnt++;

        rc = check_prefix("ALL", "ALL");
        if (rc == 0)
            pos_cnt++;
    }

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return pos_cnt;
}

// TESTING - int file_is_empty(FILE *f)
int tests_file_is_empty(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 1, test_pos = 1;

    {
        int rc = 0;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        rc = file_is_empty(f);
        if (rc != FILE_IS_EMPTY)
            neg_cnt++;

        WRITE_SEQUENCE(f, "Hello\n12\n45\n");

        rc = file_is_empty(f);
        if (rc != EXIT_SUCCESS)
            pos_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    printf("===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return pos_cnt;
}

// TESTING - void default_subject(subject_t *subject)
int tests_default_subject(void)
{
    int pos_cnt = 0, test_pos = 1;

    subject_t subject;
    default_subject(&subject);

    if (subject.name_subject != NULL || (subject.weight - 0.0) > EPS || (subject.volume - 0.0) > EPS)
        pos_cnt++;
    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS\n");

    return pos_cnt;
}

// TESTING - int get_size_string(FILE *f)
int tests_get_size_string(void)
{
    int pos_cnt = 0, test_pos = 2;

    int n = 0;
    FILE *f = fopen(UNIT_TESTS_FILE, "w+");
    WRITE_SEQUENCE(f, "Hello\n");

    n = get_size_string(f);
    if (n != 5)
        pos_cnt++;

    WRITE_SEQUENCE(f, "Maggi Maggi");

    n = get_size_string(f);
    if (n != 11)
        pos_cnt++;

    fclose(f);
    remove(UNIT_TESTS_FILE);


    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

// TESTING - int get_size_struct(FILE *f, size_t *size)
int tests_get_size_struct(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 10, test_pos = 1;
    // PARAMS_ERR
    {
        size_t n = 0;
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;

        rc = get_size_struct(f, &n);
        if (!(n == 0 && rc == PARAMS_ERR))
            neg_cnt++;

        f = fopen(UNIT_TESTS_FILE, "w+");
        n = 25;

        rc = get_size_struct(f, &n);
        if (!(n == 25 && rc == PARAMS_ERR))
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);

    }
    // STRUCT_ERROR
    {
        size_t n = 0;
        int rc = EXIT_SUCCESS;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "\n");
        rc = get_size_struct(f, &n);
        if (!(n == 0 && rc == STRUCT_ERROR))
            neg_cnt++;

        WRITE_SEQUENCE(f, "Hello\n");
        rc = get_size_struct(f, &n);
        if (!(n == 0 && rc == STRUCT_ERROR))
            neg_cnt++;

        WRITE_SEQUENCE(f, "Hello\n1\n");
        rc = get_size_struct(f, &n);
        if (!(n == 0 && rc == STRUCT_ERROR))
            neg_cnt++;


        WRITE_SEQUENCE(f, "Hello\n\n2");
        rc = get_size_struct(f, &n);
        if (!(n == 0 && rc == STRUCT_ERROR))
            neg_cnt++;


        WRITE_SEQUENCE(f, "\n13.0\n4.0");
        rc = get_size_struct(f, &n);
        if (!(n == 0 && rc == STRUCT_ERROR))
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    // NEGATIVE_DATA
    {
        size_t n = 0;
        int rc = EXIT_SUCCESS;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "Hi\n-13.0\n4.0");
        rc = get_size_struct(f, &n);
        if (!(n == 0 && rc == NEGATIVE_DATA))
            neg_cnt++;

        WRITE_SEQUENCE(f, "Hi\n13.0\n-4.0");
        rc = get_size_struct(f, &n);
        if (!(n == 0 && rc == NEGATIVE_DATA))
            neg_cnt++;

        WRITE_SEQUENCE(f, "Hi\n-13.0\n-4.0");
        rc = get_size_struct(f, &n);
        if (!(n == 0 && rc == NEGATIVE_DATA))
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);

    }
    // POSITIVE_TEST
    {
        size_t n = 0;
        int rc = EXIT_SUCCESS;
        FILE *f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "Hi\n13.0\n4.0\nMaggi\n13.0\n43.0\nMaggi\n100.0\n43.0");
        rc = get_size_struct(f, &n);
        if (!(n == 3 && rc == EXIT_SUCCESS))
            pos_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }

    printf("===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf("\n -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt + neg_cnt;
}

// TESTING - void trim_beg_end_str(char *str)
int tests_trim_beg_end_str(void)
{
    int pos_cnt = 0, test_pos = 1;
    char string[24] = "    HELLO    HELLO    ";
    trim_beg_end_str(string);

    if (strcmp(string, "HELLO HELLO ") != 0)
        pos_cnt++;

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

// TESTING - void str_shift_left(char *str, size_t i)
int tests_str_shift_left(void)
{
    int pos_cnt = 0, test_pos = 3;
    char string[6] = "Hello";

    str_shift_left(string, 1);
    if (strcmp(string, "Hllo") != 0)
        pos_cnt++;

    str_shift_left(string, 2);
    if (strcmp(string, "Hlo") != 0)
        pos_cnt++;

    str_shift_left(string, 0);
    if (strcmp(string, "lo") != 0)
        pos_cnt++;

    printf("===%s:", __func__);
    printf("\n -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt;
}

// TESTING - int read_struct_info(FILE *f, subject_t *subject, size_t count_st)
int tests_read_struct_info(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 7, test_pos = 2;
    //PARAMS_ERR
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        subject_t subject;
        default_subject(&subject);

        rc = read_struct_info(f, &subject, 0);
        if (!(rc == PARAMS_ERR && subject.name_subject == NULL))
            neg_cnt++;
    }
    //STRUCT_ERROR
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        subject_t subject;
        default_subject(&subject);
        // Проверка когда нет вообще данных или достигнут конец файла
        f = fopen(UNIT_TESTS_FILE, "w+");
        rc = read_struct_info(f, &subject, 0);
        if (!(rc == ERR_IO && subject.name_subject == NULL && (subject.weight - 0.0) < EPS && (subject.volume - 0.0) < EPS))
            neg_cnt++;

        // Проверка когда нет данных о именни
        WRITE_SEQUENCE(f, "\n21.0\n2.0");
        rc = read_struct_info(f, &subject, 0);
        if (!(rc == ERR_IO && subject.name_subject == NULL && (subject.weight - 0.0) < EPS && (subject.volume - 0.0) < EPS))
            neg_cnt++;
        free(subject.name_subject);
        subject.name_subject = NULL;
        fclose(f);

        // Проверка когда нет данных о массе и объеме
        f = fopen(UNIT_TESTS_FILE, "w+");
        fprintf(f, "Hello");
        rewind(f);
        rc = read_struct_info(f, &subject, 0);
        if (!(rc != EXIT_SUCCESS && strcmp("Hello", subject.name_subject) == 0))
            neg_cnt++;
        free(subject.name_subject);
        subject.name_subject = NULL;
        fclose(f);

        // Проверка когда нет данных о массе
        f = fopen(UNIT_TESTS_FILE, "w+");
        fprintf(f, "Hello\n\n23");
        rewind(f);
        rc = read_struct_info(f, &subject, 0);
        if (!(rc != EXIT_SUCCESS && strcmp("Hello", subject.name_subject) == 0 && (subject.weight - 23.0) < EPS))
            neg_cnt++;
        free(subject.name_subject);
        subject.name_subject = NULL;
        fclose(f);

        // Проверка когда нет данных о объеме
        f = fopen(UNIT_TESTS_FILE, "w+");
        fprintf(f, "Hello\n10.0\n");
        rewind(f);
        rc = read_struct_info(f, &subject, 0);
        if (!(rc != EXIT_SUCCESS && strcmp("Hello", subject.name_subject) == 0 && (subject.weight - 10.0) < EPS))
            neg_cnt++;
        free(subject.name_subject);
        subject.name_subject = NULL;
        fclose(f);

        remove(UNIT_TESTS_FILE);
    }
    //NEGATIVE_DATA
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        subject_t subject;
        default_subject(&subject);

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "Hello\n-21.0\n2.0\n");
        rc = read_struct_info(f, &subject, 0);
        if (!(rc == NEGATIVE_DATA && strcmp("Hello", subject.name_subject) == 0 && (subject.weight + 21.0) < EPS && (subject.volume - 2.0) < EPS))
            neg_cnt++;
        free(subject.name_subject);
        default_subject(&subject);

        WRITE_SEQUENCE(f, "Hello\n21.0\n-2.0\n");
        rc = read_struct_info(f, &subject, 0);
        if (!(rc == NEGATIVE_DATA && strcmp("Hello", subject.name_subject) == 0 && (subject.weight - 21.0) < EPS && (subject.volume + 2.0) < EPS))
            neg_cnt++;
        free(subject.name_subject);
        default_subject(&subject);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    //POSITIVE
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        subject_t subject;
        default_subject(&subject);

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f, "Hello\n21.0\n2.0\nMaggi\n45.0\n23.0\n");

        rc = read_struct_info(f, &subject, 0);
        if (!(rc == EXIT_SUCCESS && strcmp("Hello", subject.name_subject) == 0 && (subject.weight - 21.0) < EPS && (subject.volume - 2.0) < EPS))
            pos_cnt++;
        free(subject.name_subject);
        default_subject(&subject);

        rc = read_struct_info(f, &subject, 1);
        if (!(rc == EXIT_SUCCESS && strcmp("Maggi", subject.name_subject) == 0 && (subject.weight - 45.0) < EPS && (subject.volume - 23.0) < EPS))
            pos_cnt++;
        free(subject.name_subject);
        default_subject(&subject);

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    printf("===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf("\n -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt + neg_cnt;
}

// TESTING - int read_struct(FILE *f, subject_t **arr, size_t *n)
int tests_read_struct(void)
{
    int neg_cnt = 0, pos_cnt = 0, test_neg = 4, test_pos = 1;
    //PARAMS_ERR
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        subject_t subject , *array = NULL;
        size_t n = 0;

        rc = read_struct(NULL, &array, &n);
        if (!(rc == PARAMS_ERR && array == NULL && n == 0))
            neg_cnt++;

        f = fopen(UNIT_TESTS_FILE, "w+");

        array = &subject;
        rc = read_struct(f, &array, &n);
        if (!(rc == PARAMS_ERR && n == 0))
            neg_cnt++;

        array = NULL;
        n = 10;
        rc = read_struct(f, &array, &n);
        if (!(rc == PARAMS_ERR && n == 10))
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    //FILE_IS_EMPTY
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        subject_t *array = NULL;
        size_t n = 0;

        f = fopen(UNIT_TESTS_FILE, "w+");

        rc = read_struct(f, &array, &n);
        if (!(rc == FILE_IS_EMPTY && array == NULL && n == 0))
            neg_cnt++;

        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    //POSITIVE_DATA
    {
        int rc = EXIT_SUCCESS;
        FILE *f = NULL;
        subject_t *array = NULL;
        size_t n = 0;

        f = fopen(UNIT_TESTS_FILE, "w+");

        WRITE_SEQUENCE(f,"Maggi\n12.0\n34\nGeful\n123.0\n67\nMaggi\n12.0\n56\n");

        rc = read_struct(f, &array, &n);
        if (!(rc == EXIT_SUCCESS && n == 3 && array != NULL))
            pos_cnt++;

        free_structs(&array, n);
        fclose(f);
        remove(UNIT_TESTS_FILE);
    }
    printf("===%s:\n -Негативные тесты: %d of %d - %s", __func__,test_neg - neg_cnt, test_neg, neg_cnt ? "FAILED" : "SUCCESS");
    printf("\n -Позитивные тесты: %d of %d - %s\n", test_pos - pos_cnt, test_pos, pos_cnt ? "FAILED" : "SUCCESS");

    return pos_cnt + neg_cnt;
}
