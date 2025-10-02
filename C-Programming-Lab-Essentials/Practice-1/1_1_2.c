#include<stdio.h>

int main(){
	float num1, num2;
	// taking input
	scanf("%f%f", &num1, &num2);

	// performing multiplication operation
	float multiplication = num1 * num2;
	printf("%.4f", multiplication);
	return 0;
}