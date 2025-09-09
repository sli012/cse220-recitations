#include <stdio.h>

int main(void) {
    signed char a = 0xF0;      // -16 in two's complement
    unsigned char b = 0xF0;    // 240

    // Under the hood both a and b are stored as 11110000 (0xF0)

    // !! The (unsigned char) cast is for formatting reasons only
    printf("a       = %02x (%d)\n", (unsigned char)a, a);
    printf("b       = %02x (%u)\n", (unsigned char)b, b);

    // Since a is signed, the sign bit is extended when right shifted
    // 11110000 >> 1 -> 11111000 which is 0xf8

    // Since b is unsigned, zeroes are shifted in
    // 11110000 >> 1 -> 01111000 which is 0x78

    // This is why unsigned data types are preferred when doing bit manipulation. The sign bit extension from signed data types can mess things up!

    printf("a >> 1  = %02x (%d)\n", (unsigned char)(a >> 1), a >> 1);
    printf("b >> 1  = %02x (%u)\n", (unsigned char)(b >> 1), b >> 1);


    return 0;
}
