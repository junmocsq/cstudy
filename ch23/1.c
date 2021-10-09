#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <errno.h>
#include <string.h>

#define PRINT_DOUBLE(x) printf("%lf\n", x)

#if INT_MAX < 100000
#error short int is too samll
#endif
int main()
{
    printf("%g %g\n", FLT_MAX, FLT_MIN);
    printf("%d %d %d\n", FLT_MANT_DIG, DBL_MANT_DIG, LDBL_MANT_DIG);
    printf("%g %g\n", DBL_MAX, DBL_MIN);
    printf("%Lg %Lg\n", LDBL_MAX, LDBL_MIN);
    // printf("%Lf %Lf\n",LDBL_MAX,LDBL_MIN);
    printf("%ld\n", sizeof(long double));
    printf("%d %d %d\n", CHAR_MAX, SCHAR_MAX, UCHAR_MAX);
    printf("%d\n", MB_LEN_MAX);
    printf("%lld %ld\n", LLONG_MAX, LONG_MAX);

    printf("%g\n", HUGE_VAL);
    errno = 0;
    printf("%lf\n", acos(2));
    printf("errno: %d\n", errno);

    PRINT_DOUBLE(ldexp(2.0, 4));
    PRINT_DOUBLE(ldexp(2.0, 4));
    double x = 20, y = -30;
    PRINT_DOUBLE(copysign(x, y));
    PRINT_DOUBLE(nextafter(x, y));

    char s[] = "系统管理unix权威指南";
    printf("%s %ld %ld\n", s, sizeof(s), strlen(s));

    char s1[] = "hello unix linux xxx";
    printf("%ld %ld\n", (char *)memchr(s1, 'x', strlen(s1)) - s1, strchr(s1, 'x') - s1);
    printf("%p %p\n", s1, strrchr(s1, 'a'));
    printf("%p %ld\n", s1, strpbrk(s1, "uo") - s1);
    printf("%lu %lu\n", strspn(s1, "heo "), strcspn(s1, "abc"));
    printf("%ld %p\n", strstr(s1, "unix") - s1, strstr(s1, "abc"));

    char s2[] = "  April \t\t28,1998";
    printf("--:%s--\n", strtok(s2, " \t"));    // --:April--
    printf("--:%s--\n", strtok(NULL, " \t,")); // --:28--
    printf("--:%s--\n", strtok(NULL, " \t"));  // --:1998--

    return 0;
}