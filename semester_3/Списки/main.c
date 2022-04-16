#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define INVALID_INDEX 1
#define EMPTY_LIST 2
#define NO_MEMORY 3
#define NO_LIST 4
#define POINTER_ERROR 5
#define WRONG_CONTENT 6

struct List
{
  struct Node *head;
  struct Node *bottom;
  int count;
};

struct Node
{
  int inf;
  struct Node *next;
  struct Node *prev;
};
  
struct List init();
int delete_elem(struct List *list, int index);
void free_node(struct Node *node);
int insert(struct List *list, int index, int inf);
int insert_by_ptr(struct List *list, struct Node* node, int inf);
int print(struct List *list);
int sort(struct List *list);
int clean(struct List *list);  
void print_code(int code);  

int main(void) 
{
  printf("\n---INIT LIST---\n");
  struct List list = init();
  
  print_code(print(&list));
  
  printf("\n---INSERT ELEMS TO LIST---\n");
  print_code(insert(&list, 0, 1));
  print_code(insert(&list, 0, 2));
  print_code(insert(&list, 1, 3));
  print_code(insert(&list, 1, 4));
  print_code(insert(&list, 0, 5));
  print_code(insert(&list, 0, 6));
  
  print_code(print(&list));

  printf("\n---DELETE ELEM FROM LIST---\n");
  print_code(delete_elem(&list, 0));

  print_code(print(&list));

  printf("\n---SORT LIST---\n");
  print_code(sort(&list));

  print_code(print(&list));

  printf("\n---CLEAN LIST---\n");
  print_code(clean(&list));

  print_code(print(&list));

  return 0;
}

struct List init()
{
  struct List list;
  list.bottom = list.head = NULL;
  list.count = 0;
  return list;
}

void print_code(int code)
{
  printf("Code: ");
  switch(code)
  {
    case OK:
      printf("OK\n");
      break;
    case INVALID_INDEX:
      printf("INVALID INDEX ERROR\n");
      break;
    case EMPTY_LIST:
      printf("EMPTY LIST ERROR\n");
      break;
    case NO_MEMORY:
      printf("NO MEMORY ERROR\n");
      break;
    case NO_LIST:
      printf("NO LIST ERROR\n");
      break;
    case POINTER_ERROR:
      printf("POINTER ERROR\n");
      break;
    case WRONG_CONTENT:
      printf("LIST WRONG CONTENT ERROR\n");
      break;
    default:
      printf("UNKNOWN ERROR\n");
      break;
  }
}

int insert(struct List *list, int index, int inf)
{
  int exit_code = (index >= 0) ? OK : INVALID_INDEX;
  struct Node *node = list->bottom;

  for (int i = 0; exit_code == OK && i < index; i++)
  {
      if (node)
          node = node->next;
      else
          exit_code = INVALID_INDEX;
  }

  struct Node *new_node = NULL;
  if (exit_code == OK)
  {
    new_node = (struct Node*)malloc(sizeof(struct Node));

    if (!new_node)
      exit_code = NO_MEMORY;
  }

  if (exit_code == OK)
  {
    new_node->inf = inf;
    new_node->next = node;

    if (node)
    {
      new_node->prev = node->prev;

      if (node->prev)
        node->prev->next = new_node;

      if (list->bottom == node)
        list->bottom = new_node;

      node->prev = new_node;
    }
    else
    {
      new_node->prev = list->head;

      if (list->head)
        list->head->next = new_node;
      else
        list->bottom = new_node;

      list->head = new_node;
    }

    list->count++;
  }

  return exit_code;
}

int insert_by_ptr(struct List *list, struct Node* node, int inf)
{
  int exit_code = OK;
  struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

  if (!new_node)
    exit_code = NO_MEMORY;

  if (exit_code == OK)
  {
    new_node->inf = inf;
    new_node->next = node;

    if (node)
    {
      new_node->prev = node->prev;

      if (node->prev)
        node->prev->next = new_node;

      if (list->bottom == node)
        list->bottom = new_node;

      node->prev = new_node;
    }
    else
    {
      new_node->prev = list->head;

      if (list->head)
        list->head->next = new_node;
      else
        list->bottom = new_node;

      list->head = new_node;
    }

    list->count++;
  }

  return exit_code;
}

int delete_elem(struct List *list, int index)
{
  int i = 0;
  int result = OK;
  if (list == NULL)
  {
    result = NO_LIST;
  }
  else if (list->bottom == NULL || list->head == NULL)
  {
    result = WRONG_CONTENT;
  }
  else if (list->bottom == NULL && list->head == NULL)
  {
    result = EMPTY_LIST;
  }
  struct Node *t = list->bottom;
  while (result == OK && i < index && t->next != NULL)
  {
    t = t->next;
    i++;
  }
  if (result == OK && i != index)
  {
    result = INVALID_INDEX;
  }
  else if (result == OK)
  {
      if (t->prev == NULL && t->next == NULL)
      {
        list->bottom = NULL;
        list->head = NULL;
      }
      else if (t->prev == NULL)
      {
        list->bottom = list->bottom->next;
        list->bottom->prev = NULL;
      }
      else if (t->next == NULL)
      {
        list->head = t->prev;
        list->head->next = NULL;
      }
      else
      {
        t->prev->next = t->next;
        t->next->prev = t->prev;
      }
      list->count--;
      free_node(t);
  }
  return result;
}

void free_node(struct Node *node)
{
  free(node);
  node = NULL;
}


void start_insert_sort(struct Node **sorted, struct Node *newNode, int n)
{
  struct Node* cur;
  if (!*sorted)
    *sorted = newNode;
  else if ((*sorted)->inf > newNode->inf)
  {
    newNode->next = *sorted;
    newNode->next->prev = newNode;
    *sorted = newNode;
  }
  else
  {
    cur = *sorted;
    for (; cur->next && cur->next->inf < newNode->inf; cur = cur->next);
    newNode->next = cur->next;
    if (cur->next)
      newNode->next->prev = newNode;
    cur->next = newNode;
    newNode->prev = cur;
  }
}


int sort(struct List *list)
{
  struct Node *sorted = NULL;
  struct Node *current = list->bottom;
  for (int i = 0; i < list->count; i++)
  {
    struct Node *next = current->next;
    current->prev = current->next = NULL;
    start_insert_sort(&sorted, current, list->count);
    current = next;
  }
  list->bottom = sorted;
  // я сделал 
  // всё
  return OK;
}

int print(struct List *list)
{
  int result = OK;
  struct Node *previous = NULL;
  struct Node *current = list->bottom;
  if (current && list->count)
  {
    printf("Всего в списке %d элементов\n", list->count);
    while (current && result == OK)
    {
      printf("%d\n", current->inf);
      previous = current;
      current = current->next;
      if (current && (previous != current->prev || previous == current))
        result = POINTER_ERROR;
    }
  }
  else
    printf("Список пуст\n");
  if (result != OK)
    printf("Печать прекращена из-за ошибки\n");
  return result;
}

int clean(struct List *list)
{
  struct Node *next;
  struct Node *cur = list->bottom;

  while (cur)
  {
    next = cur->next;
    free_node(cur);
    cur = next;
  }
  list->count = 0;

  return OK;
}