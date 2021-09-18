#include <stdio.h>
int func2_1();
void func_p2_1();
float func_p2_2();
float func_p2_3();
float func_p2_4();
float func_p2_5();
float func_p2_6();
void func_p2_7();
void func_p2_8();

int main()
{
    func2_1();
    func_p2_1();
    func_p2_2();
    func_p2_3();
    func_p2_4();
    func_p2_5();
    func_p2_6();
    func_p2_7();
    func_p2_8();
}

int func2_1()
{
    printf("Hello, world\n");
    return 0;
}

void func_p2_1()
{
    char star = '*';
    printf("%8c\n", star);
    printf("%7c\n", star);
    printf("%6c\n", star);
    printf("%c%4c\n", star, star);
    printf("%2c%2c\n", star, star);
    printf("%3c\n", star);
}

float func_p2_2()
{
    float volume;
    float r = 10.0f;
    float pi = 3.14f;
    volume = 4.0f / 3.0f * pi * r * r * r;
    printf("r:%10.2f volume:%10.3f\n", r, volume);
    return volume;
}

float func_p2_3()
{
    float volume;
    float r;
    printf("请输入需要计算的球半径：");
    scanf("%f", &r);
    float pi = 3.14f;
    volume = 4.0f / 3.0f * pi * r * r * r;
    printf("r:%10.2f volume:%10.3f\n", r, volume);
    return volume;
}

float func_p2_4()
{
    float amount = 0.0f;
    float tax = 0.0f;
    printf("Enter an amount: ");
    scanf("%f", &amount);
    tax = amount + 0.05f * amount;
    printf("With tax add: $%5.2f\n", tax);
    return tax;
}

float func_pow(float x, int times)
{
    float res = 1.0f;
    for (int i = 0; i < times; i++)
    {
        res *= x;
    }
    return res;
}

float func_p2_5()
{
    float x = 0.0f;
    float sum = 0.0f;
    printf("Enter an x: ");
    scanf("%f", &x);
    // sum = 3.0f * func_pow(x, 5) + 2.0f * func_pow(x, 4) - 5.0f * func_pow(x, 3) - func_pow(x, 2) + 7.0f * x - 6.0f;
    sum = 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
    printf("3x^5+2x^4-5x^3-x^2+7x-6 = %10.2f\n", sum);
    return sum;
}

// Horner
float func_p2_6()
{
    float x = 0.0f;
    float sum = 0.0f;
    printf("Enter an x: ");
    scanf("%f", &x);
    // sum = 3.0f * func_pow(x, 5) + 2.0f * func_pow(x, 4) - 5.0f * func_pow(x, 3) - func_pow(x, 2) + 7.0f * x - 6.0f;
    sum = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("3x^5+2x^4-5x^3-x^2+7x-6 = %10.2f\n", sum);
    return sum;
}

void func_p2_7()
{
    int amount = 0.0f;
    int amount_20, amount_10, amount_5, amount_1;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);
    amount_20 = amount / 20;
    amount %= 20;

    amount_10 = amount / 10;
    amount %= 10;

    amount_5 = amount / 5;
    amount %= 5;

    amount_1 = amount;

    printf("$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n",
           amount_20, amount_10, amount_5, amount_1);
    return;
}

void func_p2_8()
{
    float loan = 0.0f;
    float rate = 0.0f;
    float payment = 0.0f;
    float sum;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &rate);
    printf("Enter monthly payment: ");
    scanf("%f", &payment);

    sum = loan * (rate / 1200.0f + 1) - payment;
    printf("Balance remaining after first payment: $%8.2f\n", sum);
    sum = sum * (rate / 1200.0f + 1) - payment;
    printf("Balance remaining after second payment: $%8.2f\n", sum);
    sum = sum * (rate / 1200.0f + 1) - payment;
    printf("Balance remaining after third payment: $%8.2f\n", sum);
    return;
}