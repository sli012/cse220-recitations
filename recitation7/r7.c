#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "r7.h"

int main()
{
    // Allocate space for 200 students on the heap
    // Note: We could use a stack array (Student students[MAX_STUDENTS]) since main() runs for the entire program lifetime
    Student *students = malloc(MAX_STUDENTS * sizeof(Student));
    if (students == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    int count = 0;
    int choice;

    printf("=== Simple Gradebook ===\n\n");

    while (1)
    {
        printf("\n1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Display Grades\n");
        printf("4. Export to CSV\n");
        printf("5. Exit\n");
        printf("Choice: ");

        char choice_buffer[CHOICE_BUFFER_SZ];
        fgets(choice_buffer, CHOICE_BUFFER_SZ, stdin);
        choice = atoi(choice_buffer);

        if (choice == 1)
        {
            addStudent(students, &count);
        }
        else if (choice == 2)
        {
            removeStudent(students, &count);
        }
        else if (choice == 3)
        {
            displayGrades(students, count);
        }
        else if (choice == 4)
        {
            exportToCSV(students, count);
        }
        else if (choice == 5)
        {
            // Free all dynamically allocated names
            for (int i = 0; i < count; i++)
            {
                free(students[i].name);
            }
            free(students);
            printf("Goodbye!\n");
            return 0;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
// TODO: implement
void addStudent(Student *students, int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Gradebook is full! Cannot add more students.\n");
        return;
    }
}

// TODO: implement
void removeStudent(Student *students, int *count)
{
    if (*count == 0)
    {
        printf("\nNo students to remove.\n");
        return;
    }
}
