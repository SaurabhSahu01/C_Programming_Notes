#include<stdio.h>

int main(){
	// declaration of variables
	float num1, num2;

	// taking input
	scanf("%f%f", &num1, &num2);

	// finding the sum
	float sum = num1 + num2;

	// printing the value up to 3 decimal places
	printf("%.3f", sum);
	return 0;
}