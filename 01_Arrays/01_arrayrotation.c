#include <stdio.h>
//void RotatebyOne(int arr[], int n);
void DisplayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

// Function to left Rotate arr[] of size n by 1
void RotatebyOne(int arr[], int n)
{
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
    {

        arr[i] = arr[i + 1];
    }
    arr[n - 1] = temp;
}

void LeftRotateByD(int arr[], int d, int n)
{
    for (int i = 0; i < d; i++)
    {
        RotatebyOne(arr, n);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    DisplayArray(arr, 6);
    printf("\nAfer rotation\n");
    LeftRotateByD(arr, 3, 6);
    DisplayArray(arr, 6);
    return 0;
}