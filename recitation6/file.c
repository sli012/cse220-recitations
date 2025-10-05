#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 4096 // adjust as needed

void ReplaceInFile(const char *inputFile, const char *outputFile, const char *src, const char *dst)
{
    FILE *in = fopen(inputFile, "r");
    if (!in)
    {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *out = fopen(outputFile, "w");
    if (!out)
    {
        perror("Failed to open output file");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE];
    size_t srcLen = strlen(src);
    size_t dstLen = strlen(dst);

    while (fgets(line, sizeof(line), in))
    {
        char *pos = line;
        while ((pos = strstr(pos, src)) != NULL)
        {
            // Write everything before the match
            fwrite(line, 1, pos - line, out);
            // Write the replacement
            fwrite(dst, 1, dstLen, out);
            // Move past the match
            pos += srcLen;
            // Shift the remainder
            memmove(line, pos, strlen(pos) + 1);
            pos = line;
        }
        // Write whatever remains
        fputs(line, out);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s <input> <output> <src> <dst>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ReplaceInFile(argv[1], argv[2], argv[3], argv[4]);
    printf("Replacements complete. Output written to %s\n", argv[2]);

    return EXIT_SUCCESS;
}
