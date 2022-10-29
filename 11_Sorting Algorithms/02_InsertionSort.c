#include <stdio.h>

void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

void insertionSort(int *a, int n)
{
    int key;
    int j;
    for (int i = 1; i <= n - 1; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}
int main()
{
    int a[] = {12, 143, 21, 134, 65, 212, 76, 43, 65, 123, 456, 653, 578, 431, 6, 3412, 7, 6543, 67, 563, 67, 7895, 54,634 , 56, 67, 462, 633, 642, 89};
    int n = 35;
    printf("Array before sorting\n");
    PrintArray(a, n);
    insertionSort(a, n);
    printf("Array after sorting\n");
    PrintArray(a, n);
    return 0;
}