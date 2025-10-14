#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes
void save_student(Student s, const char *filename);
Student load_student(const char *filename);
long get_file_size(const char *filename);

int main(void) {
    Student s1;
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    const char *filename = "student.bin";

    // TODO: Call save_student() to save student data to file
    printf("Saving student in binary format...\n");
    save_student(s1, filename);

    // TODO: Call load_student() to read data back into a new struct
    printf("Loading student from binary file...\n");
    Student s2 = load_student(filename);

    // TODO: Print loaded data to confirm correctness
    printf("Loaded student: %s, %d, GPA %.2f\n", s2.name, s2.age, s2.gpa);

    // Compare file sizes between text and binary versions
    long binary_size = get_file_size(filename);
    long text_size = get_file_size("student.txt"); // Assumes text version exists from Task 2
    printf("Binary file size: %ld bytes\n", binary_size);
    if (text_size >= 0) {
        printf("Text file size: %ld bytes\n", text_size);
    } else {
        printf("Text file not found for size comparison.\n");
    }

    return 0;
}

// TODO: Implement save_student()
// Open file for writing, check errors, write fields, then close file
void save_student(Student s, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open %s for writing.\n", filename);
        exit(1);
    }

    printf("Writing student data to %s...\n", filename);
    fwrite(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student data saved successfully.\n");
}

// TODO: Implement load_student()
// Open file for reading, check errors, read fields, then close file
Student load_student(const char *filename) {
    Student s;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open %s for reading.\n", filename);
        exit(1);
    }

    printf("Reading student data from %s...\n", filename);
    fread(&s, sizeof(Student), 1, fp);
    fclose(fp);
    printf("Student data loaded successfully.\n");
    return s;
}

// Helper function to get file size
long get_file_size(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1; // Indicate file not found
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);
    return size;
}