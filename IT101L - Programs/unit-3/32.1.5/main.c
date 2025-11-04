#include <stdio.h>
#include "functions.c"
int main() {
	int a, b;
	printf("Enter two values : ");
	scanf("%d%d", &a, &b);
	printf("Addition of two values = %d\n", sum(a, b));
	printf("Subtraction of two values = %d\n", sub(a, b));
	printf("multiplication of two values = %d\n", mul(a, b));
	printf("division of two values = %d\n", div(a, b));
    return 0;
}