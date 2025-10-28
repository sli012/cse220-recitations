#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "r8.h"

// Add a new student to the linked list
Student *add_student(Student **head, char *name, float grade)
{
    // Allocate memory for new student
    Student *new_student = (Student *)malloc(sizeof(Student));
    new_student->next_student =NULL; // YOU SHOULD PROBABLY NULL this so some garbage value won't be here for the first node.

    if (new_student == NULL)
    {
        return NULL;
    }

    // Allocate memory for name and copy it
    new_student->name = (char *)malloc(strlen(name) + 1);
    if (new_student->name == NULL)
    {
        free(new_student);
        return NULL;
    }
    strcpy(new_student->name, name);

    new_student->grade = grade;
    new_student->next_student = *head;
    *head = new_student;

    return new_student;
}

// Display all students in the linked list
void show_students(Student *head)
{
    if (head == NULL)
    {
        printf("No students in the list.\n");
        return;
    }

    printf("\n=== Student List ===\n");
    Student *current = head;
    int count = 1;

    while (current != NULL)
    {
        printf("%d. Name: %s, Grade: %.2f\n", count++, current->name, current->grade);
        current = current->next_student;
    }
    printf("====================\n\n");
}

// Remove a student from the linked list by name
Student *remove_student(Student **head, char *name)
{
    if (*head == NULL)
    {
        return NULL;
    }

    Student *current = *head;
    Student *previous = NULL;

    // Search for the student
    while (current != NULL && strcmp(current->name, name) != 0)
    {
        previous = current;
        current = current->next_student;
    }

    // Student not found
    if (current == NULL)
    {
        return NULL;
    }

    // Remove the student
    if (previous == NULL)
    {
        // Removing the head node
        *head = current->next_student;
    }
    else
    {
        // Removing a middle or last node
        previous->next_student = current->next_student;
    }

    free(current->name);
    free(current);

    return *head; // Return new head
}

// Search for a student by name
Student *search_student(Student *head, char *name)
{
    Student *current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            return current;
        }
        current = current->next_student;
    }

    return NULL;
}

// Update a student's grade
Student *update_student(Student *head, char *name, float new_grade)
{
    Student *current = head;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            current->grade = new_grade;
            return current;
        }
        current = current->next_student;
    }

    return NULL;
}