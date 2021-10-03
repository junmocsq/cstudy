#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void func_14_1();
void func_14_2();
void func_14_3();
void func_14_4();
void func_14_5();
void func_14_6();
void func_14_7();
void func_14_8();
void func_14_9();
void func_14_10();
void func_14_11();
void func_14_14();
int main()
{
    func_14_1();
    func_14_2();
    func_14_3();
    func_14_4();
    func_14_5();
    func_14_6();
    func_14_7();
    func_14_8();
    func_14_9();
    func_14_10();
    func_14_11();
    func_14_14();
    return 0;
}

void func_14_1()
{
#define SQURE(x) ((x) * (x))
#define DIV4(n) ((n) % 4)
#define COMPARE(x, y) ((((x) * (y)) < 100) ? 1 : 0)
    printf("%d %d %d\n", SQURE(10), DIV4(99), COMPARE(4, 8));
}
void func_14_2()
{
#define NELEMS(a) ((int)(sizeof(a) / sizeof(a[0])))
    int a[20];
    printf("s len: %d\n", NELEMS(a));
}
void func_14_3()
{
#define DOUBLE(x) 2 * x
    printf("DOUBLE(1+2)=%d\n", DOUBLE(1 + 2));
    printf("4/DOUBLE(2)=%d\n", 4 / DOUBLE(2));
#undef DOUBLE
#define DOUBLE(x) (2 * (x))
    printf("DOUBLE(1+2)=%d\n", DOUBLE(1 + 2));
    printf("4/DOUBLE(2)=%d\n", 4 / DOUBLE(2));
}
void func_14_4() {}
void func_14_5()
{
#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))
    char s[10];
    strcpy(s, "abcd");
    int i = 0;
    putchar(TOUPPER(s[++i]));
    strcpy(s, "0123");
    i = 0;
    putchar(TOUPPER(s[++i]));
    puts("");
}
double add(double x, double y)
{
    return x + y;
}
void func_14_6()
{
#define DISP(x, y) printf("sqrt(%g) = %g\n", y, x(y))
    DISP(sqrt, 3.0);
#define DISP2(f, x, y) printf("sqrt(%g,%g) = %g\n", x, y, f(x, y))
    DISP2(add, 3.0, 4.0);
}
void func_14_7() {}
void func_14_8()
{
#define LINE_FILE() printf("Line %d of %s\n", __LINE__, __FILE__)
    LINE_FILE();
}

void func_14_9()
{
#define CHECK(x, y, n) ((x) >= 0 && (x) <= (n)-1 && (y) >= 0 && (y) <= (n)-1 ? 1 : 0)
#define MEDIANS(x, y, z) ((x) <= (y) && (x) >= (z) || (x) <= (z) && (x) >= (y)) ? (x) : ((y) <= (x) && (y) >= (z) || (y) <= (z) && (y) >= (x) ? (y) : (z))
#define POLYNOMIAL(x) (3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) + pow(x, 2) + 7 * (x)-6)
    int i;
    i = CHECK(1, 99, 100);
    printf("14.9: %d\n", i);
    i = MEDIANS(3, 2, 7);
    printf("14.9: %d\n", i);
    i = POLYNOMIAL(5);
    printf("14.9: %d\n", i);
}
int abc()
{
    do
    {
        if ((3) <= (2) && (3) >= (7) || (3) <= (7) && (3) >= (2))
            return 3;
        else if ((2) <= (3) && (2) >= (7) || (2) <= (7) && (2) >= (3))
            return 2;
        else
            return 7;
    } while (0);
}
void func_14_10()
{
    printf("%d\n", abc());
}
void func_14_11()
{
#define ERROR(...) fprintf(stderr, __VA_ARGS__)
    ERROR("Range error: index = %d\n", 1);
}

void func_14_14()
{
#define N 10
#define INC(x) ((x) + 1)
#define SUB(x, y) ((x) - (y))
#define SQR(x) ((x) * (x))
#define CUBE(x) (SQR(x) * (x))
#define M1(x, y) x##y
#define M2(x, y) (#x #y "juuu")

    int a[N], i, j, k, m;
#ifdef N
    i = j;
#else
    j = i;
#endif
    i = 10 * INC(j);
    i = SUB(j, k);
    i = SQR(SQR(j));
    i = CUBE(j);
    int jk = 0;
    printf("%d\n", M1(j, k));
    puts(M2(i, j));
#undef SQR
    // i = SQR(j);
#define SQR
    i = SQR(j);
}