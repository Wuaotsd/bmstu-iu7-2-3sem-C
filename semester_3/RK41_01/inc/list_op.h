#ifndef _LIST_OP_H_
#define _LIST_OP_H_

#include <stdlib.h>
#include <math.h>
#include "structs.h"
#include "errors.h"

#define EPS 1e-8

int list_push(node_t **head, void *element);
node_t *node_create(void *data);

void free_marks(node_t **head);
void free_students(node_t **studentslist);

double get_mark_avg(node_t *head);
int comparator_avg(void *f_st, void *s_st);
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

#endif