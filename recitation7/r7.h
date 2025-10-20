#ifndef STUDENT_H
#define STUDENT_H

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

#endif