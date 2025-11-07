#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int lineNumber = 0; lineNumber <= n-1; lineNumber++){
        // print the space 
        for(int space = 1; space <= n - lineNumber - 1; space++){
            printf(" ");
        }

        // print the numbers
        int firstValue = 1;
        printf("%d ", firstValue);
        // total elements in a line = lineNumber
        // index will go from 0 to lineNumber - 1
        for(int index = 1; index <= lineNumber; index++){
            int secondValue = (firstValue * (lineNumber - (index - 1))) / ( index );
            firstValue = secondValue;
            printf("%d ", secondValue);
        }
        printf("\n");
    }
    return 0;
}