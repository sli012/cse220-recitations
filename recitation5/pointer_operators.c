int main(int argc, char const *argv[])
{
    int number = 5;
    int *p = &number; // The & operator is the "address of" operator

    // The * operator is overloaded in C so it has many meanings
    // When you *ptr you "deference" the pointer and read the value at the address
    printf("The value at address %p is %d", p, *p);

    return 0;
}
