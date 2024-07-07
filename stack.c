#include <stdio.h>
#include "stack.h"


void createStack(Stack *ps)
{
    ps->top = 0;
}

void push(StackEntry e, Stack *ps)
{
    ps->entry[ps->top++] = e;
}


// *ps => in this case we used *ps for prevent wasting time , but the original stack will not change 
int isFull(Stack *ps)
{
    return ps->top == MAX_SIZE ;
}

void pop(StackEntry *pe, Stack *ps){
    *pe = ps->entry[--ps->top];
}

int isEmpty (Stack *ps){
    return !ps->top  ;
}


// *ps => in this case we used *ps for prevent wasting time , but the original stack will not change 
void stackTop(StackEntry *pe, Stack *ps){
    *pe = ps->entry[ps->top-1];
}


// *ps => in this case we used *ps for prevent wasting time , but the original stack will not change 
int stackSize(Stack *ps){
    return ps->top;
}

void clearStack(Stack *ps)
{
    ps->top = 0;
}

void traverseStack(Stack *ps){
    int i = ps->top ;
    while (i)
    {
        printf("%d\n",ps->entry[--i]);
    }
    
}