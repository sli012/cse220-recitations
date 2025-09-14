#include <stdio.h>

int main(int argc, char const *argv[])
{

    unsigned char c = 0b10111111;

    // Printing all bits of C by performing a right shift and masking the rightmost bit
    // We need to multiply by 8 here because sizeof(c) is in bytes not bits
    for (int i = 0; i < sizeof(c) * 8; i++)
        printf("%d\n", (c >> i) & 0b1);

    // Say you want to print a pair at once
    for (int i = 0; i < sizeof(c) * 8; i += 2)
        // Remember your parentheses!
        // ((c >> i) & 2) >> 1 and (c >> i) & 2 >> 1 are very different
        printf("%d %d \n", (c >> i) & 0b1, ((c >> i) & 0b10) >> 1);

    return 0;
}
