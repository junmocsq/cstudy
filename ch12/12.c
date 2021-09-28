#include <stdio.h>

int main(void)
{
    int a[2][3] = {1, 2, 3, 4, 5, 6};

    printf("%d %d\n", *a[0], *a[1]);
    int(*c)[3];
    int *d;
    c = a;
    d = a[0];
    printf("%p %p %p %p\n", a, a + 1, d, d + 1);
}