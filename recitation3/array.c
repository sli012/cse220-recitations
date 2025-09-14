#include <stdio.h>

unsigned int array_len(int arr[5]) // arr will decay to int*
{
    // Why does this return 2?
    return sizeof(arr) / sizeof(arr[0]);
}

int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
        printf("i: %d addr: %p\n", i, &arr[i]); // Why are the addresses 4 bytes apart?


    // Pointer Arithmetic 
    // Because you know that arrays contains elements of the same size
    // the element at index 1 is just the starting address of the array + sizeof(arr_datatype) * index
    printf("The address at index 1 is %p, %p\n", &arr[1], (arr + 1));

    printf("The number of elements in the array is: %ld\n", sizeof(arr) / sizeof(arr[0]));

    printf("The number of elements in the array using array_len is: %d\n", array_len(arr));

    return 0;
}
