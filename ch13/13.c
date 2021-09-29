#include <stdio.h>

void testabc(char *a)
{
    a[0] = 'G';
    a[1] = 'K';
}
// cc 13.c&& ./a.out
int main(void)
{
    char aa[] = "CSQCSQ";
    char *bb = "CSQCSQ";
    printf("%p %p\n", aa, bb);
    printf("%s %s\n", aa, bb);
    testabc(aa);
    // testabc(bb);
    printf("%s %s\n", aa, bb);
}