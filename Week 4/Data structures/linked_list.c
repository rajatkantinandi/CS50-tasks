/* Program that creates a linked list with the elements from the command line arguments,
  Displays the list,
  Clears memory after program execution completion
  */

#include <stdio.h>
#include <stdlib.h>
typedef struct nodeT
{
  char *value;
  struct nodeT *next;
} node;
node *insertLast(char *value, node *last);
node *insertFirst(char *value,node *head);
void printList(node *list);
void freeMemory(node *list);
int main(int argc, char const *argv[])
{
  node *head = NULL;
  node *tail = NULL;
  int choice=1;
  printf("Enter the mode of insertion: \n 1) At First\n 2) At Last \n");
  scanf("%d",&choice);
  if (argc > 0)
  {
    for (int i = 1; i < argc; i++)
    {
      if(choice==1){
        if(head==NULL){
        tail=insertFirst(argv[i],head);
        head=tail;
        }
        else{          
        head=insertFirst(argv[i],head);
        }
      }
      else if(choice==2){
        tail = insertLast(argv[i], tail);
        if (head == NULL)
        {
          head = tail;
        }
      }
      else{
        printf("Invalid choice !! \n");
      }
    }
    printf("The list: \n");
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
node *insertLast(char *value, node *last)
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
    if (last == NULL)
    {
      last = newItem;
    }
    else
      last->next = newItem;
    return newItem;
  }
}
node *insertFirst(char *value, node *head)
{
  node *newItem = malloc(sizeof(node));
  if (newItem == NULL)
  {
    return NULL;
  }
  else
  {
    newItem->value = value;
    if (head == NULL)
    {
      newItem->next = NULL;
    }
    else
      newItem->next = head;
    head=newItem;
    return head;
  }
}
void printList(node *list)
{
  printf("Head -> ");
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