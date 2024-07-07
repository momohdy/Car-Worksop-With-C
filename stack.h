#ifndef STACK_H
#define STACK_H

#include "global.h"

typedef Customer StackEntry;

typedef struct stack
{
    int top;
    StackEntry entry[MAX_SIZE];
} Stack;

void createStack(Stack *ps);
void push(StackEntry e, Stack *ps);
int isFull(Stack *ps);
void pop(StackEntry *pe, Stack *ps);
int isEmpty(Stack *ps);
void stackTop(StackEntry *pe, Stack *ps);
int stackSize(Stack *ps);
void clearStack(Stack *ps);
void traverseStack(Stack *ps);

#endif /* STACK_H */
