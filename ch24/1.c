#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <string.h>
#include <setjmp.h>

jmp_buf env;
void f1(void);
void f2(void);
int main()
{

    errno = 0;
    double x = -4;
    x = acos(x);
    if (errno != 0)
    {
        perror("sqrt error");
    }
    errno = 0;
    // int xx, yx = 0;
    // xx = xx / yx;
    printf("errno: %d %lf\n", errno, x);

    puts(strerror(EDOM));

    if (setjmp(env) == 0)
    {
        printf("setjmp returned 0\n");
    }
    else
    {
        printf("Program terminates: longjmp called\n");
        return 0;
    }
    f1();
    printf("Program terminates normally.\n");
    return 0;
}

void f1(void)
{
    printf("f1 begins\n");
    f2();
    printf("f1 returns\n");
}
void f2(void)
{
    printf("f2 begins\n");
    longjmp(env, 1);
    printf("f2 returns\n");
}