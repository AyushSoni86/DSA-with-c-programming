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

//*********CODE FOR INSERTION OF ELEMENT IN AN ARRAY*************

int IndexInsert(int arr[], int size, int element, int capacity, int index)
{
    if (size >= capacity)
    {
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main()
{
    //array index - 0   1   2   3   4
    int arr[100] = {56, 24, 98, 12, 89};
    int size = 5, element = 10, index = 1;
    display(arr, size);
    IndexInsert(arr, size, element, 100, index);

    size += 1;
    display(arr, size);
    return 0;
}