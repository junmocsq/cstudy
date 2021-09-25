#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int check(int x, int y, int n);
int gcd(int x, int y);
int day_of_year(int month, int day, int year);
int num_digits(int n);
int digit(int n, int k);
int f(int a, int b) { return a + b; }
// f1(double);
void func_9_10(int arr[], int n, int *max, int *avg, int *num);
float computer_GPA(char grades[], int n);
double inner_product(double a[], double b[], int n);
int evaluate_position(char board[][8]);

// p9_1
void selection_sort(int arr[], int n);
double func_p_9_2(double income);
void func_p_9_3();
void func_p_9_4();
void func_p_9_5();
double func_p_9_6(double x);
double func_p_9_7(double x, int num);
void func_p_9_8();

int main()
{
    printf("2. %d\n", check(3, 4, 5));
    printf("3. %d\n", gcd(12, 28));
    printf("4. %d\n", day_of_year(3, 4, 2000));
    printf("5. %d\n", num_digits(123454320));
    printf("6. %d %d %d %d\n", digit(829, 1), digit(829, 2), digit(829, 3), digit(829, 4));

    // int i;
    // double x;
    // i = f(83, 12);
    // x = f(83, 12);
    // i = f(83.1, 12.1);
    // x = f(83.1, 12.1);
    int max, avg, num;
    func_9_10((int[]){3, 0, 2, 1, 3, -99, -7, 1999, 12, 10}, 10, &max, &avg, &num);
    printf("10. max:%d avg:%d positive:%d\n", max, avg, num);
    printf("11. GPA:%.2f \n", computer_GPA((char[]){'A', 'A', 'B', 'C', 'F', 'C'}, 6));
    // int arr[10];
    // selection_sort(arr, 10);

    printf("p7 %.2lf^%d=%.2lf\n", 2.0, 10, func_p_9_7(2, 10));
    func_p_9_8();
}

int check(int x, int y, int n)
{
    if (x >= 0 && y >= 0 && x < n && y < n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int gcd(int m, int n)
{
    if (n == 0)
    {
        return m;
    }
    return gcd(n, m % n);
}

int day_of_year(int month, int day, int year)
{
    int arr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        arr[1] = 29; // 闰年
    }
    int result = day;
    for (int i = 0; i < month - 1; i++)
    {
        result += arr[i];
    }
    return result;
}

int num_digits(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int arr[10] = {0};
    while (n > 0)
    {
        arr[n % 10]++;
        n /= 10;
    }
    int result = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > 0)
            ++result;
    }
    return result;
}
int digit(int n, int k)
{
    for (int i = 0; i < k - 1; i++)
    {
        n /= 10;
    }
    return n % 10;
}
void func_9_10(int arr[], int n, int *max, int *avg, int *num)
{
    *max = arr[0];
    *num = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        *max = arr[i] > *max ? arr[i] : *max;
        sum += arr[i];
        if (arr[i] > 0)
            (*num)++;
    }
    *avg = sum / n;
    return;
}

float computer_GPA(char grades[], int n)
{
    float sum = 0.0f;
    for (int i = 0; i < n; i++)
    {
        switch (grades[i])
        {
        case 'A':
        case 'a':
            sum += 4;
            break;
        case 'B':
        case 'b':
            sum += 3;
            break;
        case 'C':
        case 'c':
            sum += 2;
            break;
        case 'D':
        case 'd':
            sum += 1;
            break;

        default:
            break;
        }
    }
    return sum / n;
}

double inner_product(double a[], double b[], int n)
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += a[i] * b[i];
    }
    return result;
}

int evaluate_position(char board[][8])
{
    int black = 0, white = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; i++)
        {
            switch (board[i][j])
            {
            case 'Q':
                white += 8;
                break;
            case 'q':
                black += 8;
                break;
            case 'R':
                white += 5;
                break;
            case 'r':
                black += 5;
                break;
            case 'B':
            case 'N':
                white += 3;
                break;
            case 'b':
            case 'n':
                black += 3;
                break;
            case 'P':
                white += 1;
                break;
            case 'p':
                black += 1;
                break;
            }
        }
    }
    return white - black;
}

