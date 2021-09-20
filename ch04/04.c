#include <stdio.h>

// cc 04.c && ./a.out
int main()
{
    printf("%d %d %d %d\n", -9 / 7, 9 / -7, -9 % 7, 3 * -5 + 6); // -1 -1 -2 2
    int i, j, k;
    i = 1;
    j = 10;
    k = 100;
    i += j += k;
    printf("%d %d %d\n", i, j, k); // 111 110 100

    i = 10;
    printf("%d\n", -i++); // -10
    printf("%d\n", i);    // 11
    printf("%d\n", -++i); // -12
    return 0;
}