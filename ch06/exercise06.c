#include <stdio.h>

void func_p_6_1();
void func_p_6_2();
void func_p_6_3();
void func_p_6_4();
void func_p_6_5();
void func_p_6_6();
void func_p_6_7();
void func_p_6_8();
void func_p_6_9();
void func_p_6_10();
void func_p_6_11();
void func_p_6_12();

// gcc exercise06.c && ./a.out
int main()
{
    func_p_6_1();
    func_p_6_2();
    func_p_6_3();
    func_p_6_4();
    func_p_6_5();
    func_p_6_6();
    func_p_6_7();

    func_p_6_8();
    func_p_6_9();
    func_p_6_10();
    func_p_6_11();
    func_p_6_12();
    return 0;
}

void func_p_6_1()
{
    float num, max;
    max = -1.0f;
    for (;;)
    {
        printf("Enter a number: ");
        scanf("%f", &num);
        if (num <= 0.0f)
        {
            break;
        }
        if (num > max)
        {
            max = num;
        }
    }
    printf("The largest number entered was %.2f\n", max);
}
int gcd(int m, int n)
{
    int temp;
    while (n != 0)
    {
        temp = m % n;
        m = n;
        n = temp;
    }
    return m;
}
void func_p_6_2()
{
    int m, n;
    printf("Enter two integers: ");
    scanf("%d %d", &m, &n);
    printf("Greatest common divisor: %d\n", gcd(m, n));
}

void func_p_6_3()
{
    printf("Enter a fraction (a/b): ");
    int a, b;
    scanf("%d /%d", &a, &b);
    int g = gcd(a, b);
    printf("In lowest terms: %d/%d", a / g, b / g);
}

void func_p_6_4()
{
    float trade, result;
    while (1)
    {
        printf("Enter value of trade: ");
        scanf("%f", &trade);
        if (trade == 0)
        {
            break;
        }
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
    }
}
void func_p_6_5()
{
    long long a, b;
    printf("Enter a number: ");
    scanf("%lld", &a);
    b = 0;
    int zero = 0, flag = 0;
    do
    {
        if (flag == 0 && a % 10 == 0)
        {
            ++zero;
        }
        else
        {
            flag = -1;
        }
        b = b * 10 + a % 10;
        a /= 10;
    } while (a > 0);
    printf("The reversal is: ");
    for (int i = 0; i < zero; i++)
    {
        printf("0");
    }
    printf("%lld\n", b);
}
void func_p_6_6()
{
    printf("Enter a number: ");
    int n;
    scanf("%d", &n);
    int i = 2;
    while (i * i <= n)
    {
        printf("%d\n", i * i);
        i += 2;
    }
}
void func_p_6_7()
{
    int n, odd, square;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    square = 1;
    odd = 3;
    for (int i = 1; i <= n; ++i)
    {
        printf("%10d%10d\n", i, square);
        square += odd;
        odd += 2;
    }
}

void func_p_6_8()
{
    int month, start;
    printf("Enter number of days in month: ");
    scanf("%d", &month);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start);
    for (int i = 1; i < start; i++)
    {
        printf("%5s", "");
    }
    for (int i = 1; i <= month; i++)
    {
        printf("%5d", i);
        if ((i + start - 1) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}
void func_p_6_9()
{
    float loan = 0.0f;
    float rate = 0.0f;
    float payment = 0.0f;
    float sum;
    int num;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        loan = loan * (rate / 1200.0f + 1) - payment;
        printf("Balance remaining after %d times payment: $%8.2f\n", i + 1, loan);
    }
    return;
}
void func_p_6_10()
{

    int m, d, y, m2, d2, y2;
    m2 = 0;
    d2 = 0;
    y2 = 10000;
    while (1)
    {
        printf("Enter a date(mm/dd/yy): ");
        scanf("%d /%d /%d", &m, &d, &y);
        if (m == 0 && d == 0 && y == 0)
        {
            break;
        }
        if (y2 > y || y2 == y && (m2 > m || m2 == m && d2 > d))
        {
            m2 = m;
            d2 = d;
            y2 = y;
        }
    }
    printf("%d/%.2d/%.2d is the earlier date\n", m2, d2, y2);
}
long long factorial(int n)
{
    long long res = 1;
    for (int i = 2; i <= n; i++)
    {
        res *= i;
    }
    return res;
}
void func_p_6_11()
{
    float sum = 1.0f;
    int n = 20;
    for (int i = 1; i < n; i++)
    {
        sum += 1.0f / factorial(i);
    }
    printf("e is %.10f\n", sum);
}
void func_p_6_12()
{
    float sum = 1.0f, temp, std;
    printf("Enter a small float number: ");
    scanf("%f", &std);
    int i = 1;
    for (;; i++)
    {
        temp = 1.0f / factorial(i);
        sum += temp;
        if (temp < std)
        {
            break;
        }
    }
    printf("n is %d, e is %.10f\n", i, sum);
}