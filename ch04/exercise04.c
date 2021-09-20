#include <stdio.h>
void func_p_4_1();
void func_p_4_2();
void func_p_4_2_1();
void func_p_4_3();
void func_p_4_4();
void func_p_4_5();
void func_p_4_6();

// cc exercise04.c && ./a.out
int main()
{
    func_p_4_1();
    func_p_4_2();
    func_p_4_2_1();
    func_p_4_3();
    func_p_4_4();
    func_p_4_5();
    func_p_4_6();
    return 0;
}

void func_p_4_1()
{
    int a;
    printf("Enter a two-digit number: ");
    scanf("%d", &a);
    printf("The reversal is: %d\n", a % 10 * 10 + a / 10);
}

void func_p_4_2()
{
    int a, b;
    printf("Enter a two-digit number: ");
    scanf("%d", &a);
    b = a % 10 * 100;
    a /= 10;
    b += a % 10 * 10 + a / 10;
    printf("The reversal is: %d\n", b);
}

void func_p_4_2_1()
{
    int a, b;
    printf("Enter a two-digit number: ");
    scanf("%d", &a);
    b = 0;
    for (;;)
    {
        b = b * 10 + a % 10;
        a /= 10;
        if (a == 0)
        {
            break;
        }
    }
    printf("The reversal is: %d\n", b);
}

void func_p_4_3()
{
    int a, b, c;
    printf("Enter a two-digit number: ");
    scanf("%1d%1d%1d", &a, &b, &c);
    printf("The reversal is: %d%d%d\n", c, b, a);
}

void func_p_4_4()
{
    int a, b, c;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &a);
    b = 0;
    c = a;
    int i = 1;
    for (;;)
    {
        b += a % 8 * i;
        a /= 8;
        i *= 10;
        if (a == 0)
        {
            break;
        }
    }
    printf("In octal,your number is: 0%o 0%d\n", c, b);
}

void func_p_4_5()
{
    long long d;
    printf("Enter the first 11 digits of a UPC: ");
    scanf("%lld", &d);
    int sum1, sum2;
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
    printf("Check digit: %d\n", check);
}

void func_p_4_6()
{
    long long d;
    printf("Enter the first 12 digits of a EAN: ");
    scanf("%lld", &d);
    int sum1, sum2;
    for (int i = 0; i < 12; i++)
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
    printf("%d %d\n", sum1, sum2);
    int check;
    check = 9 - (sum1 * 3 + sum2 - 1) % 10;
    printf("Check digit: %d\n", check);
}