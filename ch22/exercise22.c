#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#define N 10

void func_22_4();
void func_22_7();
void func_22_12();
void func_22_13();
void func_22_14();
void func_22_15();
void func_22_16();

void func_p_22_1();
void func_p_22_2();
void func_p_22_3();
void func_p_22_4();
void func_p_22_5();
void func_p_22_6();
void func_p_22_7();
void func_p_22_8();

int main()
{
    func_22_4();
    func_22_7();
    func_22_12();
    func_22_13();
    func_22_14();
    func_22_15();
    func_22_16();

    func_p_22_1();
    // func_p_22_2();
    func_p_22_3();
    func_p_22_4();
    func_p_22_5();
    func_p_22_6();
    func_p_22_7();
    func_p_22_8();
    return 0;
}

void func_22_4()
{
    printf("%#012.5f\n", 83.7361);
    printf("%#012.5g\n", 83.7361);
    printf("%#012.5g\n", 29748.6607);
    printf("%#012.5g\n", 1054932234.0);
    printf("%#012.5g\n", 0.0000235218);
    printf("%.4d %04d\n", 18766, 18766);
    printf("%.4s %s\n", "18766", "87661");
    int n = 1;
    printf(n > 1 ? "%d widgets\n" : "%d widget\n", n);
    n = 100;
    printf(n > 1 ? "%d widgets\n" : "%d widget\n", n);
}
void func_22_7()
{
    int n, i, j;
    float x;
    n = sscanf("10 20 30 ", "%d%f%d", &i, &x, &j);
    printf("%d i:%d x:%f j:%d\n", n, i, x, j);

    n = sscanf("1.0 2.0 3.0 ", "%d%f%d", &i, &x, &j);
    printf("%d i:%d x:%f j:%d\n", n, i, x, j);

    n = sscanf("0.1 0.2 0.3 ", "%d%f%d", &i, &x, &j);
    printf("%d i:%d x:%f j:%d\n", n, i, x, j);

    n = sscanf(".1 .2 .3 ", "%d%f%d", &i, &x, &j);
    printf("%d i:%d x:%f j:%d\n", n, i, x, j);
    /**
    3 i:10 x:20.000000 j:30
    3 i:1 x:0.000000 j:2
    3 i:0 x:0.100000 j:0
    0 i:0 x:0.100000 j:0
    */
    char ch;
    n = sscanf("jm", " %c", &ch);
    printf("n:%d c:%c\n", n, ch);
    char temp[10];
    n = sscanf("jm", "%1s%c", temp, &ch);
    printf("n:%d c:%c\n", n, ch);
}

int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    int ch;
    if ((fp = fopen(filename, "r")) != NULL)
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == '.')
                ++n;
        }
        fclose(fp);
    }
    return n;
}
void func_22_12()
{
    printf("fff1.txt: %d\n", count_periods("fff1.txt"));
}
// 第n行长度
int line_length(const char *filename, int n)
{
    int line = 1;
    int count = 0;
    int ch;
    FILE *fp;
    if ((fp = fopen(filename, "r")) != NULL)
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == '\n')
                ++line;
            else if (line == n)
            {
                ++count;
                // putchar(ch);
            }
        }
        // putchar('\n');
        fclose(fp);
    }
    return count;
}
void func_22_13()
{
    printf("fff1.txt: %d\n", line_length("fff1.txt", 11));
}

char *my_fgets(char *s, int n, FILE *fp)
{
    int i = 0;
    int ch;
    for (; i < n - 1;)
    {
        ch = getc(fp);
        if (ch == EOF)
        {
            if (i == 0)
            {
                return NULL;
            }
            break;
        }
        s[i] = ch;
        i++;
        if (ch == '\n')
            break;
    }
    s[i] = '\0';
    return s;
}
int my_fputs(char *s, FILE *fp)
{
    int i = 0;
    int ch;
    for (; *s != '\0'; s++)
    {
        if (putc(*s, fp) == EOF)
        {
            return EOF;
        }
        ++i;
    }
    return i;
}
void func_22_14()
{
    char filename[] = "fff2.txt";
    FILE *fp;
    char temp[N];
    if ((fp = fopen(filename, "r")) != NULL)
    {
        while (my_fgets(temp, N, fp) != NULL)
        {
            my_fputs(temp, stdout);
        }
        fclose(fp);
    }
}

