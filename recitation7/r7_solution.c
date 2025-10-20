#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_STUDENTS 200
#define GRADE_BUFFER_SZ 20
#define CHOICE_BUFFER_SZ 10

typedef struct
{
    char *name;
    float grade;
} Student;

void addStudent(Student *students, int *count);
void removeStudent(Student *students, int *count);
void displayGrades(Student *students, int count);
void exportToCSV(Student *students, int count);

int main()
{
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

void addStudent(Student *students, int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Gradebook is full! Cannot add more students.\n");
        return;
    }

    // Get student info
    char buffer[MAX_NAME_LEN];
    char grade_buffer[GRADE_BUFFER_SZ];

    printf("Enter name: ");
    fgets(buffer, MAX_NAME_LEN, stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    // Dynamically allocate memory for the name
    students[*count].name = malloc((strlen(buffer) + 1) * sizeof(char));
    if (students[*count].name == NULL)
    {
        printf("Memory allocation failed for name!\n");
        return;
    }
    strcpy(students[*count].name, buffer);

    printf("Enter grade: ");
    fgets(grade_buffer, GRADE_BUFFER_SZ, stdin);
    students[*count].grade = atof(grade_buffer);

    (*count)++;
    printf("Added! Total students: %d\n", *count);
}

void removeStudent(Student *students, int *count)
{
    if (*count == 0)
    {
        printf("\nNo students to remove.\n");
        return;
    }

    displayGrades(students, *count);

    char index_buffer[CHOICE_BUFFER_SZ];
    int index;
    printf("\nEnter student index to remove (0-%d): ", *count - 1);
    fgets(index_buffer, CHOICE_BUFFER_SZ, stdin);
    index = atoi(index_buffer);

    if (index < 0 || index >= *count)
    {
        printf("Invalid student index!\n");
        return;
    }

    // Free the name of the student being removed
    free(students[index].name);

    // Shift all students after the removed one
    for (int i = index; i < *count - 1; i++)
    {
        students[i] = students[i + 1];
    }

    (*count)--;
    printf("Student removed! Total students: %d\n", *count);
}

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