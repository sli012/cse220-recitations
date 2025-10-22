#include <stdio.h>
#include <string.h>

struct Person //one way to declare struct
{
    char name[50];
    int age; 
}; // What is the size of this struct?

typedef struct //2nd way
{
    char name[50];
    int age;
} Person; // Same thing, but u can now use Person instead of struct Person

int main()
{
    Person p1; //uses first way
    Person p2; //uses second way so you don't need struct keyword when declaring

    strcpy(p1.name, "Alice");
    p1.age = 30;

    p2 = p1; // Structs are COPY on ASSIGNMENT. They look the same but do not reference the same object in memory.

    printf("Name: %s\nAge: %d\n", p1.name, p1.age);
    printf("Name: %s\nAge: %d\n", p2.name, p2.age);
    printf("%p == %p\n", &p1, &p2); //adresses are different 

    p2.age = 20;

    printf("Age of P1 after changing P2.age: %d\n", p1.age); //p1 is still the same becuase you are not changing p1

    // To reference p1 and make changes presist

    struct Person *p3 = &p1;

    p3->age = 10; // This syntax is equivalent to (*p3).age

    printf("Age of P1 after changing P3.age: %d\n", p1.age);

    return 0;
}

/**
byte order goes from biggest elem to least

Struct a{
 int ;   int is biggest, struct order: [4 " " " | i i i i | s s " "] 12 total bytes
 short;       padding: " " " " and there are 4 bytes each  so the first 4 bytes don't look like an int and to not cross byte border
                short take up 2 bytes and char takes up 1 bytes
 declaring integer after character
}

struct b{
    [i i i i | s s c "] 8 bytes this is better


}

*/
