#include <stdio.h>

int str_len(char *str)
{
    int count = 0;
    // This while loop keep going if the current character is not '\0'
    // Reminder: '\0' has a value of 0 and 0 is false
    while (*str++)
        count++;
    return count;
}

int main(int argc, char const *argv[])
{
    printf("%d\n", str_len("hi"));
    return 0;
}
