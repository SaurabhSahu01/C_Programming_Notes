/*
Logic :
To print N number of pages, lets say X sheets are required. 
Then, 2*X >= N, must be followed given that the X acquires the minimum value.
*/
#include<stdio.h>

int main(){
	// variable declaration
	int N;

	// taking input
	scanf("%d", &N);

	// logic 
	int quotient = N / 2;
	int remainder = N % 2; // if number of pages are even, no extra sheet is required, else 1 extra sheet is required
	int totalSheets = quotient + remainder;

	// printing the answer
	printf("%d", totalSheets);
	return 0;
}