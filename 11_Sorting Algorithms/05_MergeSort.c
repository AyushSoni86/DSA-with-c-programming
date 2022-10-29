#include <stdio.h>

void PrintArray(int *a, int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n\n");
}

void merge(int *a, int mid, int low, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int b[high + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void MergeSort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
      //  PrintArray(a, 10);
        mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}

int main()
{
    int a[] = {10, 2, 5, 9, 6, 3, 1, 8, 4, 7};
    int n = 10;
    PrintArray(a, n);
    printf("Performing Merge Sort........\n");
    MergeSort(a, 0, 9);
    PrintArray(a, n);
    return 0;
}