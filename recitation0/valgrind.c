#include <stdlib.h>
#include <stdio.h>
#include "r0.h"

// Fills a page of memory with garbage
int pollute() {
    size_t size = 4096;

    char *p = malloc(size);

    if (!p) return 1;

    memset(p, 0xAA, size);

    free(p);

    return 0;
}

int main()
{
    // This simulates normal system usage where this or other processeses may make memory dirty by writing to it.
    // Never assume that the Kernel will give you a clean page of memory.
    pollute();

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

    // Notice how sum is not 0?
    // Never rely on malloc'd memory to be all 0s
    printf("Sum: %d\n", sum); 

    // 5. Invalid free, this is trying to free a[1]
    free(arr + 1);
    return 0;
}
