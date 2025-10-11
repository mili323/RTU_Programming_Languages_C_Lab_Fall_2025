#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    int *arr = NULL;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    // Allocate memory for n integers using malloc
    arr = malloc(n * sizeof(int));

    // Check allocation success
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read n integers from user input and store in array
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input.\n");
            free(arr);
            return 1;
        }
    }

    // Compute sum and average
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double average = (double)sum / n;

    // Print the results
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    // Free allocated memory
    free(arr);

    return 0;
}