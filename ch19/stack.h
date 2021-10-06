#ifndef STACK_H
#define STACK_H
#include <stdbool.h>

typedef struct stack *Stack;

Stack make_stack();
bool push(Stack s, int i);
int pop(Stack s);
#endif