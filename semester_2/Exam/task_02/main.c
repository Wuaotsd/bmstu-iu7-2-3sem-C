#include "process.h"

int main(int argc, char **argv)
{
    if (argc < 2 || argv == NULL)
        return PARAM_ERR;
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return NOT_FOUND_ERR;
    int rc = EXIT_SUCCESS;
    char words[ARR_WORD][WORD_LEN];
    int boolsign[ARR_WORD];
    size_t n = 0;
    rc = my_fscanf(f, words, boolsign, &n);
    if (rc != EXIT_SUCCESS)
        return rc;
    sort_words(words, boolsign, n);
    my_prinf(words,boolsign, n);
    return EXIT_SUCCESS;
}