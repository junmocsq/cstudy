#include "exercise13-1.c"
#include "stack.c"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void func_p_13_1(void);
void func_p_13_2(void);
void func_p_13_3(void);
void func_p_13_4(void);
void func_p_13_5(void);
void func_p_13_6(void);
void func_p_13_7(void);
void func_p_13_8(void);
void func_p_13_9(void);
void func_p_13_10(void);
void func_p_13_11(void);
void func_p_13_12(void);
void func_p_13_13(void);
void func_p_13_14(void);
void func_p_13_15(void);
void func_p_13_16(void);
void func_p_13_17(void);
void func_p_13_18(void);
int main(void)
{
    func_13_1();
    func_13_2();
    // func_13_3();
    // func_13_4();
    func_13_5();
    func_13_6();
    func_13_7();
    func_13_8();
    func_13_9();
    func_13_10();
    func_13_11();
    func_13_12();
    func_13_13();
    func_13_14();
    func_13_15();
    func_13_16();
    func_13_17();
    func_13_18();

    // func_p_13_1();
    func_p_13_2();
    func_p_13_3();
    func_p_13_4();
    func_p_13_5();
    func_p_13_6();
    func_p_13_7();
    func_p_13_8();
    func_p_13_9();
    func_p_13_10();
    func_p_13_11();
    // func_p_13_12();
    func_p_13_13();
    func_p_13_14();
    func_p_13_15();
    func_p_13_16();
    func_p_13_17();
    func_p_13_18();
    return 0;
}

#define MAX_WORD 20
void func_p_13_1(void)
{
    char smallest_word[MAX_WORD + 1];
    char largest_word[MAX_WORD + 1];

    char temp[MAX_WORD + 1];
    printf("Enter word:");
    scanf("%s", temp);
    strcpy(smallest_word, temp);
    strcpy(largest_word, temp);
    while (true)
    {
        printf("Enter word:");
        scanf("%s", temp);
        if (strlen(temp) == 4)
        {
            break;
        }
        if (strcmp(temp, smallest_word) < 0)
            strcpy(smallest_word, temp);
        if (strcmp(temp, largest_word) > 0)
            strcpy(largest_word, temp);
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);
}
void func_p_13_2(void)
{
    // remind.c
}
void func_p_13_3(void) {}
void func_p_13_4(void)
{
}
void func_p_13_5(void)
{
}
void func_p_13_6(void)
{
}

void func_p_13_7(void)
{
}
int compute_scrabble_value(const char *word)
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
    for (; *word != '\0';)
    {
        c = toupper(*word++);
        if (c >= 'A' && c <= 'Z')
        {
            sum += mm[c - 'A'];
        }
    }
    return sum;
}
void func_p_13_8(void)
{
    printf("%d\n", compute_scrabble_value("junmocsq"));
}
int compute_vowel_count(const char *sentence)
{
    char c;
    int num = 0;
    while (*sentence != '\0')
    {
        c = toupper(*sentence++);
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        {
            ++num;
        }
    }
    return num;
}
void func_p_13_9(void)
{

    printf("Your sentence contains %d vowels.\n", compute_vowel_count("hello waold iosaka jsds"));
}

void reverse_name(char *name)
{
    char c;
    _Bool flag = 0;
    c = toupper(*name);
    char *p;
    int i = 0;
    for (p = name; *p; p++)
    {
        if (flag)
        {
            name[i++] = *p;
        }
        if (*p == ' ')
        {
            flag = 1;
        }
    }
    name[i++] = ',';
    name[i++] = ' ';
    name[i++] = c;
    name[i++] = '.';
    name[i] = '\0';
}
void func_p_13_10(void)
{
    char name[] = "Lloyd Fosdick";
    reverse_name(name);
    printf("Enter a first and last name: Lloyd Fosdick;out: %s\n", name);
    // Enter a first and last name: Lloyd Fosdick
    // Fosdick, L.
}

