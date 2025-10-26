#ifndef R8_H
#define R8_H

typedef struct student
{
    char *name;
    float grade;
    struct student *next_student;
} Student;

Student *add_student(Student **head, char *name, float grade);
void show_students(Student *head);
Student *remove_student(Student **head, char *name);
Student *search_student(Student *head, char *name);
Student *update_student(Student *head, char *name, float new_grade);
#endif