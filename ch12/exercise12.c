#include <stdio.h>
#include <stdbool.h>

void func_12_1();
void func_12_6();
void func_12_7();
void func_12_8();
void func_12_9();
void func_12_12();
void func_12_13();
int main(void)
{
    func_12_1();
    func_12_6();
    func_12_7();
    func_12_8();
    func_12_9();
    func_12_12();
    func_12_13();
    return 0;
}
void func_12_1()
{
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];
    printf("%d %d %ld %d %d\n", *(p + 3), *(q - 3), q - p, p < q, *p < *q);
}

int sum_array(const int a[], int n)
{
    const int *p = a;
    int sum = 0;
    for (; p < a + n; ++p)
    {
        sum += *p;
    }
    return sum;
}
void func_12_6()
{
    printf("%d\n", sum_array((int[]){1, 2, 3, 4, 5, 6}, 6));
}

bool search(const int a[], int n, int key)
{
    bool result = false;
    const int *p = a;
    for (; p < a + n; ++p)
    {
        if (*p == key)
        {
            result = true;
            break;
        }
    }
    return result;
}
void func_12_7()
{
    printf("search:%d\n", search((int[]){1, 2, 3, 4, 5, 6}, 6, 5));
}

void store_zeros(int a[], int n)
{
    int *p;
    for (p = a; p < a + n;)
    {
        *p++ = 0;
    }
}
void func_12_8()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    store_zeros(a, 6);
    printf("%d %d\n", a[0], a[5]);
}

double inner_product(const double *a, const double *b, int n)
{
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        result += *a++ * *b++;
    }
    return result;
}

void func_12_9()
{
    double a[] = {1, 2, 3, 4, 5, 6};
    double b[] = {1, 2, 3, 4, 5, 6};

    printf("%lf\n", inner_product(a, b, 6));
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    if (*a > *(a + 1))
    {
        *largest = *a;
        *second_largest = *(a + 1);
    }
    else
    {
        *largest = *(a + 1);
        *second_largest = *a;
    }
    a = a + 2;
    for (int i = 2; i < n; i++)
    {
        if (*a > *largest)
        {
            *second_largest = *largest;
            *largest = *a;
        }
        else if (*a > *second_largest)
        {
            *second_largest = *a;
        }
        a++;
    }
}
void func_12_12()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int b, c;
    find_two_largest(a, 6, &b, &c);
    printf("%d %d\n", b, c);
}

void init_martix(int a[][10], int n)
{
    int *p;
    int flag = 0;
    for (p = a[0]; p < a[0] + n * n;)
    {
        if (flag == 0)
        {
            *p++ = 1;
            flag++;
        }
        else
        {
            *p++ = 0;
            if (flag++ == n)
            {
                flag = 0;
            }
        }
        }
}
void func_12_13()
{
    int a[10][10] = {0};
    init_martix(a, 10);
    int *p;
    for (int i = 0; i < 10; i++)
    {
        for (p = a[i]; p < a[i] + 10;)
        {
            printf("%d ", *p++);
        }
        printf("\n");
    }
}