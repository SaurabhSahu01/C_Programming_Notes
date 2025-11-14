#include <stdio.h>
void main() {
	int number, temp, remainder, i, power, digits = 0, sum = 0;
	printf("Enter a number : ");
	scanf("%d", &number);
	temp = number;
	while ( temp > 0 ) { // complete the condition to iterate the loop
		digits++; // increment the digits
		temp = temp/10; //calculate the temp value
	}
	temp = number;
	while (number>0) { // complete the condition to iterate the loop
		remainder = number % 10;
		i = 1;
		power = 1;
		while (i <= digits ) { // find the powers of each digit
			power =power * remainder ; // calculate power value
			i++ ; // increment i value
		}
		sum =sum+power ; // calculate sum value
		number =number; // calculate number value
		number=number/10;// calculate number value
	}
	if (sum==temp) { // write the condition
		printf("The given number %d is an armstrong number\n", temp);
	} else {
		printf("The given number %d is not an armstrong number\n", temp);
	}
}