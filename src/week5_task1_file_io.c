#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *fp;
    char filename[100];
    char line[256];
    int line_count = 0;

    // BONUS: ask user for filename instead of using default "data.txt"
    printf(" Hello !Enter the filename: ");
    scanf("%99s", filename);
    while (getchar() != '\n'); // Clear input buffer

    // TODO: 1. Open file for writing (mode = "w")
    fp = fopen(filename, "w");

    // TODO: 2. Check if file opened successfully
    if (fp == NULL) {
        printf("Error! Cannot  open file %s for writing. Please check the filename.\n", filename);
        return 1;
    }

    // TODO: 3. Write 2–3 lines of text to the file using fprintf()
    printf("Write some lines to %s...\n", filename);
    fprintf(fp, "Welcome to file I/O in C!\n");
    fprintf(fp, "This is another line.\n");
    fprintf(fp, "Final line of text.\n");

    // TODO: 4. Close the file
    fclose(fp);
    printf("Done writing! The file is now saved.\n");

    // TODO: 5. Open file again for reading (mode = "r")
    fp = fopen(filename, "r");

    // TODO: 6. Check if file opened successfully
    if (fp == NULL) {
        printf("Error! Cannot open file %s for reading\n", filename);
        return 1;
    }

    // TODO: 7. Use fgets() in a loop to read and print each line to the console
    printf("Reading contents:\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        line_count++; // BONUS: count number of lines read
    }

    // TODO: 8. Close the file
    fclose(fp);

    // BONUS: print number of lines read
    printf("\nNumber of lines read: %d\n", line_count);

    return 0;
}