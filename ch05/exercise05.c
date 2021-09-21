#include <stdio.h>
void func_5_1();
void func_5_11();
void func_p_5_1();
void func_p_5_2();
void func_p_5_3();
void func_p_5_4();
void func_p_5_5();
void func_p_5_6();
void func_p_5_7();
void func_p_5_8();
void func_p_5_9();
void func_p_5_10();
void func_p_5_11();

// gcc exercise05.c && ./a.out
int main()
{
    // func_5_1();
    // func_5_11();

    // func_p_5_1();
    // func_p_5_2();
    // func_p_5_3();
    // func_p_5_4();
    // func_p_5_5();
    // func_p_5_6(); // 0 13800 15173 5
    // func_p_5_7();
    // func_p_5_8();
    // func_p_5_9();
    func_p_5_10();
    func_p_5_11();
    return 0;
}

void func_5_1()
{
    int i, j, k;
    i = 2;
    j = 3;
    k = i * j == 6;
    printf("%d\n", k);

    i = 5;
    j = 10;
    k = 1;
    printf("%d\n", k > i < j);
}

void func_5_11()
{
    int code;
    printf("Enter USA area code: ");
    scanf("%d", &code);
    switch (code)
    {
    case 229:
        printf("Albany");
        break;
    case 404:
    case 470:
    case 678:
    case 770:
        printf("Atlanta");
        break;
    case 478:
        printf("Macon");
        break;
    case 706:
    case 762:
        printf("Columbus");
        break;
    case 912:
        printf("Savannah");
        break;

    default:
        printf("Area code not recongized");
        break;
    }
    printf("\n");
}

void func_p_5_1()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    if (number <= 9)
    {
        printf("The number %d has %d digits\n", number, 1);
    }
    else if (number <= 99)
    {
        printf("The number %d has %d digits\n", number, 2);
    }
    else if (number <= 999)
    {
        printf("The number %d has %d digits\n", number, 3);
    }
    else
    {
        printf("The number %d has %d digits\n", number, 4);
    }
}

void func_p_5_2()
{
    int hour, minute;
    printf("Enter a 24-hour time(xx:xx): ");
    scanf("%d :%d", &hour, &minute);
    if (hour < 13)
    {
        printf("Equivalent 12-hour time: %d:%d AM\n", hour, minute);
    }
    else
    {
        printf("Equivalent 12-hour time: %d:%d PM\n", hour - 12, minute);
    }
}

void func_p_5_3()
{
    float trade, price, result;
    int num;
    printf("Enter value of num and price: ");
    scanf("%d %f", &num, &price);
    trade = num * price;
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
    if (num < 2000)
    {
        printf("竞争对手佣金: $%.2f\n", 33 + num * 0.03f);
    }
    else
    {
        printf("竞争对手佣金: $%.2f\n", 33 + num * 0.02f);
    }
}

void func_p_5_4()
{
    int speed;
    printf("Enter speed（海里/小时）: ");
    scanf("%d", &speed);
    if (speed < 1)
    {
        printf("Calm!!!");
    }
    else if (speed <= 3)
    {
        printf("Light air!!!");
    }
    else if (speed <= 27)
    {
        printf("Breeze!!!");
    }
    else if (speed <= 47)
    {
        printf("Gale!!!");
    }
    else if (speed <= 63)
    {
        printf("Storm!!!");
    }
    else
    {
        printf("Hurricane!!!");
    }
    printf("\n");
}

void func_p_5_5()
{
    float income;
    printf("Enter income（美元）: ");
    scanf("%f", &income);
    if (income < 750.00f)
    {
        printf("tax: $%.2f", income * 0.01f);
    }
    else if (income < 2250.00f)
    {
        printf("tax: $%.2f", 7.5f + (income - 750.00f) * 0.02f);
    }
    else if (income < 3750.00f)
    {
        printf("tax: $%.2f", 37.5f + (income - 2250.00f) * 0.02f);
    }
    else if (income < 5250.00f)
    {
        printf("tax: $%.2f", 82.5f + (income - 3750.00f) * 0.02f);
    }
    else if (income < 7000.00f)
    {
        printf("tax: $%.2f", 142.5f + (income - 5250.00f) * 0.02f);
    }
    else
    {
        printf("tax: $%.2f", 230.00f + (income - 7000.00f) * 0.02f);
    }
    printf("\n");
}

void func_p_5_6()
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
    int check2;
    printf("Enter check digit: ");
    scanf("%d", &check2);

    if (check == check2)
    {
        printf("Valid\n");
    }
    else
    {
        printf("Not Valid\n");
    }
}

