#include <stdio.h>
#include <string.h>
#include <assert.h>
#define ERR_IO 1
#define ERR 3
#define ERR_PARAM 53
#define OK 0
#define N_MAX 10
#define ERR_MEM -4
#define ERR_FILE 5
#define EMPTY_FILE 6
#define MAX_STR_LEN 128
#define KOL_SUBJ 4
#define MAX_LASTNAME 25
#define MAX_FIRSTNAME 10
typedef struct
{
    char lastname[MAX_LASTNAME + 1];
    char firstname[MAX_FIRSTNAME + 1];
    unsigned int marks[KOL_SUBJ];
}st;
//
//========================= Задание 1 ============================
//
/*
Функция file_size принимает файл. Функция находит
и возвращает количество структур, записанных в этот
файл, возвращает код ошибки.
*/
int file_size(FILE *f, int *k)
{
    int rc = OK, size;
    if (fseek(f, 0, SEEK_END) == 0)
    {
        size = ftell(f);
        *k = size / sizeof(st);
        if (size % sizeof(st) != 0)
            rc = ERR_IO;
        else if (*k > N_MAX)
        {
            *k = N_MAX;
            rc = ERR_MEM;
        }
        if (fseek(f, 0, SEEK_SET) != 0)
            rc = ERR;
    }
    else
        rc = ERR;
    return rc;
}
/*
Функция print_marks принимает массив и его размер.
Функция печатает элементы массива на экран.
*/
void print_marks(const unsigned int *marks, int n)
{
    for (int i = 0; i < n; i++)
        printf("%u ", marks[i]);
}
/*
Функция print_struct принимает  структуру
и печатает ее на экран.
*/
void print_struct(const st student)
{
    printf("%s\n", student.lastname);
    printf("%s\n", student.firstname);
    print_marks(student.marks, KOL_SUBJ);
    printf("\n\n");
}
/*
Функция print_bin_file принимает файл и
печатает  его содержимое на экран.
*/
int print_bin_file(FILE *f)
{
    int k = 0, rc = OK;
    st student;
    if (fseek(f, 0, SEEK_SET) == OK)
    {
        rc = file_size(f, &k);
        if (rc == OK)
            for (int i = 0; i < k; ++i)
            {
                fread(&student, sizeof(st), 1, f);
                print_struct(student);
            }
    }
    else
        rc = ERR;
    return rc;
}
/*
Функция check_file принимает файл и проверяет корректность
его содержимого. Функция возвращает код ошибки.
*/
int check_file(FILE *f)
{
    int k = 0, rc = OK;
    rc = file_size(f, &k);
    if (rc == OK)
    {
        if (fseek(f, 0, SEEK_SET) == 0)
        {
            if (k == 0)
                return EMPTY_FILE;
        }
        else
            return ERR;
    }
    else
        return ERR;
    return rc;
}
/*
Функция get_student_by_pos принимает файл, позицию. Функция
возвращает структуру, находящуюся на указанной позиции.
*/
int get_student_by_pos(FILE *f, int pos, st *get_student)
{
    int rc = OK;
    if (fseek(f, pos * sizeof(st), SEEK_SET) == 0)
    {
        if (fread(get_student, sizeof(st), 1, f) != 1)
            rc = ERR_IO;
    }
    else
        rc = ERR;
    return rc;
}
/*
Функция put_student_by_pos принимает файл, позицию.
Функция записывает структуру в указанную позицию.
*/
int put_student_by_pos(FILE *f, int pos, st put_student)
{
    int rc = OK;
    if (fseek(f, pos * sizeof(st), SEEK_SET) == 0)
    {
        if (fwrite(&put_student, sizeof(st), 1, f) != 1)
            rc = ERR_IO;
    }
    else
        rc = ERR;
    return rc;
}
/*
Функция sort принимает файл. Функция упорядочивает
информацию о студентах по фамилиям и возвращает код ошибки.
*/
int sort(FILE *f)
{
    int k = 0, rc = OK;
    st f_student, s_student;
    rc = file_size(f, &k);
    if (rc == OK)
    {
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if (get_student_by_pos(f, i, &f_student) != OK)
                    return ERR;
                if (get_student_by_pos(f, j, &s_student) != OK)
                    return ERR;
                if (strcmp(f_student.lastname, s_student.lastname) > 0)
                {
                    if (put_student_by_pos(f, i, s_student) != OK)
                        return ERR;
                    if (put_student_by_pos(f, j, f_student) != OK)
                        return ERR;
                }
                else
                {
                    if (strcmp(f_student.lastname, s_student.lastname) == 0)
                    {
                        if (strcmp(f_student.firstname, s_student.firstname) > 0)
                        {
                            if (put_student_by_pos(f, i, s_student) != OK)
                                return ERR;
                            if (put_student_by_pos(f, j, f_student) != OK)
                                return ERR;
                        }
                    }
                }
            }
        }
    }
    return rc;
}
/*
void data(FILE *f)
{
    st student1 = {"Novik", "Elena", {3, 2, 4, 4} };
    fwrite(&student1, sizeof(st), 1, f);
    st student2 = {"Novik", "Alena", {4, 3, 1, 5} };
    fwrite(&student2, sizeof(st), 1, f);
    st student3 = {"Solovey", "Olga", {3, 2, 4, 4} };
    fwrite(&student3, sizeof(st), 1, f);
    st student4 = {"Gerasimenko", "Andrey", {4, 3, 1, 5} };
    fwrite(&student4, sizeof(st), 1, f);
    st student5 = {"Sidorov", "Sid", {4, 3, 4, 4} };
    fwrite(&student5, sizeof(st), 1, f);
    st student6 = {"Sidorov", "Petr", {3, 4, 5, 3} };
    fwrite(&student6, sizeof(st), 1, f);
}
*/
//
//======================== Задание 3 ============================
//
/*
Функция read_stud_info_text принимает файл и структуру.
Функция читает информацию об одном студенте из файла
в структуру. Функция возвращает код ошибки.
*/
int read_stud_info_text(FILE *f, st *student)
{
    char buf[8];
    int len;
    if (!fgets(student->lastname, sizeof(student->lastname), f))
        return ERR_IO;
    len = strlen(student->lastname);
    if (student->lastname[len - 1] == '\n')
        student->lastname[len - 1] = 0;
    if (!fgets(student->firstname, sizeof(student->firstname), f))
        return ERR_IO;
    len = strlen(student->firstname);
    if (student->firstname[len - 1] == '\n')
        student->firstname[len - 1] = 0;
    if (fscanf(f, "%u%u%u%u", &student->marks[0], &student->marks[1],
        &student->marks[2], &student->marks[3]) != 4)
        return ERR_IO;
    fgets(buf, sizeof(buf), f);
    return OK;
}
/*
Функция read_in_array_text принимает файл,массив структур
и его размер. Функция читает информацию о студентах из
текстового файла и помещает в массив. Функция возвращает код ошибки.
*/
int read_in_array_text(FILE *f, st *arr, int *n)
{
    st cur;
    int k = 0;
    int rc = OK;
    while (rc == OK)
    {
        rc = read_stud_info_text(f, &cur);
        if (rc == OK)
        {
            if (k < N_MAX)
            {
                arr[k] = cur;
                k++;
            }
            else
                rc = ERR_MEM;
        }
        *n = k;
    }
    if (rc != ERR_MEM)
        rc = OK;
    return rc;
}
/*
Функция del_stud принимает массив структур, его размер,
массив ср. баллов студентов и значение среднего балла
всех студентов. Функция удаляет студентов, средний балл
которых меньше среднего значения.
*/
void del_stud(st *arr, float *mas_avr, int *n, float s_sr)
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
/*
Функция average_calc принимает массив структур, его размер и
массив. В функции массив заполняется средними знчениями
оценок каждого студента. Вычисляется и возвращается
среднее значение среднего балла всех студентов.
*/
float average_calc(st *arr, int n, float *mas_avr)
{
    assert(n > 0);
    float s = 0; // среднее значение оценок каждого студента
    float s_sr = 0; // среднее значение среднего балла
    for (int i = 0; i < n; i++)
    {
        s = 0;
        for (int j = 0; j < KOL_SUBJ; j++)
            s += arr[i].marks[j];
        mas_avr[i] = s / KOL_SUBJ;
        s_sr += mas_avr[i];
    }
    s_sr = s_sr / n;
    return s_sr;
}
// =================== Запись ответа в файл ====================
/*
Функция print_st_info принимает файл и структуру
и печатает о ней информацию в файл.
*/
void print_st_info_file(FILE *f, st *student)
{
    fprintf(f, "%s\n", student->lastname);
    fprintf(f, "%s\n", student->firstname);
    fprintf(f, "%u %u %u %u\n", student->marks[0], student->marks[1],
        student->marks[2], student->marks[3]);
}
/*
Функция print_st_array принимает массив структур
и его размер. Функция печатает элементы массива в файл.
*/
void print_st_array_file(FILE *f, st *arr, int n)
{
    for (int i = 0; i < n; i++)
        print_st_info_file(f, &arr[i]);
}
/*
Функция выводит информацию о том, что
может выполнить данная программа.
*/
void usage(void)
{
    printf("app.exe <action> filename\n");
    printf("<action>\n");
    printf("\t sb - sort students in binary file\n");
    printf("\t dt - removes students whose average score is less "
        "than the average values. \n");
}
int main(int argc, char *argv[])
{
    st arr[N_MAX];
    float mas_avr[N_MAX];
    int n = 0;
    float s_sr;
    int rc = OK;
    FILE *f;
    if (argc != 3)
    {
        usage();
        rc = ERR_PARAM;
    }
    else if (strcmp(argv[1], "dt") == 0)
    {
        f = fopen(argv[2], "rt");
        if (f == NULL)
            rc = ERR_FILE;
        else
        {
            rc = read_in_array_text(f, arr, &n);
            if (n == 0)
                rc = EMPTY_FILE;
            if (rc == OK)
            {
                s_sr = average_calc(arr, n, mas_avr);
                del_stud(arr, mas_avr, &n, s_sr);
                fclose(f);
                f = fopen(argv[2], "wt");
                print_st_array_file(f, arr, n);
            }
            fclose(f);
        }
    }
    else if (strcmp(argv[1], "sb") == 0)
    {
        //f = fopen(argv[2], "w + b");
        f = fopen(argv[2], "r + b");
        if (f == NULL)
            rc = ERR_FILE;
        else
        {
            //data(f);
            rc = check_file(f);
            if (rc != OK)
                fclose(f);
            else
            {
                rc = sort(f);
                if (rc == OK)
                    print_bin_file(f);
                fclose(f);
            }
        }
    }
    else
        rc = ERR_PARAM;
    return rc;
}
