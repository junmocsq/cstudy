#include <stdio.h>
#include "stack.h"

// cc stack.c 19.c && ./a.out
int main(void){
    Stack s = make_stack();
    push(s,100);
    push(s,200);
    push(s,300);
    
    printf("%d %d %d\n",pop(s),pop(s),pop(s));
    return 0;
}