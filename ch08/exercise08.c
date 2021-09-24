#include <stdio.h>
#include <stdbool.h>

void func_8_5();
void func_8_6();
void func_8_11();

void func_p_8_1();
void func_p_8_2();
void func_p_8_3();
void func_p_8_4();
void func_p_8_5();
void func_p_8_6();
void func_p_8_7();
void func_p_8_8();
void func_p_8_9();
void func_p_8_10();
void func_p_8_11();
void func_p_8_12();
void func_p_8_13();
void func_p_8_14();
void func_p_8_15();
void func_p_8_16();
void func_p_8_17();

// cc exercise08.c && ./a.out
int main()
{
    // func_8_5();
    func_8_6();
    func_8_11();

    // func_p_8_1();
    // func_p_8_2();
    // func_p_8_3();
    func_p_8_4();
    func_p_8_5();
    func_p_8_6();
    func_p_8_7();
    func_p_8_8();
    func_p_8_9();
    func_p_8_10();
    func_p_8_11();
    func_p_8_12();
    func_p_8_13();
    func_p_8_14();
    func_p_8_15();
    func_p_8_16();
    func_p_8_17();
    return 0;
}

void func_8_5()
{
    int fib_number[40];
    fib_number[0] = fib_number[1] = 1;
    for (int i = 2; i < 40; i++)
    {
        fib_number[i] = fib_number[i - 1] + fib_number[i - 2];
    }
    for (int i = 0; i < 40; i++)
    {
        printf("%2d %-10d\n", i + 1, fib_number[i]);
    }
}

void func_8_6()
{
    const int segments[10][7] = {
        {1, 1, 1, 1, 1, 1, 0}, // 0
        {0, 1, 1, 0, 0, 0, 0}, // 1
        {1, 1, 0, 1, 1, 0, 1}, // 2
        {1, 1, 1, 1, 0, 0, 1}, // 3
        {0, 1, 1, 0, 0, 1, 1}, // 4
        {1, 0, 1, 1, 0, 1, 1}, // 5
        {1, 0, 1, 1, 1, 1, 1}, // 6
        {1, 1, 1, 0, 0, 0, 0}, // 7
        {1, 1, 1, 1, 1, 1, 1}, // 8
        {1, 1, 1, 1, 0, 1, 1}, // 9
    };
    const char print_char[7] = {'_', '|', '|', '-', '|', '|', '-'};
    for (int i = 0; i < 10; i++)
    {
        if (segments[i][0])
            printf(" %c ", print_char[0]);
        printf("\t");
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        if (segments[i][5])
            printf("%c", print_char[5]);
        else
            printf(" ");
        printf(" ");
        if (segments[i][1])
            printf("%c", print_char[1]);
        else
            printf(" ");
        printf("\t");
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        if (segments[i][6])
            printf(" %c ", print_char[6]);
        printf("\t");
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        if (segments[i][4])
            printf("%c", print_char[4]);
        else
            printf(" ");
        printf(" ");
        if (segments[i][2])
            printf("%c", print_char[2]);
        else
            printf(" ");
        printf("\t");
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        if (segments[i][3])
            printf(" %c ", print_char[3]);
        printf("\t");
    }
    printf("\n");
}

void func_8_11()
{
    char checker_board[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
                checker_board[i][j] = 'B';
            else
                checker_board[i][j] = 'R';
            printf("%2c", checker_board[i][j]);
        }
        printf("\n");
    }
}

void func_p_8_1()
{
    int digit_seen[10] = {0};
    int digit;
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    bool isRepeated = false;
    while (n > 0)
    {
        digit = n % 10;
        digit_seen[digit]++;
        if (digit_seen[digit] > 1)
        {
            isRepeated = true;
        }
        n /= 10;
    }

    if (isRepeated)
    {
        printf("Repeated digit(s): ");
        for (int i = 0; i < 10; i++)
        {
            if (digit_seen[i] > 1)
                printf("%2d", i);
        }
        printf("\n");
    }
    else
    {
        printf("No repeated digit.\n");
    }
}
void func_p_8_2()
{
    int digit_seen[10] = {0};
    int digit;
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0)
    {
        digit = n % 10;
        digit_seen[digit]++;
        n /= 10;
    }
    printf("Digit:        ");
    for (int i = 0; i < 10; i++)
        printf("%2d", i);
    printf("\nOccurrences:  ");
    for (int i = 0; i < 10; i++)
        printf("%2d", digit_seen[i]);
    printf("\n");
}
void func_p_8_3()
{

    int digit;
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0)
    {
        int digit_seen[10] = {0};
        bool isRepeated = false;
        while (n > 0)
        {
            digit = n % 10;
            digit_seen[digit]++;
            if (digit_seen[digit] > 1)
            {
                isRepeated = true;
            }
            n /= 10;
        }

        if (isRepeated)
        {
            printf("Repeated digit(s): ");
            for (int i = 0; i < 10; i++)
            {
                if (digit_seen[i] > 1)
                    printf("%2d", i);
            }
            printf("\n");
        }
        else
        {
            printf("No repeated digit.\n");
        }
        printf("Enter a number: ");
        scanf("%ld", &n);
    }
}
void func_p_8_4()
{
    int a[10], i;
    printf("Enter 10 number: ");
    int length = (int)(sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < length; i++)
        scanf("%d", &a[i]);

    printf("In reverse order: ");
    for (i = length - 1; i >= 0; i--)
    {
        printf(" %d", a[i]);
    }
    printf("\n");
    // Enter 10 number: 24 33 12 44 55 77 88 89 32 11
    // In reverse order:  11 32 89 88 77 55 44 12 33 24
}
void func_p_8_5() {}
void func_p_8_6() {}
void func_p_8_7() {}
void func_p_8_8() {}
void func_p_8_9() {}
void func_p_8_10() {}
void func_p_8_11() {}
void func_p_8_12() {}
void func_p_8_13() {}
void func_p_8_14() {}
void func_p_8_15() {}
void func_p_8_16() {}
void func_p_8_17() {}