#include <stdio.h>

enum Day
{
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int main()
{
    enum Day today = WEDNESDAY;

    if (today == WEDNESDAY)
    {
        printf("It's Wednesday!\n");
    }

    printf("Day number: %d\n", today); // prints 2 (0-based)
    printf("Sizeof Day: %lu\n", sizeof(today));

    return 0;
}
