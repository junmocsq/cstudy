#include <stdio.h>

void func_12_1();
int main(void)
{
    func_12_1();
    return 0;
}
void func_12_1()
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];
    printf("%d %d %ld %d %d\n", *(p + 3), *(q - 3), q - p, p < q, *p < *q);
}