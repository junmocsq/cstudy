#include <stdio.h>
void func_3_1();
void func_p_3_1();
void func_p_3_2();
void func_p_3_3();
void func_p_3_4();
void func_p_3_5();
void func_p_3_6();

// gcc exercise03.c && ./a.out
int main()
{
    func_3_1();
    func_p_3_1();
    func_p_3_2();
    func_p_3_3();
    func_p_3_4();
    func_p_3_5();
    func_p_3_6();
    return 0;
}

void func_3_1()
{
    printf("%6d,%4d\n", 86, 1040);   // ....86,1040
    printf("%12.5e\n", 30.253);      // .3.02530e+01
    printf("%.4f\n", 83.162);        // 83.1620
    printf("%-6.2g\n", .0000009979); // 1e-6
    // int i, j, k;
    // scanf("%d-%d-%d", &i, &j, &k);
    // printf("%d %d %d\n", i, j, k);

    // scanf("%d, -%d -%d", &i, &j, &k);
    // printf("%d, %d %d\n", i, j, k);
}

void func_p_3_1()
{
    int m, d, y;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);
    printf("Your entered the date %.4d%.2d%.2d\n", y, m, d);
}

void func_p_3_2()
{
    int num, m, d, y;
    float price;

    printf("Enter item number: ");
    scanf("%d", &num);
    printf("Enter unit price: ");
    scanf("%f", &price);
    printf("Enter purchase date: (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);
    printf("%-20s%-20s%s\n", "Item", "Unit", "Purchase");
    printf("%-20s%-20s%s\n", "", "Price", "Date");
    printf("%-20d$%10.2f%9s%.2d/%.2d/%.4d\n", num, price, "", m, d, y);
    /*
    Enter item number: 583
    Enter unit price: 13.5
    Enter purchase date: (mm/dd/yyyy): 10/24/2021
    Item                Unit                Purchase
                        Price               Date
    583                 $     13.50         10/24/2021
    */
}

void func_p_3_3()
{
    int a1, a2, a3, a4, a5;
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &a1, &a2, &a3, &a4, &a5);
    printf("GS1 prefix: %d\nGroup identifier: %d\nPublisher code: %d\nItem number: %d\nCheck digit: %d\n",
           a1, a2, a3, a4, a5);
    /*
    Enter ISBN: 978-0-393-97950-3
    GS1 prefix: 978
    Group identifier: 0
    Publisher code: 393
    Item number: 97950
    Check digit: 3
    */
}

void func_p_3_4()
{
    int a1, a2, a3;
    printf("Enter iphone number [(xxx) xxx-xxxx]: ");
    scanf("(%d)%d-%d", &a1, &a2, &a3);
    printf("Your entered %.3d.%.3d.%.4d\n",
           a1, a2, a3);
    // Enter iphone number [(xxx) xxx-xxxx]: (404) 817-6900
    // Your entered 404.817.6900
}

void func_p_3_5()
{
    int arr[16];
    int rows[4];
    int colums[4];
    int diagonal[2];
    printf("Enter the numbers from 1 to 16 in any order: \n");
    int temp;
    for (int i = 0; i < 16; i++)
    {
        scanf("%d", &temp);
        arr[i] = temp;
        if (i > 0 && i % 4 == 0)
        {
            printf("\n");
        }
        printf("%-5d", temp);
    }
    printf("\n");

    for (int i = 0; i < 16; i++)
    {
        if (i % 4 == 0)
        {
            rows[i / 4] = 0;
        }
        rows[i / 4] += arr[i];
    }

    for (int i = 0; i < 16; i++)
    {
        if (i < 4)
        {
            colums[i] = arr[i];
        }
        else
        {
            colums[i % 4] += arr[i];
        }
    }
    diagonal[0] = 0;
    diagonal[1] = 0;
    for (int i = 0; i < 16; i++)
    {
        if (i % 5 == 0)
        {
            diagonal[0] += arr[i];
        }
        else if (i >= 3 && i <= 12 && i % 3 == 0)
        {
            diagonal[1] += arr[i];
        }
    }

    printf("Row sums: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%4d", rows[i]);
    }
    printf("\nColum sums: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%4d", colums[i]);
    }
    printf("\nDiagonal sums: ");
    for (int i = 0; i < 2; i++)
    {
        printf("%4d", diagonal[i]);
    }
    printf("\n");

    // output:
    /*
    Enter the numbers from 1 to 16 in any order:         
    16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
    16   3    2    13   
    5    10   11   8    
    9    6    7    12   
    4    15   14   1    
    Row sums:   34  34  34  34
    Colum sums:   34  34  34  34
    Diagonal sums:   34  34
    */
}

void func_p_3_6()
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    printf("Enter two fractions separated by a plus sign: ");
    scanf("%d/%d+%d/%d", &num1, &denom1, &num2, &denom2);

    result_num = num1 * denom2 + num2 * denom1;
    result_denom = denom1 * denom2;
    printf("The sum is %d/%d\n", result_num, result_denom);

    // Enter two fractions separated by a plus sign: 5/6+3/4
    // The sum is 38/24
}