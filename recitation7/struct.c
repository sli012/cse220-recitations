#include <stdio.h>
#include <string.h>

struct Person
{
    char name[50];
    int age;
}; // What is the size of this struct?

typedef struct
{
    char name[50];
    int age;
} Person; // Same thing, but u can now use Person instead of struct Person

int main()
{
    struct Person p1;
    struct Person p2;

    strcpy(p1.name, "Alice");
    p1.age = 30;

    p2 = p1; // Structs are COPY on ASSIGNMENT. They look the same but do not reference the same object in memory.

    printf("Name: %s\nAge: %d\n", p1.name, p1.age);
    printf("Name: %s\nAge: %d\n", p2.name, p2.age);
    printf("%p == %p\n", &p1, &p2);

    p2.age = 20;

    printf("Age of P1 after changing P2.age: %d\n", p1.age);

    // To reference p1 and make changes presist

    struct Person *p3 = &p1;

    p3->age = 10; // This syntax is equivalent to (*p3).age

    printf("Age of P1 after changing P3.age: %d\n", p1.age);

    return 0;
}
