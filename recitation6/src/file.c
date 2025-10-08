#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <file.h>
#include <ctype.h>

#define MAX_LINE 4096

// TODO: implement
void CopyFile(const char *inputFile, const char *outputFile) //takes in 2 character pointers that are names of the files
{ 
    FILE *in = fopen(inputFile, "r");//initialize file pointer, "r" for read
    FILE *out = fopen(outputFile, "w"); //"w" for write
    
    char buffer[MAX_LINE];

    while(fgets(buffer, sizeof(buffer), in)){ //fgets reads line from input file and saves it to buffer
        fputs(buffer, out); //saves copy to output file
    }

    fclose(in);//close pointers
    fclose(out);
}

// string = "Hello my name is sam"
// censor = "name"

// out = "Hello my XXXX is sam"
void Censor(const char *inputFile, const char *outputFile, const char *word)
{
    FILE *in = fopen(inputFile, "r");
    FILE *out = fopen(outputFile, "w");

    char buffer[MAX_LINE];

    char *match; //character pointer for where a match occurs

    while(fgets(buffer, sizeof(buffer), in)){ //while there are still more lines to read
        char temp[MAX_LINE] = {0};
        char *current = buffer;
        

        while((match = strstr(current, word))){ //loops through current which is buffer and returns instance where word appears
            strncat(temp, current, match - current);//copy every before and after the censored word in string variable
            strcat(temp, "XXXX");
            current = match + strlen(word);
        }
        strcat(temp, current); //copies rest of string after no more matches which is what comes after the censored word in string variable
        fputs(temp, out);
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
