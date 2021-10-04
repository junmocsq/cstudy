#include <stdio.h>
#include <stdlib.h>

int f1(int *a, int *b)
{
    *a = 5;
    *b = 6;
    return *a + *b;
}

int f2(int *restrict a, int *restrict b)
{
    *a = 5;
    *b = 6;
    return *a + *b;
}

int main(void)
{

    int *restrict p;
    int *restrict q;
    p = malloc(sizeof(int));
    q = p;
    *q = 999;
    *p = 888;
    printf("%d %d\n", *p, *q);

    int ar[10] = {0};
    int *restrict restar = (int *)calloc(10, sizeof(int));
    int *restrict par = ar;
    for (int n = 0; n < 10; n++)
    {
        par[n] += 5;
        restar[n] += 5;
        ar[n] *= 2;
        par[n] += 3;
        restar[n] += 3;
    }
    printf("%d %d\n", par[0], restar[0]);

    int a;
    printf("%d %d\n", f1(&a, &a), f2(&a, &a));

    char ***a22 = NULL;
    printf("%p %p\n", a22, *a22);
    return 0;
}