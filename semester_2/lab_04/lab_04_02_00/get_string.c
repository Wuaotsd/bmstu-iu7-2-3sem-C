#include "check_word.h"

int getchar(void);

int condition(char str);
// чтение строки без стандартных библиотек
int gets_str(char *str, int n)
{
    int i = 0, rc = EXIT_SUCCESS;
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        str[i++] = ch;
        if (i > n - 1)
        {
            rc = STR_FULL_ERR;
            break;
        }
    }	
    if (i == 0)
        rc = STR_EMPTY_ERR;

    if (rc == EXIT_SUCCESS)
        str[i++] = '\0';
    return rc;
}
// разделения строки на слова без использование стандартных библиотек
int split_word(const char *str, char (*w)[WORD_LEN], size_t *n)
{
    size_t i = 0, j = 0, g = 0;
    int flag = 0;
    while (str[g] != '\0')
    {
        if (condition(str[g]))
        {
            w[i][j] = str[g];
            j++;
            flag = 0;
            if (!(condition(str[g + 1])))
            {
                w[i][j] = '\0';
                j = 0;
                i++;
                flag = 1;
            }
        }
        if (j > WORD_LEN - 1)
            return WORD_FULL_ERR;
        g++;
    }
    if (flag == 0 && j > 0)
    {
        w[i][j] = '\0';
        i++;
    }
    *n = i;

    if (i == 0)
        return STR_EMPTY_END;
    return 0;
}
// условия для концевого признака слова
int condition(char str)
{
    return (str != ' ' && str != '\n' && str != '-' && str != ',' && str != '.' && str != ';' && str != ':' && str != '!' && str != '?');
}
