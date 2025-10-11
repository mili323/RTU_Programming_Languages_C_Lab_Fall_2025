#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct Student with fields name, id, grade
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    int n;
    struct Student *students = NULL;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        return 1;
    }

    // Allocate memory for n Student structs using malloc
    students = malloc(n * sizeof(struct Student));

    // Read student data in a loop
    for (int i = 0; i < n; i++) {
        printf("Enter student name: ");
        scanf("%s", students[i].name);
        printf("Enter student ID: ");
        scanf("%d", &students[i].id);
        printf("Enter student grade: ");
        scanf("%f", &students[i].grade);
    }

    // Display all student records in formatted output
    for (int i = 0; i < n; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].id);
        printf("Grade: %.2f\n", students[i].grade);
    }

    // Optional: Compute average grade or find top student
    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].grade;
    }
    printf("Average grade: %.2f\n", sum / n);

    // Free allocated memory
    free(students);

    return 0;
}