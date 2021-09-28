#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100
int contents[STACK_SIZE];
int *top_ptr = contents;
void make_empty(void)
{
    top_ptr = contents;
}

bool is_empty(void)
{
    return top_ptr == contents;
}
bool is_full(void)
{
    return top_ptr - contents == STACK_SIZE;
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
        *top_ptr++ = i;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();
    else
        return *--top_ptr;
    return 0;
}