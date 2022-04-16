#include "process.h"

int main(int argc, char **argv)
{
    if(argc != 2 || argv == NULL)
        return PARAM_ERR;
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return NOT_FOUND_FILE;
    int rc = EXIT_SUCCESS;
    char words[LENGHT_ARRAY][LENGHT_STRING + 1];
    size_t n;
    rc = my_read_file(f, words, &n);
    if (rc == EXIT_SUCCESS)
    {
        char *short_word = words[0];       
        printf("Numbers of words with A or O: %d\n", numbers_only_a_o_with_words(words, &n));
        for (size_t i = 0; i < n - 1; i++)
            for(size_t j = i + 1; j < n; j++)
                if (words[i][0] == words[i][strlen(words[i]) - 1] && strlen(words[i]) <= strlen(short_word))
                    strcpy(short_word, words[i]);
        printf("%s\n", short_word);
    }
    return rc;
}