void repeat_str(char *s, int n, int ch)
{
    for (int i = 0; i < n - 2; i++)
        s[i] = ch;
    s[n - 2] = '\n';
    s[n - 1] = '\0';
}
void func_22_15()
{
    char *filename = "foo.txt";
    FILE *fp = fopen(filename, "w+");
    char temp[65];
    int n = 10;
    for (int i = 0; i < 20; i++)
    {
        repeat_str(temp, 65, 'A' + i);
        my_fputs(temp, fp);
    }

    fseek(fp, n * 64, SEEK_SET);
    repeat_str(temp, 65, 'a');
    my_fputs(temp, fp);
    fseek(fp, -64, SEEK_END);
    repeat_str(temp, 65, 'b');
    my_fputs(temp, fp);
    rewind(fp);

    fseek(fp, 13 * 64, SEEK_SET);
    printf("\n\ncurr:%ld\n", ftell(fp));
    fseek(fp, -64, SEEK_CUR);
    printf("previous:%ld\n", ftell(fp));
    fseek(fp, 13 * 64, SEEK_SET);
    fseek(fp, 2 * 64, SEEK_CUR);
    printf("next two:%ld\n", ftell(fp));
    fclose(fp);
}
void get_sales_rank(char *sales_rank, int n)
{
    int count;
    count = sscanf("junmo#989csq", "%*[^0123456789]%[0123456789,]%*[^0123456789]", sales_rank);
    printf("%d %s\n", count, sales_rank);
    count = sscanf("junmo#24,675csq", "%*[^0123456789]%[0123456789,]%*[^0123456789]", sales_rank);
    printf("%d %s\n", count, sales_rank);
    count = sscanf("junmo#1,234,989csq", "%*[^0123456789]%[0123456789,]%*[^0123456789]", sales_rank);
    printf("%d %s\n", count, sales_rank);
}
void func_22_16()
{
    char sales_rank[1024];
    get_sales_rank(sales_rank, 1024);
}

void canopen(int n_values, ...)
{
    va_list vlist;
    va_start(vlist, n_values);
    char *temp;
    FILE *fp;
    for (int i = 0; i < n_values; i++)
    {
        temp = va_arg(vlist, char *);
        if ((fp = fopen(temp, "r")) != NULL)
        {
            printf("%s can be opened!\n", temp);
            fclose(fp);
        }
        else
        {
            printf("%s can't be opened!\n", temp);
            exit(EXIT_FAILURE);
        }
    }
    va_end(vlist);
}
void func_p_22_1()
{
    canopen(3, "fff.txt", "fff1.txt", "fff2.txt");
}
void func_p_22_2()
{
    char s[1024];
    int ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        s[i++] = toupper(ch);
    }
    s[i] = '\0';
    fprintf(stdout, "%s\n", s);
}

void fcat(int n_values, ...)
{
    va_list vlist;
    va_start(vlist, n_values);
    char *temp;
    FILE *fp;
    char read[N];
    for (int i = 0; i < n_values; i++)
    {
        temp = va_arg(vlist, char *);
        if ((fp = fopen(temp, "r")) != NULL)
        {
            printf("%s can be opened!\n", temp);
            while (fgets(read, N, fp) != NULL)
            {
                fprintf(stdout, "%s", read);
            }
            fclose(fp);
        }
        else
        {
            printf("%s can't be opened!\n", temp);
        }
    }
    va_end(vlist);
}
void func_p_22_3()
{
    fcat(3, "fff1.txt", "fff2.txt", "foo.txt");
}

void count_prog(char *name, int *ch_num, int *word_num, int *line_num)
{
    *ch_num = 0;
    *word_num = 0;
    *line_num = 0;
    FILE *fp;
    int ch;
    int is_word_start = 0;
    if ((fp = fopen(name, "r")) != NULL)
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            (*ch_num)++;
            if (isspace(ch))
            {
                is_word_start = 1;
            }
            else if (is_word_start == 1)
            {
                (*word_num)++;
                is_word_start = 0;
            }
            if (ch == '\n')
            {
                (*line_num)++;
            }
        }
        if (ch != '\n')
        { // 如果最后一行没有换行符，+1
            (*line_num)++;
        }
        fclose(fp);
    }
    else
    {
        printf("%s can't be opened!\n", name);
    }
}
void func_p_22_4()
{
    int ch_num, word_num, line_num;
    count_prog("fff1.txt", &ch_num, &word_num, &line_num);
    printf("char: %d, word: %d, line: %d\n", ch_num, word_num, line_num);
}
void func_p_22_5() {}
void func_p_22_6() {}
void func_p_22_7() {}
void func_p_22_8() {}