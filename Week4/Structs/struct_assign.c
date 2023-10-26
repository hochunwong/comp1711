#include <stdio.h>
#include <string.h>

struct student {
    char name [200];
    char student_id [11]; // Assuming 10 digits.
    unsigned mark;
};

int main () {
    struct student new_student;
    strcpy(new_student.name, "Name Surname");
    strcpy(new_student.student_id, "13902178");
    printf("Student name: %s\n", new_student.name);
    printf("Student ID:   %s\n", new_student.student_id);
    printf("Final mark:   %u\n", new_student.mark);

    struct student second_new_student;
    printf("\nEnter second new student's name      : ");
    scanf("%s", second_new_student.name);
    printf("Enter second new student's Student ID: ");
    scanf("%s", second_new_student.student_id);
    printf("Enter second new student's final mark: ");
    scanf("%u", &second_new_student.mark);

    printf("Student name: %s\n", second_new_student.name);
    printf("Student ID:   %s\n", second_new_student.student_id);
    printf("Final mark:   %u\n", second_new_student.mark);

    return 0;
}