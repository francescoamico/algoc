#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "item.h"

struct stackNode {
  Item item;
  struct stackNode *next;
};

typedef struct stackNode StackNode;
typedef StackNode * StackNodePtr;

struct stack { StackNodePtr top; int N; };

S stackInit() {
  S stack = malloc(sizeof(S));
  stack->top = NULL;
  stack->N = 0;
  return stack;
}

int stackIsEmpty(S stack) {
  return ((stack->top) == NULL);
}

void stackPush(S stack, Item item) {
  StackNodePtr x = malloc(sizeof(*x));
  if (x != NULL) {
    x->item = item;
    x->next = stack->top;
    stack->top = x;
    (stack->N)++;
  }
  else puts("Not pushed. No memory.\n"); 
}

Item stackPop(S stack) {
  if (stack->top != NULL) {
    StackNodePtr t = stack->top;
    Item item = stack->top->item;
    stack->top = stack->top->next;
    free(t);
    (stack->N)--;
    return item;
  }
  else puts("Not popped. Stack underflow.\n");
  return NULLITEM;
}

Item stackPeek(S stack) {
  if (stack->top != NULL) {
    Item item = stack->top->item;
    return item;
  }
  else puts("Stack empty.\n");
  return NULLITEM;
}

int stackSize(S stack) {
  return(stack->N);
}
