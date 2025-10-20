#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "r7.h"

void displayGrades(Student *students, int count)
{
    if (count == 0)
    {
        printf("\nNo students yet.\n");
        return;
    }

    printf("\n=== Grades ===\n");
    for (int i = 0; i < count; i++)
    {
        printf("[%d] %s: %.2f\n", i, students[i].name, students[i].grade);
    }
}

void exportToCSV(Student *students, int count)
{
    if (count == 0)
    {
        printf("\nNo students to export.\n");
        return;
    }

    FILE *file = fopen("out.csv", "w");
    if (file == NULL)
    {
        printf("Cannot create file.\n");
        return;
    }

    fprintf(file, "Name,Grade\n");
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s,%.2f\n", students[i].name, students[i].grade);
    }

    fclose(file);
    printf("Exported %d students to out.csv\n", count);
}