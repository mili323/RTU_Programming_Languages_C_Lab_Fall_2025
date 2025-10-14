#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define DATA_FILE "students.txt"

typedef struct {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;

// Function prototypes
int load_students(Student arr[]);
void save_students(Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(Student arr[], int count);

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    // TODO: Load existing data from file using load_students()
    count = load_students(students);

    do {
        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                // TODO: Call list_students()
                list_students(students, count);
                break;
            case 2:
                // TODO: Call add_student()
                add_student(students, &count);
                break;
            case 3:
                // TODO: Call save_students() and exit loop
                save_students(students, count);
                printf("Data saved. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// TODO: Implement load_students()
// Open DATA_FILE, read records until EOF, return number of records loaded
int load_students(Student arr[]) {
    FILE *fp = fopen(DATA_FILE, "r");
    int count = 0;

    // Handle case where file doesn't exist or is empty
    if (fp == NULL) {
        printf("No existing student data found. Starting fresh!\n");
        return 0;
    }

    // Read records until EOF or array is full
    while (count < MAX_STUDENTS && fscanf(fp, "%49s %d %f\n", arr[count].name, &arr[count].id, &arr[count].gpa) == 3) {
        count++;
    }

    fclose(fp);
    printf("Loaded %d student(s) from %s.\n", count, DATA_FILE);
    return count;
}

// TODO: Implement save_students()
// Write all students to DATA_FILE
void save_students(Student arr[], int count) {
    FILE *fp = fopen(DATA_FILE, "w");
    if (fp == NULL) {
        printf("Error! Could not open %s for writing.\n", DATA_FILE);
        exit(1);
    }

    // Write each student record to the file
    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s %d %f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }

    fclose(fp);
}

// TODO: Implement add_student()
// Read input from user and append to array
void add_student(Student arr[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Error! Student list is full!\n");
        return;
    }

    printf("Enter name: ");
    scanf("%49s", arr[*count].name);
    getchar(); // Clear newline

    printf("Enter ID: ");
    scanf("%d", &arr[*count].id);
    getchar(); // Clear newline

    printf("Enter GPA: ");
    scanf("%f", &arr[*count].gpa);
    getchar(); // Clear newline

    (*count)++;
    printf("Student added successfully!\n");
}

// TODO: Implement list_students()
// Print all students in readable format
void list_students(Student arr[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent List:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, ID: %d, GPA: %.2f\n", arr[i].name, arr[i].id, arr[i].gpa);
    }
    printf("----------------------------------------\n");
}