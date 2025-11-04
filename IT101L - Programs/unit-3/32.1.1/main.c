#include <stdio.h>
#include "functions.c"
int main() {
	int num1, num2;
	printf("Enter two integer numbers : ");
	scanf("%d%d", &num1, &num2);
	printf("GCD of %d and %d : %d\n", num1, num2, gcdResult(num1, num2));
    return 0;
}