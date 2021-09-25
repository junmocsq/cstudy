#include <stdio.h>
extern int mm;
void test_1001(int a, int b, int c)
{
    printf("%d %d %d\n", a, b, c);
}
int main()
{
    int a, b, c;

    printf("%d %d %d\n", a, b, c);
    test_1001(a, b, c);
    printf("mm:%d\n", mm);
}