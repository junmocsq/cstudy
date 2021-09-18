#include <stdio.h>
#define INCHES_PER_POUND 166
// gcc dweight2.c && ./a.out
int main(void)
{
    int length, width, heigth, volume, weight;
    printf("Enter length, width, heigth:");
    scanf("%d%d%d", &length, &width, &heigth);
    volume = length * width * heigth;
    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
    printf("箱子：长：%d 宽：%d 高：%d\n", length, width, heigth);
    printf("体积：%d\n", volume);
    printf("需要付费的重量：%d (磅)\n", weight);
    return 99;
}
