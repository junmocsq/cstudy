#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// 练习题
void func_13_1(void);
void func_13_2(void);
void func_13_3(void);
void func_13_4(void);
void func_13_5(void);
void func_13_6(void);
void func_13_7(void);
void func_13_8(void);
void func_13_9(void);
void func_13_10(void);
void func_13_11(void);
void func_13_12(void);
void func_13_13(void);
void func_13_14(void);
void func_13_15(void);
void func_13_16(void);
void func_13_17(void);
void func_13_18(void);

void func_13_1(void)
{
    printf("%c", '\n');
    printf("%s", "\n");
    printf("\n");
    putchar('\n');
    puts("abc");
    puts("\n");
    puts("");
}

void func_13_2(void)
{
    char *p = "abc";
    // putchar(p);
    putchar(*p);
    puts(p);
    // puts(*p);
}
void func_13_3(void)
{
    int i, j;
    char s[100];
    scanf("%d%s%d\n", &i, s, &j);
    printf("%d:%s:%d\n", i, s, j);
}

int read_line(char *msg, int n)
{
    int i = 0;
    char ch;
    while (isspace((ch = getchar())))
        ;

    while (1)
    {
        if (isspace(ch))
            break;
        *msg++ = ch;
        i++;
        if (i == n)
        {
            break;
        }
        if (ch == '\n')
            break;
        ch = getchar();
        /* code */
    }
    return i;
}
void func_13_4(void)
{
    char msg[11];
    int i = 0;
    i = read_line(msg, 10);
    msg[i] = '\0';
    printf("%s\n", msg);
    i = read_line(msg, 10);
    msg[i] = '\0';
    printf("%s %d\n", msg, msg[3]);
}
void capitalize1(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = toupper(str[i]);
        i++;
    }
}
void capitalize2(char *str)
{
    while (*str != '\0')
    {
        *str = toupper(*str);
        str++;
    }
}
void func_13_5(void)
{
    char msg1[] = "junmocsq123";
    char msg2[] = "junmocsq123";
    capitalize1(msg1);
    capitalize2(msg2);
    printf("%s %s\n", msg1, msg2);
}

void censor(char *str)
{
    int i = 0;
    char search[3] = {'f', 'o', 'o'};
    char replace[3] = {'x', 'x', 'x'};
    int j;
    while (*str != '\0')
    {
        for (j = 0; j < 3; j++)
        {
            if (*str != search[j])
                break;
            else
                str++;
        }
        if (j == 3)
        {
            strncpy(str - 3, replace, 3);
        }
        else
        {
            str = str - j + 1;
        }
    }
}
void func_13_6(void)
{
    char str[] = "ffood fofool";
    censor(str);
    printf("%s\n", str);
}
void func_13_7(void)
{
    char mm[] = "csq";
    strcat(mm, "");
    printf("1:%s \n", mm);
}
void func_13_8(void)
{
    char a[100] = "junmocsq";
    printf("%s\n", a);
    strcpy(a, "tire-bouchon");
    printf("%s\n", a);
    strcpy(&a[4], "d-or-wi");
    printf("%s\n", a);
    strcpy(a, "red?");
    printf("%s\n", a);
}
void func_13_9(void)
{
    char s1[20] = "computer";
    char s2[20] = "science";
    if (strcmp(s1, s2) < 0)
    {
        strcat(s1, s2);
    }
    else
    {
        strcat(s2, s1);
    }
    s1[strlen(s1) - 6] = '\0';
    printf("%s\n", s1);
}
void duplicate(const char *p, char *result)
{
    strcpy(result, p);
}
void func_13_10(void)
{
    char s[10];
    char a[] = "masaka";
    duplicate(a, s);
    printf("%s\n", s);
}
int my_strcmp(const char *s, const char *t)
{
    for (; *s == *t;)
    {
        if (*s == '\0')
            return 0;
        s++;
        t++;
    }
    return *s - *t;
}
void func_13_11(void)
{
    char *s1 = "junmo";
    char *s2 = "junmo1";
    printf("%d\n", my_strcmp(s1, s2));
}
void get_extension(const char *file_name, char *extension)
{
    int length = strlen(file_name);
    file_name += length - 1;
    int i = length;
    while (*file_name != '.' && --i > 0)
    {
        file_name--;
    }
    if (*file_name == '.')
        strcpy(extension, file_name + 1);
    else
    {
        extension[0] = '\0';
    }
}
void func_13_12(void)
{
    char msg[] = ".junmocsq";
    char ext[10];
    get_extension(msg, ext);
    printf("extension:%s %d\n", ext, ext[0]);
}
void bulid_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, "http://www.");
    strcat(strcat(index_url, domain), "/index.html");
}
void func_13_13(void)
{
    char index_url[100];
    char *domain = "google.com";
    bulid_index_url(domain, index_url);
    printf("%s\n", index_url);
}
void func_13_14(void)
{
    char s[] = "Hsjodi", *p;
    for (p = s; *p; p++)
    {
        --*p;
    }
    puts(s); // Grinch
}
int f(char *s, char *t)
{
    char *p1, *p2;
    for (p1 = s; *p1; p1++)
    {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2)
                break;
        if (*p2 == '\0')
            break;
    }
    return p1 - s;
}
void func_13_15(void)
{
    printf("%d\n", f("abcd", "babc"));
    printf("%d\n", f("abcd", "bcd"));
}
int count_space(const char s[])
{
    int count = 0;
    for (; *s; s++)
    {
        if (*s == ' ')
            count++;
    }
    return count;
}
void func_13_16(void)
{
    printf("%d\n", count_space("j u n m ocsq "));
}

bool test_extension(const char *file_name, const char *extension)
{

    while (*file_name)
    {
        if (*file_name == '.')
        {
            file_name++;
            break;
        }
        file_name++;
    }
    bool result = false;
    for (; *file_name && *extension;)
    {
        if (toupper(*file_name++) != toupper(*extension++))
            break;
    }
    if (*file_name == '\0' && *extension == '\0')
        result = true;
    return result;
}
void func_13_17(void)
{
    printf("%d\n", test_extension("memo.txt", "Txt"));
    printf("%d\n", test_extension("memo.txts", "Txts"));
}

void remove_filename(char *url)
{
    char *p1 = url + strlen(url) - 1;
    while (p1 >= url)
    {
        if (*p1-- == '/')
        {
            *(p1 + 1) = '\0';
            break;
        }
    }
}
void func_13_18(void)
{
    char url[] = "https://www.google.com/index.html";
    remove_filename(url);
    puts(url);
}