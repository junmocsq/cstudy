#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
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
void func_p_22_11();
void func_p_22_12();
void func_p_22_13();
void func_p_22_14();
void func_p_22_16();
void func_p_22_17();
void func_p_22_18();
void func_p_22_19();

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
    // func_p_22_11();
    func_p_22_12();
    // func_p_22_13();
    // func_p_22_14();
    func_p_22_16();
    func_p_22_17();
    func_p_22_18();
    func_p_22_19();
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
// ???n?????????
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
        { // ????????????????????????????????????+1
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
void xor (char *source, char *dest)
{
    char key = '&';
    FILE *f1, *f2;
    if ((f1 = fopen(source, "rb")) == NULL)
    {
        printf("open read file %s failed\n", source);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(dest, "wb")) == NULL)
    {
        printf("open write file %s failed\n", source);
        exit(EXIT_FAILURE);
    }
    int ch;
    while ((ch = fgetc(f1)) != EOF)
    {
        ch ^= key;
        fputc(ch, f2);
    }
    fclose(f1);
    fclose(f2);
}

    void func_p_22_5()
{
    xor("fff.txt", "fff-1.txt");
    xor("fff-1.txt", "fff-2.txt");
}
void print_program(char *filename)
{
    const int NN = 20;
    FILE *f1;
    if ((f1 = fopen(filename, "rb")) == NULL)
    {
        printf("open read file %s failed\n", filename);
        exit(EXIT_FAILURE);
    }
    printf("Offset%3s", " ");
    for (int i = 0; i < (3 * NN - 6) / 2; i++)
    {
        printf(" ");
    }
    printf("Bytes");
    for (int i = 0; i < (3 * NN - 6) / 2; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < (NN - 10) / 2 + 3; i++)
    {
        printf(" ");
    }
    printf("Characters\n");

    for (int i = 0; i < 6; i++)
    {
        printf("-");
    }
    printf("   ");
    for (int i = 0; i < 3 * NN - 1; i++)
    {
        printf("-");
    }
    printf("   ");
    for (int i = 0; i < NN; i++)
    {
        printf("-");
    }
    printf("\n");
    int num = 0;
    char temp[NN + 1];
    int ch;

    while ((ch = getc(f1)) != EOF)
    {
        if (num % NN == 0)
        {
            printf("%6d   ", num);
        }
        printf("%02X", ch);

        temp[num % NN] = isspace(ch) ? '.' : ch;
        if (num % NN == NN - 1)
        {
            temp[num % NN + 1] = '\0';
            printf("   %s\n", temp);
        }
        else
        {
            printf(" ");
        }
        num++;
    }
    if (num % NN != 0) // ???????????????????????????10????????????????????????
    {
        for (int i = num % NN; i < NN - 1; i++)
        {
            printf("%3s", " ");
        }
        printf("%2s", " ");
        temp[num % NN] = '\0';
        printf("   %s\n", temp);
    }
    fclose(f1);
}
void func_p_22_6()
{
    char *filename = "fff.txt";
    print_program(filename);
}

void compress_file(char *source)
{
    FILE *f1, *f2;
    char *dest = malloc(strlen(source) + 5);
    strcpy(dest, source);
    strcat(dest, ".rle");
    if ((f1 = fopen(source, "rb")) == NULL)
    {
        printf("open read file %s failed\n", source);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(dest, "wb")) == NULL)
    {
        printf("open write file %s failed\n", dest);
        exit(EXIT_FAILURE);
    }
    int ch1 = getc(f1);
    int ch2 = -1;
    int num = 1;
    while ((ch2 = getc(f1)) != EOF)
    {
        if (ch2 == ch1)
        {
            num++;
        }
        else
        {
            putc(num, f2);
            putc(ch1, f2);
            num = 1;
        }
        ch1 = ch2;
    }
    // ??????????????????
    putc(num, f2);
    putc(ch1, f2);
    fclose(f1);
    fclose(f2);
    free(dest);
}

