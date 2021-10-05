#include <stdio.h>
#include <string.h>
#include "2.h"
int cc;
extern int bb;
extern int arr[10];

void func(pa f, int size)
{
    printf("===%d===\n", size);
    f();
    printf("===%d===\n", size);
}
int (*f(int v))[]
{
    static int arr[5] = {11, 22, 33, 44, 55};
    for(int i=0;i<5;i++){
        arr[i] += v;
    }
    return &arr;
}
// int (*res)[5] = f(10);
//printf("%d %d\n",(*res)[0],(*res)[4]);

// cc 1.c 2.c && ./a.out
int main(void)
{
    printf("i:%d cc:%d\n", i, cc);

    f1();
    func(f4(), 99999);
    static int dd;
    printf("dd:%d\n", dd);
    dd = 100;
    printf("arr size:%lu\n", sizeof(arr));
    f10();
    int (*res)[5] = f(10);
    printf("%d %d\n",(*res)[0],(*res)[4]);
    return 0;
}

// void f10(){
//      printf("1--f10\n");
//  }
// static void f2(void){
//      printf("01---static f2\n");
// }
