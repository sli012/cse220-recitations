int main(int argc, char const *argv[])
{
    int number = 5;
    int *p = &number; // The & operator is the "address of" operator

    // The * operator is overloaded in C so it has many meanings
    // When you *ptr you "deference" the pointer and read the value at the address
    printf("The value at address %p is %d\n", p, *p);

    int nums[] = {1, 2, 3, 4, 5};

    int *ptr = &nums;

    printf("Post Increment: %d\n", *ptr++); //reads value at then pointer then move forward by 1
    printf("Pre Increment: %d\n", *++ptr); // What is the output of this? morve ptr forward by 1 then read the value

    //ptr++: 1
    //++ptr: prints 3 
    return 0;
}
