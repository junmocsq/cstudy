#include <stdio.h>

// gcc 03.c&& ./a.out
int main(void)
{
    int i = 99;
    int j = 1000;
    printf("%d %d\n", i);    // output: 99 -317700184 ;第二个数是随机的，无意义的
    printf("%d\n", i, j);    // output: 99  ;第二个数不显示
    printf("%f %d\n", i, j); // output: 0.000000 99 ; 编译器不会检查数据类型，如果类型不对，会产生无意义的输出
    printf("--------------------\n");
    i = 999999999;
    float fi = 78991999.0f;
    printf("%d\n", i);
    printf("%e\n", fi);
    printf("%f\n", fi);
    printf("%g\n", fi); // g根据数的大小选择合适的计数方式 7.8992e+07
    return 0;
}