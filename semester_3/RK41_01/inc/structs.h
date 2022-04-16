#ifndef _STRUCTS_H_
#define _STRUCTS_H_

#define STR_MAX 256
#define LIST_SIZE 50

typedef struct st_node
{
	void *data;
	struct st_node *next;
} node_t;

typedef struct st_student
{
	char name[STR_MAX];
	int age;
	node_t *marks_l;
} student_t;

#endif