#include <stdio.h>
#include "stack.c"
#include <stdbool.h>

void func_p_10_1(void);
void func_p_10_5(void);
void func_p_10_7(void);

// cc exercise10.c&& ./a.out
int main()
{
    // func_p_10_1();
    // func_p_10_5();
    func_p_10_7();
    return 0;
}

void func_p_10_1(void)
{
    printf("Enter parenteses and/or braces: ");
    char ch;
    bool flag = true;
    while ((ch = getchar()) != '\n')
    {
        if (ch == '(' || ch == '{')
        {
            push(ch);
        }
        if (ch == ')' && pop() != '(')
        {
            flag = false;
            break;
        }
        if (ch == '}' && pop() != '{')
        {
            flag = false;
            break;
        }
    }
    if (!flag || !is_empty())
    {
        printf("Parenteses/braces aren't nested properly!\n");
    }
    else
    {
        printf("Parenteses/braces are nested properly!\n");
    }
}

void func_p_10_5(void)
{

    char ch;
    int a, b;
    extern int top;
    for (;;)
    {
    L2:
        make_empty();
        printf("Enter an RPN expression:");
        while (true)
        {

            scanf(" %c", &ch);
            switch (ch)
            {
            case '+':
                if (top < 2)
                {
                    printf("Not enough operands! %d\n", top);
                    goto L2;
                }
                a = pop();
                b = pop();
                push(a + b);
                break;
            case '-':
                if (top < 2)
                {
                    printf("Not enough operands!\n");
                    goto L2;
                }
                a = pop();
                b = pop();
                push(b - a);
                break;
            case '*':
                if (top < 2)
                {
                    printf("Not enough operands!\n");
                    goto L2;
                }
                a = pop();
                b = pop();
                push(b * a);
                break;
            case '/':
                if (top < 2)
                {
                    printf("Not enough operands!\n");
                    goto L2;
                }
                a = pop();
                b = pop();
                push(b / a);
                break;
            case '=':
                if (top < 1)
                {
                    printf("Not enough operands!\n");
                    goto L2;
                }
                printf("Value of expression: %d\n", pop());
                goto L2;
                break;
            default:
                if (ch >= '0' && ch <= '9')
                {
                    push(ch - '0');
                }
                if (ch == 'q')
                {
                    goto L1;
                }
                break;
            }
        }
    }
L1:;
}

#define MAX_DIGITS 10
char digits[3][MAX_DIGITS * 4];
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
void clear_digits_array(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < MAX_DIGITS * 4; j++)
            digits[i][j] = ' ';
    }
}

void process_digit(int digit, int position)
{

    const char print_char[7] = {'_', '|', '|', '_', '|', '|', '_'};
    int i = position * 4;
    if (segments[digit][0])
    {
        digits[0][i + 1] = print_char[0];
    }
    if (segments[digit][5])
    {
        digits[1][i] = print_char[5];
    }
    if (segments[digit][6])
    {
        digits[1][i + 1] = print_char[6];
    }
    if (segments[digit][1])
    {
        digits[1][i + 2] = print_char[1];
    }
    if (segments[digit][4])
    {
        digits[2][i] = print_char[4];
    }
    if (segments[digit][3])
    {
        digits[2][i + 1] = print_char[3];
    }
    if (segments[digit][2])
    {
        digits[2][i + 2] = print_char[2];
    }
}
void print_digits_array(void)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 40; j++)
        {
            printf("%c", digits[i][j]);
        }
        printf("\n");
    }
}
void func_p_10_7()
{
    char arr[MAX_DIGITS];
    char ch;
    int i = 0;
    printf("Enter a number: ");
    while ((ch = getchar()) != '\n' && i < 10)
    {
        if (ch >= '0' && ch <= '9')
            arr[i++] = ch - '0';
    }

    clear_digits_array();
    for (int j = 0; j < i; j++)
    {
        process_digit(arr[j], j);
    }
    print_digits_array();
}