#include "sf_math.h"
#include "sf_science.h" // <- Circular import of sf_math.h in sf_science.h

// Define the add function to fix the compilation error
int add(int x, int y) {
    return x + y;
}

int main(int argc, char const *argv[])
{
    int sum = add(1, 2);
    printf("Your program compiled and the ouput is: %d\n", sum);
    return 0;
}
