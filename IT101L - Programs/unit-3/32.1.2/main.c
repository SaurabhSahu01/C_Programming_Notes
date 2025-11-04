#include <stdio.h>
#include "functions.c"
int main() {
	int d;
	printf("Enter a positive decimal number : ");
	scanf("%d", &d);
	printf("The binary number of decimal %d is : ", d);
	decimalToBinary(d);
	printf("\n");
    return 0;
}