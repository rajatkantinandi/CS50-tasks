/* Program that creates a linked list with the elements from the command line arguments,
  Displays the list,
  Clears memory after program execution completion
  */

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  char *value;
  struct node *next;
} node;
node *insertLast(char *value, node *list);
void printList(node *list);
void freeMemory(node *list);
int main(int argc, char const *argv[])
{
  node *head = NULL;
  node *tail = NULL;
  if (argc > 0)
  {
    for (int i = 1; i < argc; i++)
    {
      tail = insertLast(argv[i], head);
      if (head == NULL)
      {
        head = tail;
      }
    }
    printf("The list: \n", head, head->value);
    printList(head);
    freeMemory(head);
    free(head);
    free(tail);
  }
  else
  {
    printf("Err: Invalid List size!\n");
  }
  return 0;
}
node *insertLast(char *value, node *list)
{
  node *newItem = malloc(sizeof(node));
  if (newItem == NULL)
  {
    return NULL;
  }
  else
  {
    newItem->value = value;
    newItem->next = NULL;
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
      if (ptr->next == NULL)
      {
        ptr->next = newItem;
        break;
      }
    }
    return newItem;
  }
}
void printList(node *list)
{
  for (node *ptr = list; ptr != NULL; ptr = ptr->next)
  {
    printf("%s -> ", ptr->value);
  }
  printf("Null\n");
}
void freeMemory(node *list)
{
  for (node *ptr = list; ptr != NULL; ptr = ptr->next)
  {
    free(ptr);
  }
}