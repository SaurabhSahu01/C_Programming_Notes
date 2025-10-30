#include <stdio.h>

/**
 * 
 * This problem is similar to the previous problem where we had to print the upper half and the lower
 * half of the diamond pattern.
 * This question is about printing the upper half of the diamond. The only difference is that this question has 2 spaces instead of 1 space.
 */
int main(){
    int n;
    printf("Enter rows: ");
    scanf("%d", &n);

    // Input validation
    if(n <= 0){
        printf("Number of rows should be greater than zero.\n");
        return 0;
    }

    // print the upper half of the diamond
    for(int lineNumber = 1; lineNumber <= n; lineNumber++){
        int numberOfElements = 2*lineNumber - 1;
        // print the space
        for(int space = 1; space <= n - lineNumber; space++){
            printf("   "); // Note we are using 2 spaces after each space
        }

        int maxNumberInline = lineNumber;

        // print the numbers in increasing order
        for(int number = 1; number <= maxNumberInline; number++){
            printf("%d  ", number); // Note we are using 2 spaces after every number
        }
        // print the numbers in decreasing order
        for(int number = maxNumberInline-1; number >= 1; number--){
            printf("%d  ", number);
        }
        printf("\n");
    }
}