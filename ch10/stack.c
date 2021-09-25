#include <stdbool.h>

#define STACK_SIZE 100
int contents[STACK_SIZE];
int top = 0;
void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}
bool is_full(void)
{
    return top == STACK_SIZE;
}
void stack_overflow()
{
    printf("stack is full!\n");
    exit(1);
}
void stack_underflow()
{
    printf("stack is empty!\n");
    exit(2);
}
void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}