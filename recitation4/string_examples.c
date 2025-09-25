#include <stdio.h>
#include <string.h>

int main()
{
    /* 1. Copying a string */
    char src[] = "Linux";
    char dest[50];
    strcpy(dest, src);
    printf("[1] Copied string: %s\n", dest);

    /* 2. Concatenating strings */
    char str1[50] = "Hello, ";
    char str2[] = "World!";
    strcat(str1, str2);
    printf("[2] Concatenated string: %s\n", str1);

    /* 3. Comparing strings */
    char a[] = "alpha";
    char b[] = "beta";
    if (strcmp(a, b) == 0)
        printf("[3] Strings are equal\n");
    else
        printf("[3] Strings are different\n");

    /* 4. Finding a substring */
    char text[] = "The kernel is Linux.";
    char *ptr = strstr(text, "Linux");
    if (ptr)
        printf("[4] Found substring: %s\n", ptr);
    else
        printf("[4] Substring not found\n");

    
    printf("L is at address: %p\n", &text[14]);
    printf("strstr ptr %p\n", ptr);
    

    /* 5. Tokenizing (splitting a string) */
    char str[] = "apple,banana,pear";

    printf("Before strtok: %s\n", str);
    printf("Before strtok: %c\n", str[5]);

    char *token = strtok(str, ",");
    printf("[5] Tokens:\n");
    while (token != NULL)
    {
        printf("    %s\n", token);
        token = strtok(NULL, ",");
    }

    printf("After strtok: %s\n", str);
    printf("After strtok: %d\n", str[5]);

    /* 6. Memory operations */
    char buffer[20];
    memset(buffer, '-', sizeof(buffer));
    buffer[19] = '\0'; // null terminate manually
    printf("[6] Buffer after memset: %s\n", buffer);


    // 7. Buffer Overrun
    char currentbuffer[5] = "aaaa\0";
    char nextbuffer[5] = "bbbb\0";

    // Removing the null terminator will overrun into the next buffer
    currentbuffer[4] = 'c';
    

    printf("Overrun: %s\n", currentbuffer);
    return 0;
}
