#include <stdio.h>
void swap(int arr[], int i, int j);
int divide(int arr[], int l, int r);
int divide2(int arr[], int l, int r);
void quick(int arr[], int l, int r);

// cc quick.c&& ./a.out
int main()
{
    int arr[10] = {12, 3, 6, 18, 7, 15, 10, 1, 88, 9};
    quick(arr, 0, 9);
    // swap(arr,0,9);
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

void swap(int arr[], int i, int j)
{
    if (arr[i] == arr[j]) // 相同的值异或为0
    {
        return;
    }
    arr[i] ^= arr[j];
    arr[j] ^= arr[i];
    arr[i] ^= arr[j];
}
void quick(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    int i = divide2(arr, l, r);
    return;
    quick(arr, l, i - 1);
    quick(arr, i + 1, r);
}
int divide(int arr[], int l, int r)
{

    int i = l + 1, j = r;
    for (; i <= j;)
    {
        if (arr[j] > arr[l]) // 保证(j,r]为大于 arr[l]的数组元素
        {
            --j;
        }
        else
        {
            swap(arr, i, j);
            ++i;
        }
    }

    swap(arr, l, j);
    return j;
}
int divide2(int arr[], int l, int r)
{

    int i = l, j = l;
    // [l,i) 小于arr[r]
    // [i,j) 大于等于arr[r]
    for (; j < r;)
    {
        if (arr[j] < arr[r])
        {
            swap(arr, i, j);
            ++i;
        }
        ++j;
    }

    swap(arr, r, i);
    return i;
}
