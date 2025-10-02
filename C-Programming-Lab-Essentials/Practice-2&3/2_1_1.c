#include<stdio.h>
#include<limits.h>

int main(){
	// variable declaration
	int bro1, bro2, bro3;

	// taking input
	scanf("%d%d%d", &bro1, &bro2, &bro3);
	/*
	// Logic 1 : finding the tallest brother using ternary operator
	int tallest = (bro1 > bro2) ? ((bro1 > bro3) ? bro1 : bro3) : (bro2 > bro3 ? bro2 : bro3);
	*/
	
	// Logic 2 : finding the tallest brother using the max variable
	int tallest = INT_MIN;
	if(bro1 > tallest) tallest = bro1;
	if(bro2 > tallest) tallest = bro2;
	if(bro3 > tallest) tallest = bro3;
	
	// printing the tallest brother
	printf("%d", tallest);
	return 0;
}