#include <stdio.h>
#include <string.h>

// Define struct Student with fields: name (char[]), id (int), grade (float)
struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void) {
    // Declare one or more Student variables
    struct Student student1;

    // Assign values (either manually or via scanf)
    printf("Enter student name: ");
    scanf("%49s", student1.name); // Limit to 49 chars to avoid buffer overflow
    printf("Enter student ID: ");
    scanf("%d", &student1.id);
    printf("Enter student grade: ");
    scanf("%f", &student1.grade);

    // Print struct contents using printf
    printf("\nStudent Details:\n");
    printf("Name: %s\n", student1.name);
    printf("ID: %d\n", student1.id);
    printf("Grade: %.2f\n", student1.grade);

    return 0;
}