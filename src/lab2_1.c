#include <stdio.h>

/*
    Task:
    Write a function int sum_to_n(int n) that computes
    the sum of all integers from 1 up to n using a for loop.

    In main():
      - Ask user for a positive integer n
      - If n < 1, print an error
      - Otherwise, call sum_to_n and print the result
*/

int sum_to_n(int n) {

    int total =0;
    for (int num =1; num <= n; num++) {
        total +=num ;
    }
    // TODO: implement sum with a for loop
    return total; // placeholder
}

int main(void) {
    int n;

    printf("Enter a positive integer n: ");
    scanf("%d", &n);

    if (n<=0)
    {
        printf(" Invalid  input! n must be greater than 0 (n>=1).\n");
    }
    else
    {
        int result = sum_to_n(n);
        printf("The sum  from 1 to %d = %d.\n", n, result);
    }

    // TODO: validate input, call function, and print result

    return 0;
}