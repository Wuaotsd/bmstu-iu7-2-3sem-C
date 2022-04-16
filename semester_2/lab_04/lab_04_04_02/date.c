#include "date.h"
// преобразование char в int
int char_to_int(char *str)
{
    int num = 0, i = 0, digit = 0;
    while (str[i] != '\0')
    {
        if (!(isdigit(str[i])))
        {
            num = -1;
            break;
        }
        if (str[i] == '0')
            digit = 0;
        if (str[i] == '1')
            digit = 1;
        if (str[i] == '2')
            digit = 2;
        if (str[i] == '3')
            digit = 3;
        if (str[i] == '4')
            digit = 4;
        if (str[i] == '5')
            digit = 5;
        if (str[i] == '6')
            digit = 6;
        if (str[i] == '7')
            digit = 7;
        if (str[i] == '8')
            digit = 8;
        if (str[i] == '9')
            digit = 9;
        num = num * 10 + digit;
        i++;
    }
    return num;
}

// проверяем месяцы
int check_months(char *str1, char (*str2)[MONTH_LEN])
{
    int i = 0, result = 0;
    while (str1[i] != '\0')
    {
        if (!islower(str1[i]))
            str1[i] = (char) tolower(str1[i]);
        i++;
    }
    i = 0;
    while (i < MONTH)
    {
        if (strcmp(str1, str2[i]) == 0)
        {
            result = 1;
            break;
        }
        i++;
    }
    return result;
}

// проверяем строку на числа
int my_isdigit(char *str)
{
    int result = 1, i = 0;
    while (str[i] != '\0')
    {
        if (!(isdigit(str[i])))
        {
            result = 0;
            break;
        }
        i++;
    }
    return result;
}

// проверяем дату 
int check_ndate(char *str, int max_day)
{
    int n = strlen(str), num;
    if (my_isdigit(str) && n > 0)
    {
        num = char_to_int(str);
        if (num <= max_day && num > 0)
            return 1;
    }
    return 0;
}

// проверяем год 
int check_year(char *str)
{
    int result = 0, n = strlen(str);
    int year = char_to_int(str);
    if (my_isdigit(str) && n > 0 && year >= 0)
        result = 1;
    return result;
}

// проверяем высокосный год
int check_high_grade_year(char *str)
{
    int n = char_to_int(str);
    if (n > 0)
    {
        if (n % 4 != 0 || (n % 100 == 0 && n % 400 != 0))
            return 0;
        else
            return 1;
    }
    return 0;
}

// проверка правильности написания даты в строке и есть ли дата там
int check_data_day(char *str)
{
    char words[ARR_WORD][WORD_LEN];
    int n = 0;
    if (split_word(str, words, &n) != EXIT_SUCCESS || n != 3)
        return 0;
    
    int result = 0, i = 0, j, count = 0;
    char months [MONTH][MONTH_LEN] = { "january", "february", "march", "april", "may", "june", "july", "august", "september", "october", "november", "december" };
    while (i < n - 2)
    {
        if (my_isdigit(words[i]) && (check_months(words[i + 1], months)) && (check_year(words[i + 2])))
        {
            j = 0;
            while (j < MONTH)
            {
                if ((j % 2 == 0 && j < 7) || (j % 2 != 0 && j >= 7))
                {
                    if (check_ndate(words[i], 31) && strcmp(words[i + 1], months[j]) == 0)
                    {
                        count ++;
                        result = 1;
                        break;
                    }
                }
                else if (j == 1)
                {
                    if (check_high_grade_year(words[i + 2]))
                    {
                        if (check_ndate(words[i], 29) && strcmp(words[i + 1], months[j]) == 0)
                        {
                            count ++;
                            result = 1;
                            break;
                        }
                    }
                    else
                    {
                        if (check_ndate(words[i], 28) && strcmp(words[i + 1], months[j]) == 0)
                        {
                            count ++;
                            result = 1;
                            break;
                        }
                    }
                }
                else
                {    
                    if (check_ndate(words[i], 30) && strcmp(words[i + 1], months[j]) == 0)
                    {
                        count ++;
                        result = 1;
                        break;
                    }
                }
                j++;
            }
        }
        i++;
    }
    if (count != 1)
        result = 0;
    return result;
}