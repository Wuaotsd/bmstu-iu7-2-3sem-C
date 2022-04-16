#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "errors.h"
#include "structs.h"
#include "read_students.h"
#include "print_students.h"
#include "list_op.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
	int rc = EXIT_SUCCESS;
	if (argc > 4 || argc < 3)
	{
	    printf("Key not valid\n");
        rc = ARGV_ERROR;
    }
	else
	{
		node_t *students = NULL;
		FILE *f_in = fopen(argv[2], "r");
		if(f_in == NULL)
		{
			printf("File not found\n");
			rc = FILE_NOT;
		}
		else
		{
			long size;
			fseek(f_in, 0, SEEK_END);
			size = ftell(f_in);
			if (size == 0)
			{
			    printf("File is empty\n");
                rc = FILE_EMPTY;
            }
			else
				fseek(f_in, 0, SEEK_SET);
			
			if (rc == EXIT_SUCCESS)
			{
			    if (!strcmp("-f", argv[1]))
                {
                    rc = read_students(f_in, &students);
                    if (rc == EXIT_SUCCESS)
                    {
                        if (argc == 3)
                            printf_students(stdout, students);
                        if (argc == 4)
                        {
                            if (!strcmp("-s", argv[3]))
                            {
                                students = sort(students, (int (*)(const void *, const void *)) comparator_avg);
                                printf_students(stdout, students);
                            }
                        }
                    }
                    else
                        printf("File not valid\n");
                }
			    else
                {
                    printf("Key not valid\n");
                    rc = ARGV_ERROR;
                }
			}
            free_students(&students);
			fclose(f_in);
		}
		
	}
	
	return rc;
} 