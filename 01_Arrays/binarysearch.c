#include <stdio.h>
int BinarySearch(int arr[], int size, int element)
{
    int low, mid, high;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == element)
        {
            return mid;
        }
        if (arr[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
} 

int main()
{
    //index of elements= 0,  1,  2,  3,   4,  5,   6,   7,   8,   9,  10,  11, 12, 13,
         int arr[100] = {12, 40, 58, 81, 95, 123, 145};
    int element = 12;
    int size = sizeof(arr) / sizeof(int);

    int SearchIndex = BinarySearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, SearchIndex);
    // printf((BinarySearch==-1)?"Element not found":"The element %d was found at index %d \n", element, SearchIndex);
    return 0;
}