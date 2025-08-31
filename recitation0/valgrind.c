#include <stdlib.h>
#include <stdio.h>
#include "r0.h"

int main()
{

    // 1. allocated but never freed
    int *arr = malloc(5 * sizeof(int)); 
    int sum = 0;

    // 2. Out of bound write
    arr[5] = 10; 

    // 3. Out of bound read
    printf("Value: %d\n", arr[5]); 

    // 4. Use of uninitialized memory

    for (int i = 0; i < 5; i++)
    {
        sum += arr[i];
    }

    // Notice how sum is different every time this is ran?
    // This relies on the compiler and the operating system
    // Never rely on malloc'd memory to be all 0s
    printf("Sum: %d\n", sum); 

    // 5. Invalid free, this is trying to free a[1]
    free(arr + 1);
    return 0;
}
