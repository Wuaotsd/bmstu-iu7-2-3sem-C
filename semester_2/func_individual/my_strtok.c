#include <stdio.h>

#define L_STRING 256

int check_syminstr(char c, char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

void split_str_to_words(char *str, char arr_words[][L_STRING + 1], size_t *nword, char *dev)
{
    int k = 0, i = 0, j = 0;
    while (str[k] != 0 && str[k] != '\n')
    {
        if (check_syminstr(str[k], dev))
        {
            arr_words[i][j] = '\0';
            if (j != 0)
            {
                j = 0;
                i++;
            }    
            k++;
        } else if (str[k + 1] == '\n' || str[k + 1] == '\0')
        {
            arr_words[i][j++] = str[k++];
            j = 0;
            i++;
        }
        else
            arr_words[i][j++] = str[k++];
            
    }
    (*nword) = i;
}


int main()
{
    char str[L_STRING + 1] = { 0 }, arr_words[L_STRING][L_STRING + 1] = { { 0 } };
    size_t nword;
    fgets(str, L_STRING + 1, stdin);
    split_str_to_words(str, arr_words, &nword, " !_");
    for (size_t i = 0; i < nword; i++)
        printf("%s\n", arr_words[i]);
    
    return 0;
}