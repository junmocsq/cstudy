#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

struct stack
{
    int value;
    Stack next;
};
static Stack make_node()
{
    Stack res = malloc(sizeof(*res));
    if (res == NULL)
    {
        printf("malloc failed!\n");
        exit(EXIT_FAILURE);
    }
    return res;
}
Stack make_stack()
{
    return make_node();
}

bool push(Stack s, int i)
{
    Stack new_node = make_node();
    new_node->value = i;
    new_node->next = s->next;
    s->next = new_node;
    return true;
}
bool is_empty(Stack s)
{
    return s->next == NULL;
}
int pop(Stack s)
{
    if (is_empty(s))
        return -1;
    int res = s->next->value;
    Stack top = s->next;
    s->next = s->next->next;
    free(top);
    return res;
}