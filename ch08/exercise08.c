#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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

    func_p_8_1();
    func_p_8_2();
    func_p_8_3();
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
    while (getchar() != '\n')
        ;
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
    while (getchar() != '\n')
        ;
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
    while (getchar() != '\n')
        ;
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
    while (getchar() != '\n')
        ;
    // Enter 10 number: 24 33 12 44 55 77 88 89 32 11
    // In reverse order:  11 32 89 88 77 55 44 12 33 24
}
void func_p_8_5()
{
    int rate, year;
    double rates[5];
    printf("Enter interest rate: ");
    scanf("%d", &rate);
    printf("Enter number of years: ");
    scanf("%d", &year);
    int balance = 100;
    printf("%10s", "years");
    for (int i = 0; i < (int)(sizeof(rates) / sizeof(rates[0])); i++)
    {
        rates[i] = balance + (rate + i);
        printf("%10d%%", rate + i);
    }
    printf("\n");
    for (int i = 1; i <= year; i++)
    {
        printf("%10d", i);
        for (int j = 0; j < (int)(sizeof(rates) / sizeof(rates[0])); j++)
        {
            printf("%10.2f%%", rates[j]);
            for (int k = 0; k < 12; k++)
            {
                rates[j] *= (balance + (rate + i) / 12.0) / 100.0;
            }
        }
        printf("\n");
    }
    while (getchar() != '\n')
        ;
}
void func_p_8_6()
{
    printf("Enter message: ");
    char val[1024];
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n')
    {
        val[i++] = toupper(ch);
    }
    printf("In B1FF-speak: ");
    for (int j = 0; j < i; j++)
    {
        switch (val[j])
        {
        case 'A':
            putchar('4');
            break;
        case 'B':
            putchar('8');
            break;
        case 'E':
            putchar('3');
            break;
        case 'I':
            putchar('1');
            break;
        case 'O':
            putchar('0');
            break;
        case 'S':
            putchar('5');
            break;
        default:
            putchar(val[j]);
            break;
        }
    }
    for (int j = 0; j < 10; j++)
        printf("!");
    printf("\n");
    while (getchar() != '\n')
        ;
    // Enter message: Hey dude, C is rilly cool
    // In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
}
void func_p_8_7()
{
    int vals[5][5];
    int rows[5] = {0};
    int columns[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        printf("Enter row %d: ", i + 1);
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &vals[i][j]);
            rows[i] += vals[i][j];
            columns[j] += vals[i][j];
        }
    }
    printf("Row totals: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", rows[i]);
    }
    printf("\nColumn totals: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", columns[i]);
    }
    printf("\n");
    while (getchar() != '\n')
        ;
    /*
Enter row 1: 8 3 9 0 10
Enter row 2: 3 5 17 1 1
Enter row 3: 2 8 6 23 1
Enter row 4: 15 7 3 2 9
Enter row 5: 6 14 2 6 0
Row totals: 30 27 40 36 28 
Column totals: 34 37 37 32 21 
    */
}
void func_p_8_8()
{
    int vals[5][5];
    int stats[5][5] = {0}; // 0 总分 1 平均分 2 科目总分 3 科目最高分 4 科目最低分
    for (int i = 0; i < 5; i++)
    {
        printf("Enter student %d 5 scores： ", i + 1);
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &vals[i][j]);
            stats[0][i] += vals[i][j];
            stats[2][j] += vals[i][j];
            if (i == 0)
            {
                stats[3][j] = vals[i][j];
                stats[4][j] = vals[i][j];
            }
            else
            {
                if (vals[i][j] > stats[3][j])
                    stats[3][j] = vals[i][j];
                if (vals[i][j] < stats[4][j])
                    stats[4][j] = vals[i][j];
            }
        }
        stats[1][i] = stats[0][i] / 5;
    }
    printf("student total scores: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", stats[0][i]);
    }
    printf("\nstudent average scores: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", stats[1][i]);
    }
    printf("\n科目总分 : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", stats[2][i]);
    }
    printf("\n科目最高分: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", stats[3][i]);
    }
    printf("\n科目最低分: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", stats[4][i]);
    }
    printf("\n");
    while (getchar() != '\n')
        ;
}
void func_p_8_9()
{
    char vals[10][10] = {0};
    char ch = 'A';
    srand((unsigned)time(NULL));
    int direction;
    int row = 0, column = 0;
    vals[row][column] = 'A';
    int visited[4] = {0};
    while (1)
    {

        direction = rand() % 4;
        // printf("%d %d %d %c\n", row, column, direction, ch);
        if (visited[direction])
        {
            srand((unsigned)time(NULL));
            direction = -1;
            for (int i = 0; i < 4; i++)
            {
                if (visited[i] == 0)
                {
                    direction = i;
                    break;
                }
            }
            if (direction == -1)
            {
                printf("path is blocked\n");
                break;
            }
        }
        visited[direction] = 1;
        bool isValid = false;
        switch (direction)
        {
        case 0:
            if (row - 1 >= 0 && vals[row - 1][column] == 0)
            {
                --row;
                isValid = true;
            }
            break;
        case 1:
            if (column + 1 < 10 && vals[row][column + 1] == 0)
            {
                ++column;
                isValid = true;
            }
            break;
        case 2:
            if (row + 1 < 10 && vals[row + 1][column] == 0)
            {
                ++row;
                isValid = true;
            }
            break;
        case 3:
            if (column - 1 >= 0 && vals[row][column - 1] == 0)
            {
                --column;
                isValid = true;
            }
            break;
        }
        if (isValid)
        {
            ++ch;
            vals[row][column] = ch;
            if (ch == 'Z')
                break;
            for (int i = 0; i < 4; i++)
            {
                visited[i] = 0;
            }
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (vals[i][j])
            {
                printf("%c ", vals[i][j]);
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
    while (getchar() != '\n')
        ;
}
void func_p_8_10()
{
    int start[] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};
    int end[] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58};
    int hour, minute;
    printf("Enter a 24-hour time(xx:xx): ");
    scanf("%d :%d", &hour, &minute);
    int minutes = hour * 60 + minute;
    printf("Closest departure time is ");
    int s = start[0], e = end[0];
    for (int i = 0; i < (int)(sizeof(start) / sizeof(start[0])); i++)
    {
        if (minutes <= start[i])
        {
            s = start[i];
            e = end[i];
            break;
        }
    }
    if (s < 12 * 60)
        printf("%.2d:%.2d a.m., arriving at ", s / 60, s % 60);
    else
        printf("%.2d:%.2d p.m., arriving at ", s / 60 - 12, s % 60);
    if (e < 12 * 60)
        printf("%.2d:%.2d a.m. \n", e / 60, e % 60);
    else
        printf("%.2d:%.2d p.m. \n", e / 60 - 12, e % 60);
    while (getchar() != '\n')
        ;
}
void func_p_8_11()
{
    printf("Enter phone number: ");
    char vals[15];
    int i = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        c = toupper(c);
        vals[i++] = c;
    }
    for (int j = 0; j < i; j++)
    {
        c = vals[j];
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
    while (getchar() != '\n')
        ;
    // Enter phone number: 1-800-COL_LECT
    // 1-800-265_5328
}
void func_p_8_12()
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
    while (getchar() != '\n')
        ;
    // Enter a word: pitfall
    // Scrabble value: 12
}
void func_p_8_13()
{
    printf("Enter a first and last name: ");
    char vals[20];
    int i = 0;
    char c;
    _Bool flag = 0;
    c = getchar();
    char c2 = toupper(c);
    while (c != '\n')
    {
        if (flag)
        {
            vals[i++] = c;
        }
        if (c == ' ')
        {
            flag = 1;
        }
        c = getchar();
    }
    vals[i] = '\0';
    printf("%s, %c.\n", vals, c2);
    while (getchar() != '\n')
        ;
    // Enter a first and last name: Lloyd Fosdick
    // Fosdick, L.
}
void func_p_8_14()
{
    char vals[1024];
    char temp[1024];
    printf("Enter a sentence: ");
    char ch;
    int i = 0;
    // 读入需要处理字符串
    while ((ch = getchar()) != '\n')
    {
        vals[i++] = ch;
        if (ch == '?' || ch == '.' || ch == '!')
        {
            break;
        }
    }
    printf("Reversal of sentence: ");

    // 获取结尾字符串
    --i;
    char endC = 0;
    if (vals[i] == '?' || vals[i] == '.' || vals[i] == '!')
    {
        endC = vals[i];
        --i;
    }

    // ti temp的下标，e为vals当前处理单词的后下标
    int ti = 0, e;
    e = i;
    while (1)
    {
        if (i == -1)
        {
            for (int j = i + 1; j <= e; j++)
            {
                temp[ti++] = vals[j];
            }
            break;
        }
        else if (vals[i] == ' ')
        {

            for (int j = i + 1; j <= e; j++)
            {
                temp[ti++] = vals[j];
            }
            temp[ti++] = ' ';
            e = i - 1;
        }
        --i;
    }
    if (endC)
        temp[ti++] = endC;
    temp[ti] = '\0';
    printf("%s\n", temp);
    while (getchar() != '\n')
        ;
    // Enter a sentence: remote: Resolving deltas: 100% (1/1), completed with 1 local object.
    // Reversal of sentence: object local 1 with completed (1/1), 100% deltas: Resolving remote:.
}
void func_p_8_15()
{
    int num;
    char ch;
    char vals[1024];
    int i = 0;
    printf("Enter message to be encrypted: ");
    while ((ch = getchar()) != '\n')
    {
        vals[i++] = ch;
    }

    printf("Enter shift amount[1-25]: ");
    scanf("%d", &num);
    printf("Encrypted message: ");
    for (int j = 0; j < i; j++)
    {
        ch = vals[j];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' + num) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' + num) % 26 + 'A';
        }
        putchar(ch);
    }
    putchar('\n');
    while (getchar() != '\n')
        ;
    // Enter message to be encrypted: dkhdg, pdnh pb gdb
    // Enter shift amount[1-25]: 23
    // Encrypted message: ahead, make my day
}
void func_p_8_16()
{
    char v1[26] = {0};
    char v2[26] = {0};
    char ch;
    printf("Enter first word: ");
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
        {
            v1[toupper(ch) - 'A']++;
        }
    }

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
        {
            v2[toupper(ch) - 'A']++;
        }
    }
    bool isAragrams = true;
    for (int i = 0; i < 26; i++)
    {
        if (v1[i] != v2[i])
        {
            isAragrams = false;
            break;
        }
    }
    if (isAragrams)
    {
        printf("The words are aragrams.\n");
    }
    else
    {
        printf("The words are not aragrams.\n");
    }
    while (getchar() != '\n')
        ;
    // Enter first word: smartest
    // Enter second word: mattress
    // The words are aragrams.
}
void func_p_8_17()
{
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99\n");
    printf("Enter size of magic square:");
    int num;
    scanf("%d", &num);
    int mm[99][99] = {0};
    int row = 0, column = num / 2;
    int val = 1;
    int temp_row, temp_column;
    for (;;)
    {
        mm[row][column] = val;
        if (val == num * num)
        {
            break;
        }
        ++val;
        temp_row = row;
        temp_column = column;
        --row;
        if (row == -1)
            row = num - 1;
        ++column;
        if (column == num)
            column = 0;
        if (mm[row][column] != 0)
        {
            row = temp_row;
            column = temp_column;
            ++row;
            if (row == num)
                row = 0;
        }
    }

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            printf("%5d", mm[i][j]);
        }
        printf("\n");
    }
    while (getchar() != '\n')
        ;
    /*
    This program creates a magic square of a specified size.
    The size must be an odd number between 1 and 99
    Enter size of magic square:11
    68   81   94  107  120    1   14   27   40   53   66
    80   93  106  119   11   13   26   39   52   65   67
    92  105  118   10   12   25   38   51   64   77   79
    104  117    9   22   24   37   50   63   76   78   91
    116    8   21   23   36   49   62   75   88   90  103
        7   20   33   35   48   61   74   87   89  102  115
    19   32   34   47   60   73   86   99  101  114    6
    31   44   46   59   72   85   98  100  113    5   18
    43   45   58   71   84   97  110  112    4   17   30
    55   57   70   83   96  109  111    3   16   29   42
    56   69   82   95  108  121    2   15   28   41   54
    */
}