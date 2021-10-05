#include <stdio.h>
#include "2.h"
int cc = 10;
int arr[20] = {0};
static int bb = 20;
//  extern void f10();
void f1()
{
    printf("f1\n");
    f2();
    //  f10();
}
static void f2(void)
{
    printf("static f2\n");
}

pa f3()
{
    printf("2---f3\n");
    return f2;
}

void (*f4(void))()
{
    printf("2---f4\n");
    f10();
    return f2;
}