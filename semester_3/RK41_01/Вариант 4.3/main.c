#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define READ_ERROR -1
#define ALLOCATE_ERROR -2
#define NONEXISTENT_FILE -3
#define INVALID_ARGUMENTS -4

#define STRLEN 255

//Вариант 4.3

typedef struct node node_t;

struct node
{
 void *data;
 node_t *next;
};

typedef struct
{
 char surname[STRLEN];
 int age;
 node_t *marks;
} student_t;

void push_back(node_t **list, node_t *node);

int read_file(FILE *f, node_t **students_list);

void print_students(node_t *students_list);

void free_list(node_t *list);

void free_marks(node_t *students_list);

int read_line(FILE *f, char *s, int limit);

int main(int argc, char **argv)
{
 setbuf(stdout, NULL);
 int ret = OK;
 if (argc == 3 && !strcmp(argv[1], "-f"))
 {
  node_t *students_list;
  students_list = NULL;
  FILE *f = fopen(argv[2], "r");
  if (f)
  {
   ret = read_file(f, &students_list);
   if (ret == OK)
    print_students(students_list);
   else
    printf("File not valid");
   fclose(f);
   free_marks(students_list);
   free_list(students_list);
  }
  else
  {
   printf("File not found");
   ret = NONEXISTENT_FILE;
  }
 }
 else
 {
  printf("Key not valid");
  ret = INVALID_ARGUMENTS;
 }
 return ret;
}

void push_back(node_t **list, node_t *node)
{
 if (*list)
 {
  node_t *cur = *list;
  for (; cur->next; cur = cur->next)
   ;
  cur->next = node;
 }
 else
 {
  *list = node;
 }
}

int read_file(FILE *f, node_t **students_list)
{
 int ret = OK;
 
 while (ret == OK && !feof(f))
 {
  node_t *new_student = malloc(sizeof(node_t));
  student_t *student = malloc(sizeof(student_t));
  if (student)
  {
   int rc = read_line(f, student->surname, STRLEN);
   if (rc == 1)
   {
    rc = fscanf(f, "%d", &(student->age));
    if (rc == 1)
    {
     student->marks = NULL;
     while (ret == OK)
     {
      node_t *node = malloc(sizeof(node_t));
      int *mark = malloc(sizeof(int));
      if (mark && node)
      {
       rc = fscanf(f, "%d", mark);
       if (rc == 1)
       {
        node->data = mark;
        node->next = NULL;
        push_back(&(student->marks), node);
        char ch;
        rc = fscanf(f, "%c", &ch);
        if (rc == 1 && (ch == ' ' || ch == '\n'))
        {
         if (ch == '\n')
         {
          new_student->data = student;
          new_student->next = NULL;
          push_back(students_list, new_student);
          break;
         }
        }
        else
        {
         ret = READ_ERROR;
         free(mark);
         free(node);
        }
       }
       else
       {
        ret = READ_ERROR;
        free(mark);
        free(node);
       }
      }
      else
       ret = ALLOCATE_ERROR;
     }
    }
    else
    {
     ret = READ_ERROR;
    }
   }
  }
  else
  {
   ret = ALLOCATE_ERROR;
  }
 }
 return ret;
}

void print_students(node_t *students_list)
{
 if (students_list)
 {
  for (node_t *node = students_list; node; node = node->next)
  {
   student_t *student = node->data;
   printf("%s %d ", student->surname, student->age);
   if (student->marks)
   {
    for (node_t *mark = student->marks; mark; mark = mark->next)
    {
     int *num = mark->data;
     printf("%d ", *num);
    }
   }
   printf("\n");
  }
 }
}

void free_list(node_t *list)
{
 if (list)
 {
  for (node_t *cur = list; cur;)
  {
   node_t *node = cur;
   cur = cur->next;
   free(node->data);
   free(node);
  }
 }
}

void free_marks(node_t *students_list)
{
 if (students_list)
 {
  for (node_t *cur = students_list; cur; cur = cur->next)
  {
   student_t *student = cur->data;
   free_list(student->marks);
  }
 }
}

int read_line(FILE *f, char *s, int limit)
{
 int ret = 1;
 char ch;
 int i = 0;
 while ((ch = fgetc(f)) != ' ' && ret == 1)
 {
  if (i == limit)
  {
   ret = 0;
  }
  else
  {
   s[i] = ch;
   i++;
  }
 }
 if (ret == 1)
  s[i] = '\0';
 return ret;
}