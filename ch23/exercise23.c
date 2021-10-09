#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void func_23_2();
void func_23_3();
void func_23_4();
void func_23_5();
void func_23_8();
void func_23_11();
void func_23_12();
void func_23_13();
void func_p_23_2();
void func_p_23_3();
void func_p_23_4();
void func_p_23_5();
void func_p_23_6();
void func_p_23_7();

int main()
{
    func_23_2();
    func_23_3();
    func_23_4();
    func_23_5();
    func_23_8();
    func_23_11();
    func_23_12();
    func_23_13();

    func_p_23_2();
    func_p_23_3();
    func_p_23_4();
    func_p_23_5();
    func_p_23_6();
    func_p_23_7();
    return 0;
}

double evaluate_polynomial(double a[], int n, double x)
{
    double result = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        result = fma(result, x, a[i]);
    }
    return result;
}
void func_23_2()
{
    double a[] = {1, 1, 1, 1, 1};
    printf("%.2lf\n", evaluate_polynomial(a, 5, 1));
    printf("%.2lf\n", evaluate_polynomial(a, 5, 2));
}
void func_23_3() {}
bool check_identifier(char *s)
{
    int length = (int)strlen(s);
    if (length == 0)
        return false;
    if (!isalpha(s[0]) && s[0] != '_')
        return false;
    for (int i = 1; i < length; i++)
    {
        if (!isalnum(s[i]) && s[i] != '_')
        {
            return false;
        }
    }
    return true;
}
void func_23_4()
{
    printf("%d %d %d\n", check_identifier("_abc"), check_identifier("a1sd"), check_identifier("_abc1,"));
}

long int xxdigit(char *s)
{
    int length = strlen(s);
    long result = 0;
    int ch;
    for (int i = 0; i < length; i++)
    {
        if (!isxdigit(s[i]))
        {
            return -1;
        }
        ch = toupper(s[i]);
        if (ch <= '9')
        {
            result = result * 16 + ch - '0';
        }
        else
        {
            result = result * 16 + ch - 'A' + 10;
        }
    }
    return result;
}
void func_23_5()
{
    char s[10] = {'j', 'u', 'n', 'm', 'o', '\0', 'y', 'z', 'a', '\0'};
    char s2[10];
    memcpy(s2, s, 10);
    printf("%s\n", s);
    memmove(s + 5, s + 6, 3);
    printf("%s\n", s);

    printf("%s\n", s2);
    memmove(s2 + 5, s2 + 6, 3);
    printf("%s\n", s2);
}

int numchar(const char *s, char ch)
{
    int result = 0;
    for (; (s = strchr(s, ch)) != NULL; s++)
        ++result;
    return result;
}
void func_23_8()
{
    printf("%d %d\n", numchar("hello world", 'l'), numchar("hello world", 'a'));
}

void func_23_11()
{
    char s[] = "junmocsqabc";
    int n = 5;
    memset(s + strlen(s) - n, 'i', n);
    printf("%s\n", s);
}

char *my_strdup(const char *s)
{
    char *result = malloc(strlen(s) + 1);
    if (result == NULL)
        return NULL;
    strcpy(result, s);
    return result;
}
int my_stricmp(const char *s1, const char *s2)
{
    char *s3 = my_strdup(s1);
    char *s4 = my_strdup(s2);
    for (char *temp = s3; *temp != '\0'; temp++)
    {
        *temp = toupper(*temp);
    }
    for (char *temp = s4; *temp != '\0'; temp++)
    {
        *temp = toupper(*temp);
    }
    int result = strcmp(s3, s4);
    free(s3);
    free(s4);
    return result;
}

char *my_strlwr(char *s)
{
    char *temp = s;
    for (; *temp != '\0'; temp++)
        *temp = tolower(*temp);
    return s;
}
char *strrev(char *s)
{
    int length = strlen(s);
    int ch;
    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        ch = s[i];
        s[i] = s[j];
        s[j] = ch;
    }
    return s;
}

char *my_strset(char *s, int ch)
{
    memset(s, ch, strlen(s));
    return s;
}
void func_23_12()
{
    char s[] = "junmocsq";
    char *s1 = my_strdup(s);
    s[0] = 'm';
    printf("%s %s\n", s, s1);
    free(s1);
}
int count_words(char *sentence)
{
    int num = 0;
    sentence = strtok(sentence, " \t\r\n,.");
    if (sentence != NULL)
    {
        num++;
    }
    else
    {
        return num;
    }

    for (; (sentence = strtok(NULL, " \t\r\n,.")) != NULL;)
        ++num;
    return num;
}
void func_23_13()
{
    char s[] = "for (; (sentence = (sentence, \" \t\r\n,.\")) != NULL; sentence++)";

    printf("%d\n", count_words(s));
    putchar('\n');
}

void func_p_23_2()
{
    char *filename = "exercise23.c";
    FILE *f = fopen(filename, "rb");
    bool is_start = true;
    int ch;
    while ((ch = getc(f)) != EOF)
    {
        if (is_start && isspace(ch))
        {
            continue;
        }
        if (is_start && ch == '\n')
        {
            continue;
        }
        putchar(ch);
        is_start = false;
        if (ch == '\n')
        {
            is_start = true;
        }
    }
    putchar('\n');
    fclose(f);
}
void func_p_23_3()
{
    char *filename = "exercise23.c";
    FILE *f = fopen(filename, "rb");
    bool is_start = true;
    int ch;
    while ((ch = getc(f)) != EOF)
    {
        putchar(toupper(ch));
    }
    putchar('\n');
    fclose(f);
}
void func_p_23_4()
{
    char s[1024];
    fgets(s, 1024, stdin);
    char *sentences[20];
    int size = 0;
    sentences[size++] = s;
    strtok(s, " ");
    for (char *temp; (temp = strtok(NULL, " \n")) != NULL;)
    {
        sentences[size++] = temp;
    }
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%s ", sentences[i]);
    }
    printf("\n");
}
void func_p_23_5()
{
    double total = 1000;
    double year = 10;
    double rate = 0.06;

    total = total * exp(rate * year);
    printf("%.2lf\n", total);
}
void func_p_23_6()
{
    char *filename = "exercise23.c";
    FILE *f = fopen(filename, "rb");
    bool is_start = true;
    int ch;
    while ((ch = getc(f)) != EOF)
    {
        if (ch == '\n' || !iscntrl(ch))
        {
            putchar(ch);
        }
        else
        {
            putchar('?');
        }
    }
    putchar('\n');
    fclose(f);
}
void func_p_23_7()
{
    int num = 0;
    char *filename = "exercise23.c";
    FILE *f = fopen(filename, "rb");
    int ch;
    while ((ch = getc(f)) != EOF)
    {
        if (strchr(".、?!;", ch) != NULL)
        {
            if ((ch = getc(f)) == EOF)
            {
                break;
            }
            if(ch=='\n'||ch==' '){
                ++num;
            }
        }
    }
    fclose(f);
    printf("sentence:%d\n",num);
}