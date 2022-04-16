#include "check_word.h"
// проверка схожих слов
int check_words(const char *word_1, const char *word_2)
{
    size_t i = 0;
    while (word_1[i] != '\0' || word_2[i] != '\0')
    {
        if (word_1[i] != word_2[i])
            return 0;
        i++;
    }
    return 1;
}