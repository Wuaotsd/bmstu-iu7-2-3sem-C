#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "errors.h"
#include "allocate.h"
#include "read.h"
#include "sort.h"
#include "print.h"

int main(int argc, char **argv)
{
	setbuf(stdout, NULL);
	if (argc != 2)
		return ARGV_ERR;

	FILE *f = NULL;
	int n = 0, m = 0;
	int rc = EXIT_SUCCESS;
	int **data = NULL;
	f = fopen(argv[1], "r");
	if (f == NULL)
		rc = NOT_FOUND;
	else
	{
		rc = get_size_square_matrix(f, &n, &m);
		if (rc == EXIT_SUCCESS)
		{
			data = allocate_matrix(n, m);
			if (!data)
				rc = MEMORY_MATRIX_ERR;
			else
			{
				rewind(f);
				rc = read_element_matrix(f, data, n, m);
				if (rc == EXIT_SUCCESS)
				{
				    printf("Matrix - from file:\n");
                    print_matrix(data, n, m);
				    rc = sort_by_snake_left_down(data, n, m);
				    if (rc == EXIT_SUCCESS)
				    {
                        printf("Matrix after snake sort in the lower left corner:\n");
                        print_matrix(data, n, m);
                    }
				}
			}
            free_matrix(&data);
		}
		fclose(f);
	}
	
	return rc;
}