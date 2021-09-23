#include <stdio.h>
#include <ctype.h>
#include <math.h>
void func_p_7_1();
void func_p_7_2();
void func_p_7_3();
void func_p_7_4();
void func_p_7_5();
void func_p_7_6();
void func_p_7_7();
void func_p_7_8();
void func_p_7_9();
void func_p_7_10();
void func_p_7_11();
void func_p_7_12();
void func_p_7_13();
void func_p_7_14();
void func_p_7_15();

// gcc exercise07.c&& ./a.out
int main()
{
    // func_p_7_1();
    // func_p_7_2();
    // func_p_7_3();
    // func_p_7_4();
    // func_p_7_5();
    // func_p_7_6();
    // func_p_7_7();
    // func_p_7_8();
    // func_p_7_9();
    // func_p_7_10();
    // func_p_7_11();
    // func_p_7_12();
    // func_p_7_13();
    // func_p_7_14();
    func_p_7_15();
    return 0;
}

void func_p_7_1()
{
    // short int 16; int 32; long int 64; long long int 64
    long long int n = 0xbfffffff;
    long long int square;
    long long int i;
    for (i = n - 100; i < n; i++)
    {
        square = i * i;
        printf("%lld %lld\n", i, square);
    }
}
void func_p_7_2()
{
    char c;
    int n = 72;
    for (int i = 1; i <= n; i++)
    {
        printf("%d %d\n", i, i * i);
        if (i % 24 == 0)
        {
            printf("Please Enter to continue...\n");
            while ((c = getchar()) != '\n')
            {
                putchar(c);
            }
            putchar('\n');
        }
    }
}
void func_p_7_3()
{
    double sum = 0, n;
    printf("This param sums a series of double.\n");
    printf("Enter double (0 to terminate): ");
    scanf("%lf", &n);
    while (n != 0)
    {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %.3lf\n", sum);
}
void func_p_7_4()
{
    printf("Enter phone number: ");
    char c;
    while ((c = getchar()) != '\n')
    {
        c = toupper(c);
        if (c >= 'A' && c <= 'Z')
        {
            if (c <= 'R')
                putchar((c - 'A') / 3 + '2');
            else if (c == 'S')
                putchar('7');
            else if (c <= 'V')
                putchar('8');
            else
                putchar('9');
        }
        else
        {
            putchar(c);
        }
    }
    putchar('\n');
}
void func_p_7_5()
{
    char mm[26];
    mm['A' - 'A'] = mm['E' - 'A'] = mm['I' - 'A'] = mm['L' - 'A'] = mm['N' - 'A'] = mm['O' - 'A'] = mm['R' - 'A'] = mm['S' - 'A'] = mm['T' - 'A'] = mm['U' - 'A'] = 1;
    mm['D' - 'A'] = mm['G' - 'A'] = 2;
    mm['B' - 'A'] = mm['C' - 'A'] = mm['M' - 'A'] = mm['P' - 'A'] = 3;
    mm['F' - 'A'] = mm['H' - 'A'] = mm['V' - 'A'] = mm['W' - 'A'] = mm['Y' - 'A'] = 4;
    mm['K' - 'A'] = 5;
    mm['J' - 'A'] = mm['X' - 'A'] = 8;
    mm['Q' - 'A'] = mm['Z' - 'A'] = 10;
    char c;
    int sum = 0;
    printf("Enter a word: ");
    while ((c = getchar()) != '\n')
    {
        c = toupper(c);
        if (c >= 'A' && c <= 'Z')
        {
            sum += mm[c - 'A'];
        }
    }
    printf("Scrabble value: %d\n", sum);
}
void func_p_7_6()
{
    printf("sizeof int: %lu\n", sizeof(int));
    printf("sizeof short: %lu\n", sizeof(short));
    printf("sizeof long: %lu\n", sizeof(long));
    printf("sizeof float: %lu\n", sizeof(float));
    printf("sizeof double: %lu\n", sizeof(double));
    printf("sizeof long double: %lu\n", sizeof(long double));
}
void func_p_7_7()
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    char c;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d%c%d/%d", &num1, &denom1, &c, &num2, &denom2);
    switch (c)
    {
    case '+':
        result_num = num1 * denom2 + num2 * denom1;
        result_denom = denom1 * denom2;
        break;
    case '-':
        result_num = num1 * denom2 - num2 * denom1;
        result_denom = denom1 * denom2;
        break;
    case '*':
        result_num = num1 * num2;
        result_denom = denom1 * denom2;
        break;
    case '/':
        result_num = num1 * denom2;
        result_denom = denom1 * num2;
        break;
    default:
        break;
    }

    printf("The sum is %d/%d\n", result_num, result_denom);
}
void func_p_7_8()
{
    int hour, minute;
    printf("Enter a 12-hour time(xx:xx): ");
    char c1, c2;
    scanf("%d :%d%c%c", &hour, &minute, &c1, &c2);

    int minutes = hour * 60 + minute;
    if (c1 == ' ')
    {
        if (c2 == 'p' || c2 == 'P')
        {
            minutes += 12 * 60;
        }
    }
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
void func_p_7_9()
{
    int hour, minute;
    printf("Enter a 12-hour time(xx:xx): ");
    scanf("%d:%d", &hour, &minute);
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c == 'p' || c == 'P')
        {
            hour += 12;
            break;
        }
    }

    printf("Equivalent 24-hour time: %.2d:%.2d\n", hour, minute);
}
void func_p_7_10()
{
    printf("Enter a sentence: ");
    char c;
    int num = 0;
    while ((c = getchar()) != '\n')
    {
        c = toupper(c);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            ++num;
        }
    }
    printf("Your sentence contains %d vowels.\n", num);
    // Enter a sentence: And that's the way it is .
    // Your sentence contains 6 vowels.
}
void func_p_7_11()
{
    printf("Enter a first and last name: ");
    char c;
    char c2;
    _Bool flag = 0;
    c = getchar();
    c2 = toupper(c);
    while (c != '\n')
    {

        if (flag)
        {
            putchar(c);
        }
        if (c == ' ')
        {
            flag = 1;
        }
        c = getchar();
    }
    printf(", %c.\n", c2);
    // Enter a first and last name: Lloyd Fosdick
    // Fosdick, L.
}
void func_p_7_12()
{
    printf("Enter an expression: ");
    double result = 0, rvalue = 0;
    char c;
    scanf("%lf", &result);
    while (1)
    {
        c = getchar();
        if (c == '\n')
        {
            break;
        }
        scanf("%lf", &rvalue);
        switch (c)
        {
        case '+':
            result += rvalue;
            break;
        case '-':
            result -= rvalue;
            break;
        case '*':
            result *= rvalue;
            break;
        case '/':
            result /= rvalue;
            break;
        }
    }
    printf("Value of expression: %.2lf\n", result);
}
void func_p_7_13()
{
    printf("Enter a sentence: ");
    char c;
    int num = 0, sum = 0;
    int isStart = 1; // 是否是首字母
    while ((c = getchar()) != '\n')
    {

        if (c == ' ')
        {
            isStart = 1;
        }
        else
        {
            if (isStart)
            {
                ++num;
                isStart = 0;
            }
            ++sum;
        }
    }
    printf("Average word length: %lf\n", sum * 1.0 / num);
    // Enter a sentence: It was deia va all over again.
    // Average word length: 3.428571
}
void func_p_7_14()
{
    printf("Enter a positive number: ");
    double num, result, divide, avg;
    scanf("%lf", &num);
    result = 1;
    while (1)
    {
        divide = num / result;
        avg = (result + divide) / 2;
        if (fabs(avg - result) < 0.00001 * result)
        {
            break;
        }
        result = avg;
    }

    printf("Square root: %lf\n", result);
}

void func_p_7_15()
{
    printf("Enter an positive integer: ");
    int num, result = 1, i = 2;
    scanf("%d", &num);
    for (; i <= num; i++)
    {
        result *= i;
    }
    printf("Factorial of %d: %d\n", num, result);
}