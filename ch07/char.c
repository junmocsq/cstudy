#include <stdio.h>
#include <ctype.h>

int main()
{
    for (int i = 'a'; i <= 'z'; i++)
    {
        printf("%c%c\v", i, i + 'A' - 'a');
    }
    printf("\n");

    printf("%d %d %d %d\n", 'A', 0b1000001, 0101, 0x41);
    return 0;
}