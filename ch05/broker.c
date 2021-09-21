#include <stdio.h>

// gcc broker.c && ./a.out
int main()
{
    float trade, result;
    printf("Enter value of trade: ");
    scanf("%f", &trade);
    if (trade < 2500)
    {
        result = 30 + trade * 0.017;
    }
    else if (trade < 6250)
    {
        result = 56 + trade * 0.0066;
    }
    else if (trade < 20000)
    {
        result = 76 + trade * 0.0034;
    }
    else if (trade < 50000)
    {
        result = 100 + trade * 0.0022;
    }
    else if (trade < 500000)
    {
        result = 155 + trade * 0.0011;
    }
    else
    {
        result = 255 + trade * 0.0009;
    }
    if (result < 39.0f)
    {
        result = 39.0f;
    }
    printf("Commission: $%.2f\n", result);
    return 0;
}