#include <stdio.h>
#include<stdlib.h>
int main()
{
    int m, n;
    printf("Enter the size of rows : ");
    scanf("%d", &m);
    printf("Enter the size of cols : ");
    scanf("%d", &n);
    
    // rows are just an array of pointers
    int* ptr[m];
    
    // cols are just 1D arrays pointed by those pointers
    for(int i = 0; i < m; i++){
        // assigning the address of dynamically made 1D array to the pointers
        ptr[i] = (int*)malloc(n*sizeof(int));
    }
    
    // taking input to the array
    for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++){
            scanf("%d", &ptr[row][col]);
        }
    }
    
    // printing the matrix
    for(int row = 0; row < m; row++){
        for(int col = 0; col < n; col++){
            printf("%d ", ptr[row][col]);
        }
        printf("\n");
    }

    return 0;
}