void uncompress_file(char *filename)
{
    int length = strlen(filename);
    char temp[] = ".rle";
    char output[length - 3];
    strncpy(output, filename, length - 4);
    printf("%s\n", output);
    for (int i = length - 4; i > 0 && i < length; i++)
    {
        if (filename[i] != temp[i - length + 4])
        {
            printf("file format is error, suffix must be '.rle'\n");
            return;
        }
    }

    FILE *f1, *f2;
    if ((f1 = fopen(filename, "rb")) == NULL)
    {
        printf("open read file %s failed\n", filename);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(output, "wb")) == NULL)
    {
        printf("open write file %s failed\n", output);
        exit(EXIT_FAILURE);
    }
    int ch1, ch2;
    while ((ch1 = getc(f1)) != EOF)
    {
        if ((ch2 = getc(f1)) == EOF)
        {
            printf("compress file error\n");
            return;
        }
        for (int i = 0; i < ch1; i++)
        {
            putc(ch2, f2);
        }
    }
    fclose(f1);
    fclose(f2);
}
void func_p_22_7()
{
    char *filename = "foo.txt";
    char *filename_compress = "foo.txt.rle";

    compress_file(filename);
    // print_program(filename);
    // print_program(filename_compress);

    uncompress_file(filename);
    uncompress_file(filename_compress);
}
void func_p_22_11()
{
    int m, d, y;
    int n;
    char temp[100];
    printf("Enter date mm/dd/yy: ");
    scanf("%s", temp);
    if ((n = sscanf(temp, "%d-%d-%d", &m, &d, &y)) == 3)
    {
    }
    else if ((n = sscanf(temp, "%d/%d/%d", &m, &d, &y)) == 3)
    {
    }
    else
    {
        return;
    }

    char *month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Your Entered the date %s %.2d, %.4d\n", month[m - 1], d, y);
    return;
}
void func_p_22_12()
{
    char *temp1 = "583,13.5,10/24/2005";
    char *temp2 = "3912,599.99,7.27.2008";
    char *temp[2] = {temp1, temp2};
    int item, m, d, y;
    float price;
    printf("%-10s%-15s%s\n", "Item", "Unit", "Purchase");
    printf("%-10s%-15s%s\n", "", "Price", "Date");
    for (int i = 0; i < sizeof(temp) / sizeof(*temp); i++)
    {
        sscanf(temp[i], "%d,%f,%d/%d/%d", &item, &price, &m, &d, &y);
        printf("%-10d$%7.2f%7s%2d/%2d/%2d\n", item, price, " ", m, d, y);
    }
}
void func_p_22_13()
{
    char *fliename = "flights.dat";
    FILE *f;
    char temp[1024];

    // ?????????flights.dat
    // int start[] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};
    // int end[] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58};
    // if ((f = fopen(fliename, "w")) == NULL)
    // {
    //     printf("open write file %s failed\n", fliename);
    //     exit(EXIT_FAILURE);
    // }
    // for (int i = 0; i < sizeof(start) / sizeof(*start); i++)
    // {
    //     sprintf(temp, "%d:%.2d %d:%.2d\n", start[i] / 60, start[i] % 60, end[i] / 60, end[i] % 60);
    //     // printf("%s", temp);
    //     fputs(temp, f);
    // }
    // fclose(f);
    if ((f = fopen(fliename, "r")) == NULL)
    {
        printf("open read file %s failed\n", fliename);
        exit(EXIT_FAILURE);
    }
    int(*arr)[2] = NULL;
    int length = 0;
    int t1, t2, t3, t4;
    while (fgets(temp, 1024, f) != NULL)
    {
        sscanf(temp, "%d:%d %d:%d\n", &t1, &t2, &t3, &t4);
        length++;
        arr = realloc(arr, length * sizeof(*arr));
        arr[length - 1][0] = t1 * 60 + t2;
        arr[length - 1][1] = t3 * 60 + t4;
    }

    int hour, minute;
    printf("Enter a 24-hour time(xx:xx): ");
    scanf("%d:%d", &hour, &minute);
    int minutes = hour * 60 + minute;
    printf("Closest departure time is ");
    int s = arr[0][0], e = arr[0][1];
    for (int i = 0; i < length; i++)
    {
        if (minutes <= arr[i][0])
        {
            s = arr[i][0];
            e = arr[i][1];
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
    free(arr);
    while (getchar() != '\n')
        ;
}
void func_p_22_14()
{

    char filename[1024], filename_enc[1024];
    printf("Enter file name: ");
    scanf("%s", filename);
    strncpy(filename_enc, filename, strlen(filename));
    filename_enc[strlen(filename)] = '\0';
    strcat(filename_enc, ".enc");
    printf("%s %s %lu\n", filename, filename_enc, strlen(filename));
    // return;
    FILE *f1, *f2;
    if ((f1 = fopen(filename, "rb")) == NULL)
    {
        printf("open read file %s failed\n", filename);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(filename_enc, "wb")) == NULL)
    {
        printf("open write file %s failed\n", filename_enc);
        exit(EXIT_FAILURE);
    }

    printf("Enter shift amount[1-25]: ");
    int num;
    scanf("%d", &num);
    int ch;
    while ((ch = getc(f1)) != EOF)
    {
        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' + num) % 26 + 'a';
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' + num) % 26 + 'A';
        }
        putc(ch, f2);
    }
    fclose(f1);
    fclose(f2);
}
void fcopy(char *source, char *dest)
{
    FILE *f1, *f2;
    if ((f1 = fopen(source, "rb")) == NULL)
    {
        printf("open read file %s failed\n", source);
        exit(EXIT_FAILURE);
    }
    if ((f2 = fopen(dest, "wb")) == NULL)
    {
        printf("open write file %s failed\n", dest);
        exit(EXIT_FAILURE);
    }

    char temp[512];
    int n;
    while (1)
    {
        n = fread(temp, 1, 512, f1);
        // printf("%d\n", n);
        if (n > 0)
            fwrite(temp, 1, n, f2);
        if (feof(f1))
            break;
    }

    fclose(f1);
    fclose(f2);
}
void func_p_22_16()
{
    char *source = "exercise22.c", *dest = "exercise22.c.bak";
    fcopy(source, dest);
}

