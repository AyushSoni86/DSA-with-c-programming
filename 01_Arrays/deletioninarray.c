#include <stdio.h>

//*****CODE FOR TRAVERSAL********

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//*********CODE FOR DELETION OF ELEMENT IN AN ARRAY*************

void IndexDelete(int arr[], int size, int index)
{

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}

int main()
{
    //array index - 0   1   2   3   4
    int arr[100] = {56, 24, 98, 12, 89};
    int size = 5, element = 10, index = 1;
    display(arr, size);
    IndexDelete(arr, size, index);

    size -= 1;
    display(arr, size);
    return 0;
}