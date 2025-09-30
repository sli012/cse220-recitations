#include <stdio.h>

void swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void swap_byref(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(int argc, char const *argv[])
{

    int a = 11, b = 22;

    swap(a, b);

    printf("a = %d, b = %d\n", a, b);

    swap_byref(&a, &b);

    printf("a = %d, b = %d\n", a, b);

    return 0;
}
