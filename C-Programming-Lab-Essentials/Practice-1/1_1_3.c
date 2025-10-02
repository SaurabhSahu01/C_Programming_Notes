#include<stdio.h>

int main(){
	// declaration of variables
	int amount_given, bill_amount;

	// taking input
	scanf("%d%d", &amount_given, &bill_amount);

	// finding quotient and remainder
	int quotient = amount_given / bill_amount;
	int remainder = amount_given % bill_amount;

	// printing the values, make sure to match the test cases
	printf("%d\n", quotient); // notice the newline 
	printf("%d", remainder);
	return 0;
}