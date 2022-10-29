#include <stdio.h>
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
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

    int size = 10; //size of used array

    int element = 10; //element to be inserted inside the array

    int index = 1; //elemetnt to be inserted on required index

    display(arr, size); // DISPLAYS OUR ARRAY

    IndexInsert(arr, size, element, 100, index); //INSERTION FUNCTION

    size += 1; //AFTER INSERTION INCEREASE THE SIZE OF ARRAY BY ONE

    if (IndexInsert(arr, size, element, 100, index) == 1)
    {
        display(arr, size);
        printf("\nInsertion done successfully\n");
    }
    else
    {
        printf("\nUsed size of array is greater than actual size of array! \nHence, insertion not done");
    }

    return 0;
}