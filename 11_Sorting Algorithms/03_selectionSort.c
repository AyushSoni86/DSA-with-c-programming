#include <stdio.h>

void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

void SelectionSort(int *a, int n)
{
    printf("Running selection sort.....\n");
    int indexofMin, temp;
    for (int i = 0; i < n - 1; i++)
    {
        indexofMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[indexofMin])
            {
                indexofMin = j;
            }
            temp = a[i];
            a[i] = a[indexofMin];
            a[indexofMin] = temp;
        }
    }
}
int main()
{
    //  00  01  02  03  04  05  06  07  08  09 ---->index of array
    //  32, 01, 54, 12, 56, 23, 78, 54, 90, 11 ----> input array
    int a[] = {32, 1, 54, 12, 56, 23, 78, 54, 90, 11};
    int n = 10;
    PrintArray(a, n);
    SelectionSort(a, n);
    PrintArray(a, n);
    return 0;
}