double compute_average_word_length(const char *senteence)
{
    char c;
    int num = 0, sum = 0;
    int isStart = 1; // 是否是首字母
    for (; *senteence; senteence++)
    {
        if (*senteence == ' ')
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
    return sum * 1.0 / num;

    // Enter a sentence: It was deia va all over again.
    // Average word length: 3.428571
}
void func_p_13_11(void)
{
    char *sentence = "It was deia va all over again.";
    printf("Average word length: %lf\n", compute_average_word_length(sentence));
}

void func_p_13_12(void)
{
    char result[30][21];
    printf("Enter a sentence: ");
    char ch;
    int i = 0;
    int row = -1;
    char break_char;
    // 读入需要处理字符串
    while ((ch = getchar()) != '\n')
    {
        if (ch == '?' || ch == '.' || ch == '!')
        {
            result[row][i] = '\0';
            break_char = ch;
            break;
        }
        if (ch == ' ')
        {
            if (i > 0 && row >= 0)
            {
                result[row][i] = '\0';
            }
            i = 0;
        }
        else
        {
            if (i == 0)
            {
                row++;
            }
            result[row][i++] = ch;
        }
    }
    printf("Reversal of sentence: ");
    for (int m = row; m >= 0; m--)
    {
        printf("%s ", result[m]);
    }
    putchar(break_char);
    puts("");

    while (getchar() != '\n')
        ;
    // Enter a sentence: remote: Resolving deltas: 100% (1/1), completed with 1 local object.
    // Reversal of sentence: object local 1 with completed (1/1), 100% deltas: Resolving remote:.
}

void encrypt(char *message, int shift)
{
    char ch;
    for (; *message;)
    {
        ch = *message;
        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' + shift) % 26 + 'A';
        }
        *message++ = ch;
    }
    // Enter message to be encrypted: dkhdg, pdnh pb gdb
    // Enter shift amount[1-25]: 23
    // Encrypted message: ahead, make my day
}
void func_p_13_13(void)
{
    char msg[] = "dkhdg, pdnh pb gdb";
    encrypt(msg, 23);
    printf("dkhdg, pdnh pb gdb Encrypted message: %s\n", msg);
}
bool are_anagrams(const char *word1, const char *word2)
{
    char v1[26] = {0};
    char v2[26] = {0};
    char ch;
    for (; *word1 && *word2;)
    {
        ch = *word1++;
        if (isalpha(ch))
        {
            v1[toupper(ch) - 'A']++;
        }
        ch = *word2++;
        if (isalpha(ch))
        {
            v2[toupper(ch) - 'A']++;
        }
    }

    if (*word1 != '\0' || *word2 != '\0') // 两字符串长度不等
    {
        return false;
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
    return isAragrams;
}
void func_p_13_14(void)
{
    bool isAragrams = are_anagrams("smartest", "mattress");
    if (isAragrams)
    {
        printf("The words are aragrams.\n");
    }
    else
    {
        printf("The words are not aragrams.\n");
    }
}

int evalute_RPN_expression(const char *expression)
{
    int result = 0;
    char ch;
    int a, b;
    extern int top;
    make_empty();
    while ((ch = *expression++))
    {
        if (ch == 'q')
            break;
        switch (ch)
        {
        case '+':
            if (top < 2)
            {
                printf("Not enough operands! %d\n", top);
                exit(1);
            }
            a = pop();
            b = pop();
            push(a + b);
            break;
        case '-':
            if (top < 2)
            {
                printf("Not enough operands!\n");
                exit(1);
            }
            a = pop();
            b = pop();
            push(b - a);
            break;
        case '*':
            if (top < 2)
            {
                printf("Not enough operands!\n");
                exit(1);
            }
            a = pop();
            b = pop();
            push(b * a);
            break;
        case '/':
            if (top < 2)
            {
                printf("Not enough operands!\n");
                exit(1);
            }
            a = pop();
            b = pop();
            push(b / a);
            break;
        case '=':
            if (top < 1)
            {
                printf("Not enough operands!\n");
                exit(1);
            }
            result = pop();
            break;
        default:
            if (ch >= '0' && ch <= '9')
            {
                push(ch - '0');
            }
            break;
        }
    }
    return result;
}
void func_p_13_15(void)
{
    char *expression = "1 2 3 * + =";
    printf("%s %d\n", expression, evalute_RPN_expression(expression));
}
void reverse(char *message)
{
    char *end = message + strlen(message) - 1;
    char temp;
    for (; message < end; message++, end--)
    {
        temp = *message;
        *message = *end;
        *end = temp;
    }
}
void func_p_13_16(void)
{
    char msg[] = "junmocsq";
    reverse(msg);
    printf("%s\n", msg);
}
// 是否回文
bool is_palindrome(const char *message)
{
    const char *end = message + strlen(message) - 1;
    for (; message < end;)
    {
        if (*message++ != *end--)
        {
            return false;
        }
    }
    return true;
}
void func_p_13_17(void)
{
    char msg[] = "junmocsq";
    is_palindrome(msg);
    printf("%s is palindrome or not: %d\n", msg, is_palindrome(msg));

    char msg2[] = "junmocsqscomnuj";
    is_palindrome(msg2);
    printf("%s is palindrome or not: %d\n", msg2, is_palindrome(msg2));
}
void func_p_13_18(void)
{
    int m, d, y;
    printf("Enter date mm/dd/yy: ");
    scanf("%d /%d /%d", &m, &d, &y);

    char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Your Entered the date %s %.2d, %.4d\n", month[m - 1], d, y);
    return;
}