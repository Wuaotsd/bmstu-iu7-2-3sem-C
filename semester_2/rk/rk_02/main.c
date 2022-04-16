#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_STR   100
#define MAX_STRUCT 1300

#define NUM_OF_SR_ERR -1
#define ST_IO_ERR      1
#define NUM_ST_ERR    -2

typedef struct
{
    char name[SIZE_STR];
    char region[SIZE_STR];
    char okrug[SIZE_STR];
    long long population;
    int year;
} st;

int read_struct(FILE *f, st *town)
{
    char buff[8];
    int len;
    if(!fgets(town->name, SIZE_STR, f))
        return ST_IO_ERR;
    len = strlen(town->name);
    if (town->name[len - 1] == '\n')
        town->name[len - 1] = '\0';
    
    if(!fgets(town->region, SIZE_STR, f))
        return ST_IO_ERR;
    len = strlen(town->region);
    if (town->region[len - 1] == '\n')
        town->region[len - 1] = '\0';
    
    if(!fgets(town->okrug, SIZE_STR, f))
        return ST_IO_ERR;
    len = strlen(town->okrug);
    if (town->okrug[len - 1] == '\n')
        town->okrug[len - 1] = '\0';
     
    if (fscanf(f, "%lld", &town->population) != 1)
        return ST_IO_ERR;
    if (fscanf(f, "%d", &town->year) != 1)
        return ST_IO_ERR;
    fgets(buff, sizeof(buff), f);
    return 0;
}

int read_arr_st(FILE *f, st *arr, int *n)
{
    char buff[8];
    if(fscanf(f, "%d", n) != 1)
       return NUM_OF_SR_ERR;
    fgets(buff, sizeof(buff), f);
    if (*n <= 0 || *n > MAX_STRUCT)
        return NUM_OF_SR_ERR;
    int i = 0, rc = 0;
    st cur;
    while (i < *n)
    {
        rc = read_struct(f, &cur);
        if (rc != 0)
            break;
        
        arr[i] = cur;
        i++;
    }
    if (rc == ST_IO_ERR)
        rc = 0;
    if (i != *n)
        rc = NUM_ST_ERR;
    return rc;
}

void print_info_st(FILE *f, st *town)
{
    fprintf(f, "%s\n", town->name);
    fprintf(f, "%s\n", town->region);
    fprintf(f, "%s\n", town->okrug);
    fprintf(f, "%lld\n", town->population);
    fprintf(f, "%d\n", town->year);
}


void print_st(FILE *f, st *arr, int n)
{
    for (int i = 0; i < n; i++)
        print_info_st(f, &arr[i]);
}

void find_young_town(st *arr, st *ytown, int n)
{
    ytown->year = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].year > ytown->year)
            *ytown = arr[i];
    }
}

int check_chars(st *town)
{
    int i = 0;
    int glas = 0;
    int sogl = 0;
    while (town->name[i] != '\0')
    {
        if (town->name[i] == 'A' || town->name[i] == 'a' || 
        town->name[i] == 'Y' || town->name[i] == 'y' || 
        town->name[i] == 'E' || town->name[i] == 'e' || 
        town->name[i] == 'I' || town->name[i] == 'i' || 
        town->name[i] == 'O' || town->name[i] == 'o' ||
        town->name[i] == 'U' || town->name[i] == 'u')
            glas++;
        else
            sogl++;
        
        i++;
    }
    //printf("%d, %d", glas, sogl);
    if (sogl > glas)
        return 1;
    return 0;
}
int main()
{   
    FILE *f_in, *f_out;
    st arr[MAX_STRUCT];
    st town;
    int rc = 0, n;
    
    f_in = fopen("in.txt", "r");
    if (f_in == NULL)
    {
        printf("Файл для чтения пустой!");
        return -1;
    }
    rc = read_arr_st(f_in, arr, &n);
    fclose(f_in);
    if (rc != 0)
    {
        printf("Ошибка! Проверьте корректность файла! Количетсво структур больше или меньше сколько есть! Либо структура некорректна!");
        return rc;
    }
    f_out = fopen("out.txt", "w");
    //print_st(stdout, arr, n);
    find_young_town(arr, &town, n);
    printf("Файл записан!");
    if (check_chars(&town))
        print_info_st(f_out, &town);
    else
        fprintf(f_out, "В файле нет таких городов!");
    return 0;
}

