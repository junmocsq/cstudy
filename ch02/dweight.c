#include <stdio.h>

// gcc dweight.c && ./a.out
int main(void)
{
    int length, width, heigth, volume, weight;
    length = 12;
    width = 10;
    heigth = 8;
    volume = length * width * heigth;
    weight = (volume + 165) / 166;
    printf("箱子：长：%d 宽：%d 高：%d\n", length, width, heigth);
    printf("体积：%d\n", volume);
    printf("需要付费的重量：%d (磅)\n", weight);
    return 0;
}