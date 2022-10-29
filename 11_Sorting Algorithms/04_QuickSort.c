#include <stdio.h>

void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;
    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }

    } while (i < j);
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void QuickSort(int a[], int low, int high)
{

    int partitionIndex;
    if (low < high)
    {
        PrintArray(a, 10);
        partitionIndex = partition(a, low, high);
        QuickSort(a, low, partitionIndex - 1);
        QuickSort(a, partitionIndex + 1, high);
    }
}
int main()
{
    int a[] = {10, 2, 5, 9, 6, 3, 1, 8, 4, 7};
    int n = 10;
    PrintArray(a, n);
    printf("Performing QuickSort.....\n");
    QuickSort(a, 0, n - 1);
    PrintArray(a, n);
    return 0;
}