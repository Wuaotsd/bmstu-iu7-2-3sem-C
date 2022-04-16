#include "date.h"

int main(void)
{
    char str[STR_LEN] = { 0 }; 
    int rc = EXIT_SUCCESS;
    rc = gets_str(str, STR_LEN);
    if (rc == STR_FULL_ERR)
        return rc;
    //if (rc != EXIT_SUCCESS)
    //{
    //    printf("NO");
    //    return EXIT_SUCCESS;
    //}
    //rc = split_word(str, words, &nwords);
    if (rc == EXIT_SUCCESS && check_data_day(str))
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return EXIT_SUCCESS;
}
