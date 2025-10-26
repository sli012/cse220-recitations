#include <criterion/criterion.h>
#include "r8.h"

// Helper function to free the entire list
void free_list(Student *head)
{
    Student *current = head;
    while (current != NULL)
    {
        Student *next = current->next_student;
        free(current->name);
        free(current);
        current = next;
    }
}

// Setup and teardown
Student *head;

void setup(void)
{
    head = NULL;
}

void teardown(void)
{
    free_list(head);
}

// Test add_student
Test(student_list, test_add, .init = setup, .fini = teardown)
{
    Student *result = add_student(&head, "Alice", 95.5);

    cr_assert_not_null(result, "Should add student successfully");
    cr_assert_str_eq(result->name, "Alice");
    cr_assert_float_eq(result->grade, 95.5, 0.01);
}

// Test search_student
Test(student_list, test_search, .init = setup, .fini = teardown)
{
    add_student(&head, "Alice", 95.5);
    add_student(&head, "Bob", 87.3);

    Student *result = search_student(head, "Bob");

    cr_assert_not_null(result, "Should find Bob");
    cr_assert_str_eq(result->name, "Bob");
    cr_assert_float_eq(result->grade, 87.3, 0.01);
}

// Test update_student
Test(student_list, test_update, .init = setup, .fini = teardown)
{
    add_student(&head, "Alice", 95.5);
    add_student(&head, "Charlie", 92.0);

    Student *result = update_student(head, "Charlie", 96.5);

    cr_assert_not_null(result, "Should update student successfully");
    cr_assert_str_eq(result->name, "Charlie");
    cr_assert_float_eq(result->grade, 96.5, 0.01);
}

// Test remove_student
Test(student_list, test_remove, .init = setup, .fini = teardown)
{
    add_student(&head, "Alice", 95.5);
    add_student(&head, "Bob", 87.3);
    add_student(&head, "Charlie", 92.0);

    remove_student(&head, "Bob");

    Student *result = search_student(head, "Bob");
    cr_assert_null(result, "Bob should be removed");
}