void format_phone(char *filename)
{
    FILE *f1;
    if ((f1 = fopen(filename, "rb")) == NULL)
    {
        printf("open read file %s failed\n", filename);
        exit(EXIT_FAILURE);
    }
    char temp[1024];
    int d1, d2, d3;
    int flag = 0;
    while (fgets(temp, 1024, f1) != NULL)
    {
        flag = 0;
        if (sscanf(temp, "%d.%d.%d", &d1, &d2, &d3) == 3)
        {
            flag = 1;
        }
        else if (sscanf(temp, "(%d) %d-%d", &d1, &d2, &d3) == 3)
        {
            flag = 1;
        }
        else if (sscanf(temp, "%d-%d-%d", &d1, &d2, &d3) == 3)
        {
            flag = 1;
        }
        else if (sscanf(temp, "%d%d%d", &d1, &d2, &d3) == 3)
        {
            flag = 1;
        }
        else if (sscanf(temp, "%3d%3d%4d", &d1, &d2, &d3) == 3)
        {
            flag = 1;
        }
        if (flag)
        {
            printf("(%d) %d-%d\n", d1, d2, d3);
        }
    }
    fclose(f1);
}
void func_p_22_17()
{
    char *filename = "f22_17.txt";
    format_phone(filename);
}
void func_p_22_18() {
    // TODO
    FILE *f;
    if ((f = fopen(filename, "rb")) == NULL)
    {
        printf("open read file %s failed\n", filename);
        exit(EXIT_FAILURE);
    }
    int ch;
    int max,min,mid;
    fclose(f);

}
void unix2windows(char *filename)
{
    FILE *f, *ftemp;
    if ((f = fopen(filename, "rb")) == NULL)
    {
        printf("open read file %s failed\n", filename);
        exit(EXIT_FAILURE);
    }
    ftemp = tmpfile();
    int ch;
    while ((ch = getc(f)) != EOF)
    {
        if (ch == '\n')
        {
            putc('\r', ftemp);
            putc(ch, ftemp);
        }
        else
        {
            putc(ch, ftemp);
        }
    }
    fclose(f);
    fseek(ftemp, 0, SEEK_SET);
    if ((f = fopen(filename, "wb")) == NULL)
    {
        printf("open write file %s failed\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(ftemp)) != EOF)
    {
        putc(ch, f);
    }
    fclose(f);
    fclose(ftemp);
}
void windows2unix(char *filename)
{
    FILE *f, *ftemp;
    if ((f = fopen(filename, "rb")) == NULL)
    {
        printf("open read file %s failed\n", filename);
        exit(EXIT_FAILURE);
    }
    ftemp = tmpfile();
    int ch, ch2;
    while ((ch = getc(f)) != EOF)
    {
        if (ch == '\r')
        {
            if ((ch2 = getc(f)) == EOF)
            {
                putc(ch, ftemp);
                break;
            }
            if (ch2 != '\n')
            {
                putc(ch, ftemp);
            }
            putc(ch2, ftemp);
        }
        else
        {
            putc(ch, ftemp);
        }
    }
    fclose(f);
    fseek(ftemp, 0, SEEK_SET);
    if ((f = fopen(filename, "wb")) == NULL)
    {
        printf("open write file %s failed\n", filename);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(ftemp)) != EOF)
    {
        putc(ch, f);
    }
    fclose(f);
    fclose(ftemp);
}
void func_p_22_19()
{
    // unix \n
    // windows \r\n
    unix2windows("exercise22.c.bak");
    windows2unix("exercise22.c.bak");
}