void selection_sort(int arr[], int n)
{
    printf("Enter %d numbers: ", n);
    int total = n;
    while (total-- > 0)
    {
        scanf("%d", &arr[total]);
    }
    for (int i = n - 1; i > 0; i--)
    {
        int maxIndex = i;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[maxIndex])
            {
                maxIndex = j;
            }
        }
        if (maxIndex != i)
        {
            int temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

double func_p_9_2(double income)
{
    double result;
    if (income < 750.00f)
    {
        result = income * 0.01f;
    }
    else if (income < 2250.00f)
    {
        result = 7.5f + (income - 750.00f) * 0.02f;
    }
    else if (income < 3750.00f)
    {
        result = 37.5f + (income - 2250.00f) * 0.02f;
    }
    else if (income < 5250.00f)
    {
        result = 82.5f + (income - 3750.00f) * 0.02f;
    }
    else if (income < 7000.00f)
    {
        result = 142.5f + (income - 5250.00f) * 0.02f;
    }
    else
    {
        result = 230.00f + (income - 7000.00f) * 0.02f;
    }
    return result;
}

void generate_random_walk(char walk[10][10])
{
    char ch = 'A';
    srand((unsigned)time(NULL));
    int direction;
    int row = 0, column = 0;
    walk[row][column] = 'A';
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
            if (row - 1 >= 0 && walk[row - 1][column] == 0)
            {
                --row;
                isValid = true;
            }
            break;
        case 1:
            if (column + 1 < 10 && walk[row][column + 1] == 0)
            {
                ++column;
                isValid = true;
            }
            break;
        case 2:
            if (row + 1 < 10 && walk[row + 1][column] == 0)
            {
                ++row;
                isValid = true;
            }
            break;
        case 3:
            if (column - 1 >= 0 && walk[row][column - 1] == 0)
            {
                --column;
                isValid = true;
            }
            break;
        }
        if (isValid)
        {
            ++ch;
            walk[row][column] = ch;
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
            if (!walk[i][j])
            {
                walk[i][j] = '.';
            }
        }
    }
}
void print_array(char walk[10][10])
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", walk[i][j]);
        }
        printf("\n");
    }
}
void func_p_9_3()
{
    char walk[10][10] = {0};
    generate_random_walk(walk);
    print_array(walk);
}

void read_word(int v1[26])
{
    char ch;
    while ((ch = getchar()) != '\n')
    {
        if (isalpha(ch))
        {
            v1[toupper(ch) - 'A']++;
        }
    }
}
bool equal_array(int v1[26], int v2[26])
{
    bool isAragrams = true;
    for (int i = 0; i < 26; i++)
    {
        if (v1[i] != v2[i])
        {
            isAragrams = false;
            break;
        }
    }
    return isAragrams;
}
void func_p_9_4()
{
    char v1[26] = {0};
    char v2[26] = {0};
    char ch;
    printf("Enter first word: ");
    read_word(v1);

    printf("Enter second word: ");
    read_word(v2);
    bool isAragrams = equal_array(v1, v2);
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

void create_magic_square(int n, char magic_square[n][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            magic_square[i][j] = 0;
        }
    }
    int row = 0, column = n / 2;
    int val = 1;
    int temp_row, temp_column;
    for (;;)
    {
        magic_square[row][column] = val;
        if (val == n * n)
        {
            break;
        }
        ++val;
        temp_row = row;
        temp_column = column;
        --row;
        if (row == -1)
            row = n - 1;
        ++column;
        if (column == n)
            column = 0;
        if (magic_square[row][column] != 0)
        {
            row = temp_row;
            column = temp_column;
            ++row;
            if (row == n)
                row = 0;
        }
    }
}
void print_magic_square(int n, char magic_square[n][n])
{

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%5d", magic_square[i][j]);
        }
        printf("\n");
    }
    while (getchar() != '\n')
        ;
}

void func_p_9_5()
{
    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99\n");
    printf("Enter size of magic square:");
    int n;
    scanf("%d", &n);
    char magic_square[n][n];
    create_magic_square(n, magic_square);
    print_magic_square(n, magic_square);
}

double pow_p_9_6(double x, int num)
{
    double result = 1;
    while (num-- > 0)
    {
        result *= x;
    }
    return result;
}
double func_p_9_6(double x)
{
    return 3 * pow_p_9_6(x, 5) + 2 * pow_p_9_6(x, 4) - 5 * pow_p_9_6(x, 3) - pow_p_9_6(x, 2) + 7 * x - 6;
}

double func_p_9_7(double x, int num)
{
    if (num == 1)
        return x;
    if (num % 2 == 1)
    {
        return func_p_9_7(x, num - 1) * x;
    }
    else
    {

        return func_p_9_7(x, num / 2) * func_p_9_7(x, num / 2);
    }
}

int roll_dice(void)
{

    return rand() % 6 + 1 + rand() % 6 + 1;
}
bool play_game(void)
{
    int times = 1;
    char firstWin[2] = {7, 11};
    char firstLose[3] = {2, 3, 12};

    char otherLose[1] = {7};
    char otherWin[] = {4, 5, 6, 8, 9, 10};
    int point;
    for (;;)
    {
        int res = roll_dice();
        printf("Your rolled:%d \n", res);
        if (times++ == 1)
        {
            printf("Your point is %d \n", res);
            for (int i = 0; i < (int)(sizeof(firstWin) / sizeof(firstWin[0])); i++)
            {
                if (firstWin[i] == res)
                {

                    printf("Your win!\n");
                    return true;
                }
            }
            for (int i = 0; i < (int)(sizeof(firstLose) / sizeof(firstLose[0])); i++)
            {
                if (firstLose[i] == res)
                {
                    printf("Your lose!\n");
                    return false;
                }
            }
        }
        else
        {
            if (point == res)
            {
                printf("Your win!\n");
                return true;
            }
            if (7 == res)
            {
                printf("Your lose!\n");
                return false;
            }
        }
    }
}
void func_p_9_8()
{
    srand((unsigned)time(NULL));
    int win = 0, lose = 0;
    char ch;
    while (true)
    {
        if (play_game())
            ++win;
        else
            ++lose;
        printf("Play again? ");
        if (getchar() == 'n')
        {
            break;
        }
    }
    printf("win times:%d lose times:%d\n", win, lose);
}