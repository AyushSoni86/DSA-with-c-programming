#include <stdio.h>
void DisplayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void reverse(int arr[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void LeftRotateByD(int arr[], int d, int n)
{

    if (d == 0)
        return;
    // in case the rotating factor is
    // greater than array length
    d = d % n;

    reverse(arr, 0, d - 1);
    reverse(arr, d, n - 1);
    reverse(arr, 0, n - 1);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    DisplayArray(arr, 6);
    LeftRotateByD(arr, 2, 6);
    printf("\nAfter rotation\n");
    DisplayArray(arr, 6);
    return 0;
}