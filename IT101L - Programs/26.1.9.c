// Decimal to Binary conversion
#include<stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    int decimal[7] = {-1, -1, -1, -1, -1, -1, -1};
    int counter = 6;
    // Decimal to Binary Conversion
    while(num){
        int rem = num % 2;
        decimal[counter] = rem;
        counter--;
        num = num/2;
    }
    printf("Binary Equivalent : ");
    for(int i = 0; i <= 6; i++){
        if(decimal[i] == -1)
            continue;
        printf("%d", decimal[i]);
    }

    return 0;
}