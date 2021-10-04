#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
typedef struct part
{
    int number;
    char name[21];
    int on_hand;
    struct part *next, *pre;

} Part;

void f(struct part part)
{
}
typedef struct complex
{
    double real, imaginary;
} Complex;
int main()
{
    struct
    {
        int x, y;
    } x;
    struct
    {
        int x, y;
    } y;
    typedef enum suits
    {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    } Suit;
    Part a, b;
    struct part c, d;
    c = a;
    struct ccc
    {
        double real, imaginary;
    } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;
    c1 = c2;
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;

    // struct complex c1, c2, c3;

    struct
    {
        double a;
        union
        {
            char b[4];
            double c;
            int d;
        } e;
        char f[4];
    } s;
    union
    {
        double a;
        union
        {
            char b[4];
            double c;
            int d;
        } u;
        char f[4];
    } u;
    struct
    {
        // double a;
        int b;
        union
        {
            struct
            {
                int x, y;
            } aa;
            struct
            {
                int xx;
            } bb;
        };

    } ua;
    printf("%lu %lu %lu\n", sizeof s, sizeof u, sizeof ua);
    printf("%p %p %p\n", &s.a, &s.e, &s.f);
    ua.bb.xx = 12;

    struct pinball_machine
    {
        char name[40];
        int year;
        enum
        {
            EM,
            SS
        } type;
        int players;
    };
    struct pinball_machine mmc;
    mmc.type = SS;
    enum
    {
        ENQ = 37,
        ACK,
        BEL,
        LF = 37,
        ETB,
        ESC
    };
    printf("%d %d %d\n", BEL, ETB, ESC);
    return 0;
}
struct complex make_complex(double real, double imaginary)
{
    return (struct complex){real, imaginary};
}
struct complex add_complex(struct complex a, struct complex b)
{
    return (struct complex){a.real + b.real, a.imaginary + b.imaginary};
}

Complex make_complex2(double real, double imaginary)
{
    return (Complex){real, imaginary};
}
Complex add_complex3(Complex a, Complex b)
{
    return (Complex){a.real + b.real, a.imaginary + b.imaginary};
}

struct date
{
    int month, day, year;
};

int day_of_year(struct date d)
{
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0)
    {
        month[1] = 29;
    }
    int day = d.day;
    for (int i = 0; i < d.month - 1; i++)
    {
        day += month[i];
    }
    return day;
}
int compare_dates(struct date d1, struct date d2)
{
    if (d1.year - d2.year != 0)
    {
        return d1.year < d2.year ? -1 : 1;
    }
    if (d1.month - d2.month != 0)
    {
        return d1.month < d2.month ? -1 : 1;
    }
    if (d1.day - d2.day != 0)
    {
        return d1.day < d2.day ? -1 : 1;
    }
    return 0;
}

struct time
{
    int hours, minutes, seconds;
};
struct time split_time(int total_seconds)
{
    return (struct time){total_seconds / 3600, total_seconds % 3600 / 60, total_seconds % 60};
}

struct fraction
{
    int numerator, denominator; // 分子 分母
};

int gcd(struct fraction f)
{
    int temp = 0;
    for (; f.denominator != 0;)
    {
        temp = f.numerator % f.denominator;
        f.numerator = f.denominator;
        f.denominator = temp;
    }
    return f.numerator;
}
struct fraction func_16_7_1(struct fraction f)
{
    int g = gcd(f);
    f.numerator /= g;
    f.denominator /= g;
    return f;
}
// 相加
struct fraction func_16_7_2(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;
    return func_16_7_1(f);
}
// 相减
struct fraction func_16_7_3(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;
    return func_16_7_1(f);
}
// mul
struct fraction func_16_7_4(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.numerator;
    f.denominator = f1.denominator * f2.denominator;
    return func_16_7_1(f);
}
// div
struct fraction func_16_7_5(struct fraction f1, struct fraction f2)
{
    struct fraction f;
    f.numerator = f1.numerator * f2.denominator;
    f.denominator = f1.denominator * f2.numerator;
    return func_16_7_1(f);
}
struct color
{
    int red;
    int green;
    int blue;
};
void func_16_8()
{

    const struct color MAGENTA = {255, 0, 255};
    const struct color MAGENTA99 = {.red = 255, .blue = 255};
}
struct color func_16_9_1_make_color(int red, int green, int blue)
{
    red = red < 0 ? 0 : red;
    green = green < 0 ? 0 : green;
    blue = blue < 0 ? 0 : blue;
    red = red > 255 ? 255 : red;
    green = green > 255 ? 255 : green;
    blue = blue > 255 ? 255 : blue;
    return (struct color){red, green, blue};
}

int func_16_9_2_getRed(struct color c)
{
    return c.red;
}
bool func_16_9_3_equal_color(struct color color1, struct color color2)
{
    return (bool)(color1.red == color2.red && color1.green == color2.green && color1.blue == color2.blue);
}
struct color func_16_9_4_brighter(struct color c)
{
    if (c.red == 0 && c.green == 0 && c.blue == 0)
    {
        return (struct color){3, 3, 3};
    }
    c.red = c.red < 3 && c.red > 0 ? 3 : c.red;
    c.green = c.green < 3 && c.green > 0 ? 3 : c.green;
    c.blue = c.blue < 3 && c.blue > 0 ? 3 : c.blue;
    c.red = (int)(c.red / 0.7);
    c.green = (int)(c.green / 0.7);
    c.blue = (int)(c.blue / 0.7);
    c.red = c.red > 255 ? 255 : c.red;
    c.green = c.green > 255 ? 255 : c.green;
    c.blue = c.blue > 255 ? 255 : c.blue;
    return c;
}
struct color func_16_9_5_darker(struct color c)
{
    c.red = (int)(c.red * 0.7);
    c.green = (int)(c.green * 0.7);
    c.blue = (int)(c.blue * 0.7);
    return c;
}

struct point
{
    int x, y;
};
struct rectangele
{
    struct point upper_left, lower_right;
};
int func_16_10_1_area(struct rectangele r)
{
    return abs(r.lower_right.x - r.upper_left.x) * (r.lower_right.y - r.upper_left.y);
}
struct point func_16_10_2_middle(struct rectangele r)
{
    return (struct point){(r.lower_right.x + r.upper_left.x) / 2, (r.lower_right.y + r.upper_left.y) / 2};
}
struct rectangele func_16_10_3_move(struct rectangele r, int x, int y)
{
    r.lower_right.x += x;
    r.lower_right.y += y;
    r.upper_left.x += x;
    r.upper_left.y += y;
    return r;
}
bool func_16_10_4_include(struct rectangele r, struct point p)
{
    return p.x <= r.lower_right.x && p.x >= r.upper_left.x && p.y <= r.upper_left.y && p.y >= r.lower_right.y;
}