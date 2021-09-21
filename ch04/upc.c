#include <stdio.h>

// cc upc.c && ./a.out
int main()
{
    int a, b, c;

    printf("Enter the first (single) digit: ");
    scanf("%d", &a);

    printf("Enter first group of five digits: ");
    scanf("%d", &b);

    printf("Enter second group of five digits: ");
    scanf("%d", &c);

    long long d;
    d = a * 1e+10 + b * 1e+5 + c;
    int sum1, sum2;
    sum1 = 0;
    sum2 = 0;
    for (int i = 0; i < 11; i++)
    {
        if (i % 2 == 0)
        {
            sum1 += d % 10;
        }
        else
        {
            sum2 += d % 10;
        }
        d /= 10;
    }
    int check;
    check = 9 - (sum1 * 3 + sum2 - 1) % 10;
    printf("Check digit: %d", check);
    return 0;
}