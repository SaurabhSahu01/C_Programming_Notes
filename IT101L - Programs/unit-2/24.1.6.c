#include<stdio.h>
#include<math.h>
int main(){

    int upperLimit;
    printf("Enter the upper limit : ");
    scanf("%d", &upperLimit);

    // print the series upto upper limit
    for(int term = 1; pow(2, term) -1 <= upperLimit; term++){
        printf("%d ", (int)pow(2, term) - 1);
    }
    return 0;
}