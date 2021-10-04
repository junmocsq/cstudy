#ifndef STACK_C
#define STACK_C
#include <stdlib.h>
#include <stdbool.h>
void *my_malloc(int n)
{
    void *result = malloc(n);
    if (result == NULL)
    {
        printf("malloc memory failed!\n");
        exit(EXIT_FAILURE);
    }
    return result;
}

// 栈的链表实现
typedef struct stackNode
{
    int value;
    struct stackNode *next;
} stackNode;
typedef struct stackHead
{
    stackNode *head;
} stackHead;
stackHead *make_stack()
{
    stackHead *result = my_malloc(sizeof(*result));
    result->head = NULL;
    return result;
}
bool stack_is_empty(stackHead *h)
{
    return h->head == NULL;
}
stackNode *pop(stackHead *h)
{
    if (stack_is_empty(h))
        return NULL;
    stackNode *result = h->head;
    h->head = h->head->next;
    return result;
}
void push(stackHead *h, int value)
{
    stackNode *node = my_malloc(sizeof(*node));
    node->value = value;
    node->next = h->head;
    h->head = node;
}
#endif