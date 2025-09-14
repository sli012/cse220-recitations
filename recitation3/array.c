#include <stdio.h>

unsigned int array_len(int arr[5]) // This will decay to int*
{
    // Why does this return 2?
    return sizeof(arr) / sizeof(arr[0]);
}


int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};

    printf("The number of elements in the array is: %ld\n", sizeof(arr) / sizeof(arr[0]));

    printf("The number of elements in the array using array_len is: %d\n", array_len(arr));

    return 0;
}
