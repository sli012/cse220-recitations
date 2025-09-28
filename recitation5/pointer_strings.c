#include <stdio.h>

int main()
{
    char *strings[] = {"Apple", "Banana", "Pear"};

    printf("%p -> %p -> %s \n", strings, *strings, *strings);
    printf("%p -> %p -> %s \n", (strings + 1), *(strings + 1), *(strings + 1));
    printf("%p -> %p -> %s \n", (strings + 2), *(strings + 2), *(strings + 2));

    return 0;
}
