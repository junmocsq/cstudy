#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void func_20_1();
void func_20_2();
void func_20_3();
void func_20_4();
void func_20_5();
void func_20_6();
void func_20_7();
void func_20_8();
void func_20_9();
void func_20_10();
void func_20_11();
void func_20_12();
void func_20_13();
void func_20_14();
void func_20_15();
void func_20_16();

void func_p_20_1();

// cc exercise20.c && ./a.out
// cc -S exercise20.c 
int main(void)
{
    func_20_1();
    func_20_2();
    func_20_3();
    func_20_4();
    func_20_5();
    func_20_6();
    func_20_7();
    func_20_8();
    func_20_9();
    func_20_10();
    func_20_11();
    func_20_12();
    func_20_13();
    func_20_14();
    func_20_15();
    func_20_16();

    func_p_20_1();
    return 0;
}

void func_20_1()
{
    unsigned short i, j, k;
    i = 8;
    j = 9;
    printf("%d %d\n", i >> (1 + j) >> 1, (i >> 1) + (j >> 1));
    i = 0;
    printf("%d\n", i & ~i);
    i = 2;
    j = 1;
    k = 0;
    printf("%d\n", ~i & j ^ k);
    i = 7;
    j = 8;
    k = 9;
    printf("%d\n", i ^ j & k);
}
void func_20_2()
{
    int i = 0b111111, j = 4, k;
    // 保留第j为的取反 ~(i & 1 << j) & 1<<j
    // 清除第j位：~(1 << j) & i
    printf("%x\n", ~(i & 1 << j) & 1 << j | ~(1 << j) & i);
}
void func_20_3() {}
#define MK_COLOR(RED, GREEN, BLUE) ((RED) << 16 | (GREEN) << 8 | (BLUE))
void func_20_4()
{
    long red = 0xfa;
    long green = 0xa5;
    long blue = 0x12;
    printf("%lx\n", MK_COLOR(red, green, blue));
}
#define GET_RED(COLOR) ((COLOR) >> 16 & 255)
#define GET_GREEN(COLOR) ((COLOR) >> 8 & 255)
#define GET_BLUE(COLOR) ((COLOR)&255)
void func_20_5()
{
    long red = 0xfa;
    long green = 0xa5;
    long blue = 0x12;
    long color = MK_COLOR(red, green, blue);
    printf("RED:%lx,GREEN:%lx,BLUE:%lx\n", GET_RED(color), GET_GREEN(color), GET_BLUE(color));
}
unsigned short swap_bytes(unsigned short i)
{
    return i >> 8 | i << 8;
}
void func_20_6()
{
    unsigned short i = 0xff12;
    printf("%x\n", swap_bytes(i));
}
unsigned int rotate_left(unsigned int i, int n)
{
    int size = (int)sizeof(unsigned int) * 8;
    return i >> (size - n) | i << n;
}
unsigned int rotate_right(unsigned int i, int n)
{
    int size = (int)sizeof(unsigned int) * 8;
    return i << (size - n) | i >> n;
}
void func_20_7()
{
    unsigned int i = 0x12345678;
    printf("%x %x %x\n", i, rotate_left(i, 8), rotate_right(i, 8));
}

void func_20_8() {}
int count_ones(unsigned char ch)
{
    int result = 0;
    while (ch > 0)
    {
        if (ch & 1)
            ++result;
        ch >>= 1;
    }
    return result;
}

int count_ones2(unsigned char ch)
{
    int result = 0;
    if (ch == 0)
    {
        return 0;
    }
    if (ch & 1)
    {
        ++result;
    }
    return result + count_ones2(ch >> 1);
}
void func_20_9()
{
    unsigned char ch = 0xff;
    printf("%d %d\n", count_ones(ch), count_ones2(ch));
}
unsigned int reverse_bits(unsigned int n)
{
    unsigned int l, r;
    for (int i = 0; i < 16; i++)
    {
        l = i;
        r = 31 - i;
        l = (1 << i & n) << (31 - 2 * i);
        r = (1 << (31 - i) & n) >> (31 - 2 * i);
        n &= ~(1 << i);
        n &= ~(1 << (31 - i));
        n |= l;
        n |= r;
    }
    return n;
}
void func_20_10()
{
    unsigned int i = 0xffff;
    printf("%x %x\n", i, reverse_bits(i));
}
void func_20_11()
{
#define SHIFT_BIT 1
#define CTRL_BIT 2
#define ALT_BIT 3
    unsigned char key_code = 8;
    if ((key_code & (SHIFT_BIT | CTRL_BIT | ALT_BIT)) == 0)
    {
        printf("No modifier keys passed.\n");
    }
}

unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{

    return (unsigned short)low_byte + ((unsigned short)high_byte << 8);
}

void func_20_12()
{
    printf("%x\n", create_short(0x12, 0x34));
}
int count_ints(unsigned int i)
{
    int result = 0;
    while (i > 0)
    {
        if (i & 1)
            ++result;
        i >>= 1;
    }
    return result;
}
void func_20_13()
{
    // n &= n-1; 每次消除一个1
    unsigned int n = 0xfff7faf0;
    for (; count_ints(n) > 0;)
    {
        printf("--- %d\n", count_ints(n));
        n &= n - 1;
    }
}
void func_20_14()
{
    struct float_define
    {
        unsigned int M : 23;
        unsigned int E : 8;
        unsigned int S : 1;
    };
    union mmtt
    {
        float i;
        struct float_define u;
    } u;

    float i = 18.625;
    u.i = i;
    printf("%x %d %x \n", u.u.S, u.u.E, u.u.M);
}
void func_20_15()
{
    struct
    {
        unsigned int flag : 1;
    } s;

    s.flag = 1;
    printf("%d\n", s.flag);
}
void func_20_16()
{
#define DWORD unsigned int
#define WORD unsigned short
#define BYTE unsigned char
    union
    {
        struct
        {
            DWORD eax, ebx, ecx, edx;
        } dword;
        struct
        {
            WORD ax, ah, bx, bh, cx, ch, dx, dh;
        } word;
        struct
        {
            BYTE al, ah, all, alh, bl, bh, bll, blh, cl, ch, cll, clh, dl, dh, dll, dlh;
        } byte;
    } regs;

    regs.dword.eax = 0x12345678;
    regs.dword.ecx = 0x87654321;
    printf("%x %x %x %x\n", regs.dword.eax, regs.word.ax, regs.byte.al, regs.byte.ah);
    printf("%x %x %x %x\n", regs.dword.ecx, regs.word.cx, regs.byte.cl, regs.byte.ch);
}

void func_p_20_1()
{
    struct float_define
    {
        unsigned int M : 23;
        unsigned int E : 8;
        unsigned int S : 1;
    };
    union mmtt
    {
        float i;
        struct float_define u;
    } u;
    u.u.S = 1;
    u.u.E = 128;
    u.u.M = 0;
    printf("%f\n", u.i); // -2.000000
}