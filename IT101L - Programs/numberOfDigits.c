#include<stdio.h>

// find the number of digits in a number
int main(){
    int num;
    scanf("%d", &num);

    int temp = num;

    int numberOfDigits = 0;

    while(temp){
        temp = temp / 10;
        numberOfDigits++;
    }

    printf("Number of Digits = %d", numberOfDigits);
    return 0;
}