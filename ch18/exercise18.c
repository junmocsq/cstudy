#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char func_18_8_a_f(int a)
{
    return a;
}
char (*func_18_8_a[10])(int) = {func_18_8_a_f};
int (*func_18_8_b(int))[5];
float *(*func_18_8_c(void))(int);
void (*func_18_8_d(int, void (*y)(int)))(int);
void func_18_8_d_y(int b);

char *func_18_10_a(char *);
struct t
{
    int x, y;
};
void (*func_18_10_b(struct t *p, long n))();

void insert(void) { printf("--insert\n"); }
void search(void) { printf("--search\n"); }
void update(void) { printf("--update\n"); }
void print(void) { printf("--print\n"); }
void (*func_18_10_c[4])() = {insert, search, update, print};
struct t func_18_10_d_f(int x, int y)
{
    return (struct t){x * x, y * y};
}
struct t (*func_18_10_d[10])(int, int) = {func_18_10_d_f, func_18_10_d_f, func_18_10_d_f};
 void func_18_11()
 {
     int(*f(int))[10][10];
     int (*g(int))(int);
     int (*a[10])(int);
 }

float func_18_12_params(long x){
    return x*2222/1.0f;
}
int (*func_18_12(float (*)(long), char *))(double);
int main(void)
{
    printf("%c\n", func_18_8_a[0]('A'));
    int *testb = *func_18_8_b(10);
    printf("%d %d\n", testb[0], testb[4]);
    printf("%f\n", *func_18_8_c()(100));
    func_18_8_d(14, func_18_8_d_y)(15);
    char func_18_v[30] = "cs";
    char *(*func_18_10_a_v)(char *) = func_18_10_a;
    printf("%s\n", func_18_10_a_v(func_18_v));

    struct t ttttt = {200, 500};
    func_18_10_b(&ttttt, 9000)();
    func_18_10_c[0]();
    func_18_10_c[1]();
    func_18_10_c[2]();
    func_18_10_c[3]();

    struct t ttttt10 = func_18_10_d[0](4, 5);
    printf("func_18_10_d: %d %d\n", ttttt10.x, ttttt10.y);
    printf("func_18_12: %d\n",func_18_12(func_18_12_params,"junmocsq")(100.0));

    // static int jjj=5,j2=jjj*jjj;
    return 0;
}
int (*func_18_8_b(int v))[5]
{
    static int b[5] = {1, 2, 3, 4, 5};
    for (int a = 0; a < 5; a++)
    {
        b[a] += v;
    }
    return &b;
}
float *ffc(int v)
{
    static float i = 10;
    i += v;
    return &i;
}
float *(*func_18_8_c(void))(int)
{
    return ffc;
}
void func_18_8_d_y(int b)
{
    printf("yyyyy----%d\n", b * b);
}
void (*func_18_8_d(int a, void (*y)(int b)))(int)
{
    printf("fd---fd--%d\n", a * a);
    return y;
}

char *func_18_10_a(char *str)
{
    return strcat(str, "junmo");
}
void func_18_10_b_return()
{
    printf("func_18_10_b_return\n");
}
void (*func_18_10_b(struct t *p, long n))()
{
    printf("18_10_b:t x:%d y:%d n:%ld\n", p->x, p->y, n);
    return func_18_10_b_return;
}

int func_18_12_return(double x)
{
    printf("func_18_12-2:%.2lf\n",x);
    return (int)x / 10;
}
int (*func_18_12(float (*f)(long), char *b))(double)
{
    float i = f((long)strlen(b));
    printf("func_18_12-1:%.2f\n",i);
    return func_18_12_return;
}