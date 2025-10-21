#include <stdio.h>

union Data
{
    int i;
    float f;
    char str[20];
};

int main()
{
    union Data data;

    printf("sizeof: %ld\n", sizeof(data));

    data.i = 10;
    printf("data.i = %d\n", data.i);

    data.f = 220.5;
    printf("data.f = %.2f\n", data.f);

    // Writing to one field overwrites others
    // because they share memory
    sprintf(data.str, "Hello");
    printf("data.str = %s\n", data.str);

    printf("data.i = %d\n", data.i);

    return 0;
}
