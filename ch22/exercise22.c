#include <stdlib.h>
#include <stdio.h>
#define N 10

void func_22_4();
void func_22_7();
void func_22_12();
void func_22_13();
void func_22_14();
void func_22_15();
void func_22_16();
int main()
{
    func_22_4();
    func_22_7();
    func_22_12();
    func_22_13();
    func_22_14();
    func_22_15();
    func_22_16();

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