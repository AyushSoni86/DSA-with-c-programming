#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void PrintArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", a[i]);
    }
    printf("\n");
}

int maximium(int a[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
        {
            max = a[i];
        }
    }
    return max;
}

void CountSort(int *a, int n)
{
    int i, j;

    //finding the maximum element in array a
    int max = maximium(a, n);

    //creating the count array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    //initialize all elements in count array to zero
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    //increment the corresponding index in array by one
    for (i = 0; i < n; i++)
    {
        count[a[i]] = count[a[i]] + 1;
    }
    i = 0; //counter for count array
    j = 0; //counter for given array

    while (i <= max)
    {
        if (count[i] > 0)
        {
            a[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[] = {10, 2, 5, 9, 6, 3, 1, 8, 4, 7};
    int n = 10;
    PrintArray(a, n);
    printf("Performing Count Sort........\n");
    CountSort(a, n);
    PrintArray(a, n);
    return 0;
}