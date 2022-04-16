#include "print_students.h"

void print_student(FILE *f, student_t *current)
{
    fprintf(f, "%s ", current->name);
    fprintf(f, "%d ", current->age);
	for (node_t *marks = current->marks_l; marks; marks = marks->next)
	{
	    int *mark = marks->data;
	    if (marks->next)
            fprintf(f, "%d ", *mark);
        else
            fprintf(f, "%d\n", *mark);
    }
}

void printf_students(FILE *f, node_t *studentlist)
{
    student_t *cur = NULL;
    for (; studentlist; studentlist = studentlist->next)
    {
        cur = studentlist->data;
        print_student(f, cur);
    }
}
