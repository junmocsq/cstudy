#include <stdio.h>

void func_11_1();
void func_11_3();
void func_11_4();
void func_11_5();
void func_11_6();
void func_11_7();
void func_11_8();

void func_p_11_1();
void func_p_11_2();
void func_p_11_3();
void func_p_11_4();

// gcc exercise11.c && ./a.out
int main()
{
    func_11_1();
    func_11_3();
    func_11_4();
    func_11_5();
    func_11_6();
    func_11_7();
    func_11_8();

    func_p_11_1();
    func_p_11_2();
    func_p_11_3();
    func_p_11_4();
    return 0;
}

void func_11_1()
{
    int arr[3] = {1, 10, 100};
    int *p = arr;
    printf("%d\n", *p);
    printf("%d\n", *p++);
    printf("%d\n", *p);
    return;
}

void avg_sum(double a[], int n, double *avg, double *sum)
{
    int i;
    *sum = 0;
    for (i = 0; i < n; i++)
        *sum += a[i];
    *avg = *sum / n;
}
void func_11_3()
{
    double arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double sum, avg;
    avg_sum(arr, 10, &avg, &sum);
    printf("avg:%lf sum:%lf\n", avg, sum);
}
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void func_11_4()
{
    int p = 1, q = 2;
    printf("p:%d q:%d\n", p, q);
    swap(&p, &q);
    printf("p:%d q:%d\n", p, q);
}
void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / 3600;
    *min = total_sec % 3600 / 60;
    *sec = total_sec % 60;
}
void func_11_5()
{
    int hr, min, sec;
    split_time(34567, &hr, &min, &sec);
    printf("%.2d:%.2d:%.2d\n", hr, min, sec);
}
void find_two_largest(int a[], int n, int *largest, int *second_largest)
{
    if (n < 2)
    {
        return;
    }
    else
    {
        if (a[0] > a[1])
        {
            *largest = a[0];
            *second_largest = a[1];
        }
        else
        {
            *largest = a[1];
            *second_largest = a[0];
        }
    }
    for (int j = 2; j < n; j++)
    {
        if (a[j] >= *largest)
        {
            *second_largest = *largest;
            *largest = a[j];
        }
        else if (a[j] > *second_largest)
        {
            *second_largest = a[j];
        }
    }
}
void func_11_6()
{
    int largest, second_largest;
    find_two_largest((int[]){1, 99, 2, 3, 22, 343, 323, 23423, 21121, 11}, 10, &largest, &second_largest);
    printf("largest:%d ,second_largest:%d\n", largest, second_largest);
}

void split_date(int day_of_year, int year, int *month, int *day)
{
    int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // 四年一闰；百年不闰，四百年再闰
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        monthDay[1] = 29;
    }
    *month = 1;
    int sum = 0;
    for (; *month < 13;)
    {
        sum += monthDay[*month - 1];
        if (day_of_year < sum)
        {
            break;
        }
        ++*month;
    }
    *day = day_of_year - sum + monthDay[*month - 1];
}
void func_11_7()
{
    int month, day;
    split_date(278, 2000, &month, &day);
    printf("%.2d-%.2d\n", month, day);
}

int *find_largest(int a[], int n)
{
    int i;
    int max = 0;
    for (i = 0; i < n; i++)
    {
        if (a[max] < a[i])
            max = i;
    }
    return &a[max];
}
void func_11_8()
{
    int *largest;
    largest = find_largest((int[]){1, 99, 2, 3, 22, 343, 323, 23423, 21121, 11}, 10);
    printf("largest:%d\n", *largest);
}

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{

    *twenties = dollars / 20;
    dollars %= 20;

    *tens = dollars / 10;
    dollars %= 10;

    *fives = dollars / 5;
    dollars %= 5;

    *ones = dollars;
    return;
}
void func_p_11_1()
{
    int twenties, tens, fives, ones;
    int dollars = 0.0f;
    printf("Enter a dollar amount: ");
    scanf("%d", &dollars);
    pay_amount(dollars, &twenties, &tens, &fives, &ones);
    printf("$20 bills: %d\n$10 bills: %d\n $5 bills: %d\n $1 bills: %d\n",
           twenties, tens, fives, ones);
    return;
}

void find_Closest_flight(int desired_time, int *departure_time, int *arrival_time)
{
    int start[] = {8 * 60, 9 * 60 + 43, 11 * 60 + 19, 12 * 60 + 47, 14 * 60, 15 * 60 + 45, 19 * 60, 21 * 60 + 45};
    int end[] = {10 * 60 + 16, 11 * 60 + 52, 13 * 60 + 31, 15 * 60, 16 * 60 + 8, 17 * 60 + 55, 21 * 60 + 20, 23 * 60 + 58};

    printf("Closest departure time is ");
    *departure_time = start[0];
    *arrival_time = end[0];
    for (int i = 0; i < (int)(sizeof(start) / sizeof(start[0])); i++)
    {
        if (desired_time <= start[i])
        {
            *departure_time = start[i];
            *arrival_time = end[i];
            break;
        }
    }
}
void func_p_11_2()
{
    int hour, minute;
    printf("Enter a 24-hour time(xx:xx): ");
    scanf("%d :%d", &hour, &minute);
    int desired_time = hour * 60 + minute;

    int departure_time, arrival_time;
    find_Closest_flight(desired_time, &departure_time, &arrival_time);
    if (departure_time < 12 * 60)
        printf("%.2d:%.2d a.m., arriving at ", departure_time / 60, departure_time % 60);
    else
        printf("%.2d:%.2d p.m., arriving at ", departure_time / 60 - 12, departure_time % 60);
    if (arrival_time < 12 * 60)
        printf("%.2d:%.2d a.m. \n", arrival_time / 60, arrival_time % 60);
    else
        printf("%.2d:%.2d p.m. \n", arrival_time / 60 - 12, arrival_time % 60);
}

void reduce(int numerator, int denominator, int *reduce_numerator, int *reduce_denominator)
{

    *reduce_numerator = numerator;
    *reduce_denominator = denominator;
    int temp;
    while (denominator != 0)
    {
        temp = numerator % denominator;
        numerator = denominator;
        denominator = temp;
    }

    *reduce_numerator /= numerator;
    *reduce_denominator /= numerator;
}
void func_p_11_3()
{
    printf("Enter a fraction (a/b): ");
    int a, b, c, d;
    scanf("%d /%d", &a, &b);
    reduce(a, b, &c, &d);
    printf("In lowest terms: %d/%d\n", c, d);
}
void func_p_11_4() {}