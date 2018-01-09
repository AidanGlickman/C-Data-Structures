#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

typedef struct node {
  int val;
  struct node* next;
} Node;

struct stack {
  int stackSize;
  Node* head;
};

Stack* createStack ()
{
  Stack* s = malloc (sizeof(Stack));
  s->head = NULL;
  s->stackSize = 0;
  return s;
}

void push (Stack *s, int val)
{
	Node *newNode = malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = s->head;
  s->head=newNode;
}

int pop (Stack *s)
{
  if(isStackEmpty(s) == 1){
    return INT_MIN;
  }
	int val = s->head->val;
  s->head = s->head->next;
  return val;
}

int isStackEmpty (Stack *s)
{
	if(s->head == NULL){
    return 1;
  }
  return 0;
}

int getStackSize(Stack *s)
{
  if(isStackEmpty(s)==1){
    return 0;
  }

  int i = 0;

  Node* next = s->head;

  while(next!=NULL){
    i++;
    next = next->next;
  }

  return i;
}
