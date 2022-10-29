#include <stdio.h>

void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

void BubbleSortAdaptive(int *a, int n)
{

    int temp;
    int IsSorted = 0;
    for (int i = 0; i < n - 1; i++) // this loop for number of passes
    {
        printf("Working on pass number %d \n", i + 1);
        IsSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // this loop for number of swaps
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                IsSorted = 0;
            }
        }
        if (IsSorted)
        {
            return;
        }
    }
}
int main()
{
    int a[] = {1, 2, 3, 4, 45, 67, 68, 89};
    int n = 8;
    printf("Array before sorting\n");
    PrintArray(a, n);
    BubbleSortAdaptive(a, n);
    printf("Array after sorting\n");
    PrintArray(a, n);
    return 0;
}