#include "read_students.h"

int read_student(FILE *f, student_t *student)
{
	int rc = EXIT_SUCCESS, rc_s;

	if ((rc_s = fscanf(f, "%s", student->name)) != 1)
    {
	    if (rc_s == -1)
	        rc = END_FILE;
        else
            rc = STRUCT_ERR;
    }
	else if (fscanf(f, "%d", &student->age) != 1)
		rc = STRUCT_ERR;
	else 
	{
	    int *mark, i = 0;
	    char end = '.';
		while (rc == EXIT_SUCCESS && end != '\n' && !feof(f))
		{
            mark = malloc(sizeof(int));
            if (mark == NULL)
                rc = MEMORY_ERROR;
            else
            {
                if ((rc_s = fscanf(f, "%d%c", mark, &end)) && rc_s != 1 && rc_s != 2)
                    rc = STRUCT_ERR;
                else if (*mark < 1 || *mark > 10)
                    rc = STRUCT_ERR;
                else
                {
                    rc = list_push(&student->marks_l, mark);
                    i++;
                }
            }
		}
		if (!rc && i > LIST_SIZE)
		    rc = LIST_OVERFLOW;
		if (rc)
        {
		    free(mark);
		    mark = NULL;
        }
	}

	return rc;
}

int read_students(FILE *f, node_t **studentlist)
{
	student_t *current = NULL;

    int i = 0, rc = EXIT_SUCCESS;
    while (rc == EXIT_SUCCESS)
    {
        current = (student_t *) malloc(sizeof(student_t));
        if (current != NULL)
        {
            current->marks_l = NULL;

            rc = read_student(f, current);
            if (rc == EXIT_SUCCESS)
            {
                if (i <= LIST_SIZE)
                {
                    rc = list_push(studentlist, current);
                    i++;
                }
                else
                    rc = LIST_OVERFLOW;
            }
        }
        else
            rc = MEMORY_ERROR;
    }

    if (rc)
    {
        free(current);
        current = NULL;
    }

    if (rc == END_FILE)
    {
        rc = EXIT_SUCCESS;
    }

	return rc;
}