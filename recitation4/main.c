#include <stdio.h>

// There can only be one main function in a C program

int main(int argc, char *argv[])
{

    printf("The number of args is: %d\n", argc);

    for (int i = 0; i < argc; i++)
    {
        printf("The arg is %s\n", argv[i]);
    }

    return 0;
}