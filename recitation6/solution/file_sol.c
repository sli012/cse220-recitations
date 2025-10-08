#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>
#include <ctype.h>

#define MAX_LINE 4096

void CopyFile(const char *inputFile, const char *outputFile)
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

    while (fgets(line, sizeof(line), in))
    {
        fputs(line, out);
    }

    fclose(in);
    fclose(out);
}

void Censor(const char *inputFile, const char *outputFile, const char *word)
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
    size_t word_len = strlen(word);

    while (fgets(line, sizeof(line), in))
    {
        char *p = line;
        char buffer[MAX_LINE] = {0};
        size_t buf_len = 0; // track buffer usage

        while (*p)
        {
            // check for a match and proper word boundaries
            if (strncmp(p, word, word_len) == 0 &&
                (p == line || !isalnum(p[-1])) &&
                !isalnum(p[word_len]))
            {
                if (buf_len + 4 < MAX_LINE)
                {
                    strcat(buffer, "XXXX");
                    buf_len += 4;
                }
                p += word_len;
            }
            else
            {
                if (buf_len + 1 < MAX_LINE)
                    buffer[buf_len++] = *p;
                p++;
            }
        }

        fputs(buffer, out);
    }

    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        return EXIT_FAILURE;

    // CopyFile(argv[1], argv[2]);
    Censor(argv[1], argv[2], argv[3]);

    return EXIT_SUCCESS;
}
