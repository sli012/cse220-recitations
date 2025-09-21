#include <stdio.h>
#include <string.h>

// Capitialize every instance of a character
void str_cap(char *str, char chr)
{
    while (*str)
    {
        if (*str == chr)
        {
            // in ASCII, lowercase a-z is 97-122 and uppercase A-Z is 65-90
            if (*str >= 'a' && *str <= 'z')
                *str = *str - 32;
        }

        // move onto the next character
        str++;
    }
}

int main()
{
    // This don't work because this is immutable
    // char *string = "abcdefghijklmnopqrstuvwxyz";

    char string[] = "abcdefghijklmnopqrstuvwxyz";

    str_cap(string, 'a');

    printf("%s\n", string);

    return 0;
}
