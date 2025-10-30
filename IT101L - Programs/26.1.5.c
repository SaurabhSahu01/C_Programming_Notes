#include<stdio.h>

int main(){
	/*
		Task 1: Extract each digits and reverse the number
		Task 2: Print the digit name in words
	*/
	printf("Enter an integer : ");
	int num;
	scanf("%d", &num);
	int reverseNum = 0;

	// Task 1 begins here
	while(num){
		int lastDigit = num % 10;
		reverseNum = reverseNum*10 + lastDigit;
		num = num / 10;
	}

	// Task 2 begins here
	while(reverseNum){
		int lastDigit = reverseNum % 10;

		switch(lastDigit){
			case 1: 
				printf("One ");
				break;
			case 2:
				printf("Two ");
				break;
			case 3:
				printf("Three ");
				break;
			case 4:
				printf("Four ");
				break;
			case 5: 
				printf("Five ");
				break;
			case 6:
				printf("Six ");
				break;
			case 7:
				printf("Seven ");
				break;
			case 8:
				printf("Eight ");
				break;
			case 9:
				printf("Nine ");
				break;
			default: 
				printf("Zero ");
		}

		// update the number
		reverseNum = reverseNum / 10;
	}

	return 0;
}