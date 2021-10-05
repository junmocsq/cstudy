#ifndef TEST2_H
#define TEST2_H
#include <stdio.h>
static int i = 10;
typedef void (*pa)(void);
void f1();
static void f2(void);

pa f3();
void (*f4(void))();


static inline void f10()
{
    printf("online---f10\n");
}
#endif