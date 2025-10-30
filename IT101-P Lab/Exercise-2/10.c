#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    // print the upper half of the diamond
    for(int lineNumber = 1; lineNumber <= n; lineNumber++){
        int numberOfElements = 2*lineNumber - 1;
        // print the space
        for(int space = 1; space <= n - lineNumber; space++){
            printf("  ");
        }
        // print the numbers
        for(int number = 1; number <= numberOfElements; number++){
            printf("%d ", number);
        }
        printf("\n");
    }

    // print the lower half of the diamond
    for(int lineNumber = n-1; lineNumber >= 1; lineNumber--){
        int numberOfElements = 2*lineNumber - 1;
        // print the space
        for(int space = 1; space <= n - lineNumber; space++){
            printf("  ");
        }
        // print the numbers
        for(int number = 1; number <= numberOfElements; number++){
            printf("%d ", number);
        }
        printf("\n");
    }
    
    return 0;
}
