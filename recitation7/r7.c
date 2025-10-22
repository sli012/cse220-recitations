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
    char buffer[MAX_NAME_LEN];
    char buffer2[CHOICE_BUFFER_SZ];

    printf("Student name: ");
    fgets(buffer, MAX_NAME_LEN, stdin);
    buffer[strcspn(buffer, "\n" = 0)];

    students[*count].name = malloc(strlen(buffer) + 1); //malloc at end to store students
    strcopy(students[*count].name, buffer);

    printf("Grade: ");
    fgets(buffer2, CHOICE_BUFFER_SZ, stdin); 
    students[*count].grade * atof(buffer2);
    (*count)++;
    print("Saved student");
}

// TODO: implement
void removeStudent(Student *students, int *count)
{
    if (*count == 0)
    {
        printf("\nNo students to remove.\n");
        return;
    }
    displayGrades(students, *count);

    char buffer[CHOICE_BUFFER_SZ];
    int index;
    printf("Student to remove: ");
    fgets(buffer, CHOICE_BUFFER_SZ, stdin);
    index = atoi(buffer);

    if(index < 0 || index >= *count){
        print("invalid index");
        return;
    }

    free(students[index].name);
    for(int i = 0; i < *count; i++){
        students[i] = students[i + 1];
    }
    (*count)++;
    print("student removed");

    
}
