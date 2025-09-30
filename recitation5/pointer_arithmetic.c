#include <stdio.h>

int main(int argc, char const *argv[])
{

    // 1D Pointer Arithmetic
    int arr[5];
    int *p = &arr;

    printf("%p == %p\n", arr + 5, &arr[5]);
    printf("%p == %p\n", arr + 3, &arr[3]);
    printf("%p == %p\n", arr + 1, &arr[1]);
    printf("%p == %p\n", arr + 0, &arr[0]);

    // 2D Pointer Arithmetic

    int arr2d[5][5];
    int *p2d = &arr2d;
    // It is wrong to declare a pointer to a 2d array like this
    // This means a pointer to a pointer that points to an integer
    // int **p2d = &arr2d;

    // another overrun example
    printf("Overrun Ex: %p == %p\n", *(arr2d + 0) + 5, &arr2d[0][5]);
    printf("Overrun Ex: %p == %p\n", *(arr2d + 1) + 0, &arr2d[1][0]);

    printf("%p == %p\n", *(arr2d + 3) + 2, &arr2d[3][2]);
    printf("%p == %p\n", *(arr2d + 2) + 1, &arr2d[2][1]);

    return 0;
}
