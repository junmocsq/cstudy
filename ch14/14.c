#include <stdio.h>
#include "01.c"
#define PRINT_INT(n) printf(#n " = %d\n", n)
#define ECHO(s) (gets(s), puts(s))

#define ECHO2(s) \
    do           \
    {            \
        gets(s); \
        puts(s); \
    } while (0)
int main(void)
{
    int n = 199;
    PRINT_INT(n / 12);
#define MK_ID(n) i##n

    int MK_ID(1) = 100, MK_ID(2) = 200, MK_ID(3) = 300;
    PRINT_INT(MK_ID(1));
    PRINT_INT(i1);
    PRINT_INT(ABC);

#define DEBUG 0
#if defined DEBUG
    printf("defined DEBUG\n");

#endif
#if DEBUG
    char m1[] = "MMMM";
    char m2[] = "CSQ";
    ECHO(m1);
    ECHO2(m2);
#endif
#line 12
    printf("line:%d\n", __LINE__);
#define TEST(condition, ...) ((condition) ? printf("Passed test: %s\n", #condition) : printf(__VA_ARGS__))
    int voltage = 99, max_voltage = 999;
    TEST(voltage <= max_voltage, "Voltage %d exceeds %d\n", voltage, max_voltage); // Passed test: voltage <= max_voltage
    voltage = 99999, max_voltage = 999;
    TEST(voltage <= max_voltage, "Voltage %d exceeds %d\n", voltage, max_voltage); // Voltage 99999 exceeds 999

    return 0;
}
#undef ABC
#define ABC 888