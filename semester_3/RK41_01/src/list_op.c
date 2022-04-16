#include "list_op.h"

int list_push(node_t **head, void *element)
{
    int rc = EXIT_SUCCESS;
    if (head == NULL)
        rc = EXIT_FAILURE;
    else
    {
        node_t *node = node_create(element);
        if (node != NULL)
        {
            if (*head == NULL)
                *head = node;
            else
            {
                node_t *tail = *head;
                for (;tail->next; tail = tail->next);
                tail->next = node;
            }
        }
        else
            rc = MEMORY_ERROR;
    }

    return rc;
}

node_t *node_create(void *data)
{
    node_t *node = NULL;
    if (data != NULL)
    {
        node = (node_t *) malloc(sizeof(node_t));
        if (node != NULL)
        {
            node->data = data;
            node->next = NULL;
        }
    }
    return node;
}

void free_marks(node_t **head)
{
    if (head != NULL && *head != NULL)
    {
        node_t *next_elem;
        int *mark = NULL;
        for (;*head; *head = next_elem)
        {
            mark = (*head)->data;
            next_elem = (*head)->next;
            free(mark);
            mark = NULL;
            free(*head);
        }
        *head = NULL;
    }
}

void free_students(node_t **studentslist)
{
    if (studentslist != NULL && *studentslist != NULL)
    {
        node_t *next_elem = NULL;
        student_t *current = NULL;

        for (; *studentslist; *studentslist = next_elem)
        {
            current = (*studentslist)->data;
            next_elem = (*studentslist)->next;
            free_marks(&current->marks_l);
            free(current);
            current = NULL;
            free(*studentslist);
        }
        *studentslist = NULL;
    }
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    node_t *sort = NULL;
    if (head != NULL && comparator != NULL)
    {
        while (head != NULL)
        {
            node_t *node = head;
            head = head->next;
            sorted_insert(&sort, node, comparator);
        }
    }
    else
        sort = head;
    return sort;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (head != NULL && comparator != NULL)
    {
        element->next = NULL;
        if (*head == NULL)
            *head = element;
        else
        {
            node_t *current = *head;
            node_t *prev = NULL;

            for (; current->next && comparator(element->data, current->data) >= 0; current = current->next)
                prev = current;

            if (prev == NULL)
            {
                if (comparator(element->data, current->data) < 0)
                {
                    element->next = *head;
                    *head = element;
                }
                else
                    (*head)->next = element;
            }
            else
            {
                if (!(current->next) && comparator(element->data, current->data) >= 0)
                    current->next = element;
                else
                {
                    element->next = current;
                    prev->next = element;
                }
            }
        }
    }
}

double get_mark_avg(node_t *head)
{
    double avg = 0.0;
    int count = 0, mark;

    for (; head; head = head->next)
    {
        mark = *(int *) head->data;
        avg += (double) mark;
        count++;
    }
    if (count > 0 && avg > EPS)
        avg /= count;

    return avg;
}

int comparator_avg(void *f_st, void *s_st)
{
    int result = 0;
    student_t *first = (student_t *) f_st;
    student_t *second = (student_t *) s_st;
    double f_avg = get_mark_avg(first->marks_l);
    double s_avg = get_mark_avg(second->marks_l);

    if (fabs(f_avg - s_avg) < EPS)
        result = 0;
    else if (f_avg < EPS + s_avg)
        result = 1;
    else
        result = -1;

    return result;
}