#include <stdio.h>

void PrintArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", A[i]);
    }
    printf("\n");
}

void BubbleSort(int *A, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++) // this loop for number of passes
    {
        for (int j = 0; j < n - 1 - i; j++) // this loop for number of swaps
        {
            if (A[j] > A[j + 1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
}
int main()
{
    int A[] = {11, 23, 56, 54, 32, 98, 65, 234, 1, 12, 34};
    int n = 11;
    printf("Array before Sorting\n");
    PrintArray(A, n);
    BubbleSort(A, n);
    printf("Array after Sorting\n");
    PrintArray(A, n);
    return 0;
}