// 两两比较，比较出的最大值和最小值再进行下一轮比较
void func_p_5_7()
{
    int a, b, c, d;
    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int min, max;
    if (b > a)
    {
        max = b;
        min = a;
    }
    else
    {
        max = a;
        min = b;
    }
    int min2, max2;
    if (c > d)
    {
        max2 = c;
        min2 = d;
    }
    else
    {
        max2 = d;
        min2 = c;
    }
    if (max < max2)
    {
        max = max2;
    }
    if (min > min2)
    {
        min = min2;
    }
    printf("Largest: %d\n", max);
    printf("Samllest: %d\n", min);
}

void func_p_5_8()
{
    int hour, minute;
    printf("Enter a 24-hour time(xx:xx): ");
    scanf("%d :%d", &hour, &minute);
    int minutes = hour * 60 + minute;
    if (minutes <= 8 * 60)
    {
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    }
    else if (minutes <= 9 * 60 + 43)
    {
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    }
    else if (minutes <= 11 * 60 + 19)
    {
        printf("Closest departure time is 11:19 p.m., arriving at 1:31 p.m.\n");
    }
    else if (minutes <= 12 * 60 + 47)
    {
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    }
    else if (minutes <= 14 * 60)
    {
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    }
    else if (minutes <= 15 * 60 + 45)
    {
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    }
    else if (minutes <= 19 * 60)
    {
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    }
    else if (minutes <= 21 * 60 + 45)
    {
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    }
    else
    {
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    }
}

void func_p_5_9()
{
    int m, d, y, m2, d2, y2;
    printf("Enter first date(mm/dd/yy): ");
    scanf("%d /%d /%d", &m, &d, &y);
    printf("Enter second date(mm/dd/yy): ");
    scanf("%d /%d /%d", &m2, &d2, &y2);

    if (y2 > y || y2 == y && (m2 > m || m2 == m && d2 > d))
    {
        printf("%d/%.2d/%.2d is earlier than %d/%.2d/%.2d\n", m, d, y, m2, d2, y2);
    }
    else if (y2 == y && m2 == m && d2 == d)
    {
        printf("%d/%.2d/%.2d is equal %d/%.2d/%.2d\n", m, d, y, m2, d2, y2);
    }
    else
    {
        printf("%d/%.2d/%.2d is earlier than %d/%.2d/%.2d\n", m2, d2, y2, m, d, y);
    }
}
void func_p_5_10()
{
    int grade;
    printf("Enter numberical grade: ");
    scanf("%d", &grade);
    switch (grade / 10)
    {
    case 9:
    case 10:
        printf("Letter grade: A\n");
        break;
    case 8:
        printf("Letter grade: B\n");
        break;
    case 7:
        printf("Letter grade: C\n");
        break;
    case 6:
        printf("Letter grade: D\n");
        break;
    default:
        printf("Letter grade: F\n");
        break;
    }
}
void func_p_5_11()
{
    printf("Enter a two-digit number: ");
    int number;
    scanf("%d", &number);
    printf("Your entered the number ");
    switch (number)
    {
    case 11:
        printf("eleven");
        break;
    case 12:
        printf("twleve");
        break;
    case 13:
        printf("thirteen");
        break;
    case 14:
        printf("fourteen");
        break;
    case 15:
        printf("fifteen");
        break;
    case 16:
        printf("sixteen");
        break;
    case 17:
        printf("seventeen");
        break;
    case 18:
        printf("eighteen");
        break;
    case 19:
        printf("nineteen");
        break;
    }
    switch (number / 10)
    {
    case 2:
        printf("twenty-");
        break;
    case 3:
        printf("thirty-");
        break;
    case 4:
        printf("forty-");
        break;
    case 5:
        printf("fifty-");
        break;
    case 6:
        printf("sixty-");
        break;
    case 7:
        printf("seventy-");
        break;
    case 8:
        printf("eighty-");
        break;
    case 9:
        printf("ninety-");
        break;
    }
    if (number / 10 > 1)
    {
        switch (number % 10)
        {
        case 1:
            printf("one");
            break;
        case 2:
            printf("two");
            break;
        case 3:
            printf("three");
            break;
        case 4:
            printf("four");
            break;
        case 5:
            printf("five");
            break;
        case 6:
            printf("six");
            break;
        case 7:
            printf("seven");
            break;
        case 8:
            printf("eight");
            break;
        case 9:
            printf("nine");
            break;
        }
    }
    printf("\n");
}