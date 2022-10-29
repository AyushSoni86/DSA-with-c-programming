#include <stdio.h>
int LinearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }return -1;
}
int main()
{
//index of elements= 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,   11, 12, 13,
    int arr[100] = {12, 40, 58, 81, 95, 23, 45, 64, 94, 65, 684, 6534, 98};
    int element = 684;
    int size = sizeof(arr) / sizeof(int);

    int SearchIndex = LinearSearch(arr, size, element);
    printf("The element %d was found at index %d \n", element, SearchIndex);
    return 0;
}