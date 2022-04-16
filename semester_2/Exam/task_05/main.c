#include "process.h"

int main(int argc, char **argv)
{
    if(argc != 2 || argv == NULL)
        return PARAM_ERR;
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
        return NOT_FOUND_FILE;
    item items[LENGHT_ARRAY];
    size_t n = 0;
    int rc = EXIT_SUCCESS;
    rc = my_read_file(f, items, &n);
    if (rc == EXIT_SUCCESS)
    {
        buble_sort_string(items, n);
        print_data(items, n);
    }
    return rc;
}