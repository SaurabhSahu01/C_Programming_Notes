#include<stdio.h>
int isPrime(int);
int main(){
    int lowerLimit, upperLimit;
    printf("Enter the lower limit : ");
    scanf("%d", &lowerLimit);
    printf("Enter the upper limit : ");
    scanf("%d", &upperLimit);

    for(int i = lowerLimit; i <= upperLimit; i++){
        if(isPrime(i)){
            printf("%d ", i);
        }
    }
    return 0;
}

int isPrime(int num){
    int prime = 1;
    for(int i = 2; i < num/2; i++){
        if(num % i == 0){
            prime = 0;
            break;
        }
    }
    return prime;
}