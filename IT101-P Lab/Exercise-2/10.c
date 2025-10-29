#include <stdio.h>

int main(){

    int n;
    scanf("%d", &n);

    // print the upper half of the diamond
    for(int i = 1; i <= n; i++){
        int numberOfElements = 2*i - 1;
        // print the space
        for(int k = 1; k <= n - i; k++){
            printf("  ");
        }
        for(int j = 1; j <= numberOfElements; j++){
            printf("%d ", j);
        }
        printf("\n");
    }

    // print the lower half of the diamond
    for(int i = n-1; i >= 1; i--){
        int numberOfElements = 2*i - 1;
        // print the space
        for(int k = 1; k <= n - i; k++){
            printf("  ");
        }
        for(int j = 1; j <= numberOfElements; j++){
            printf("%d ", j);
        }
        printf("\n");
    }
    
    return 0;
}
