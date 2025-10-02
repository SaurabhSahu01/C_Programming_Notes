#include<stdio.h>
#include<stdlib.h> // this library is to be included to use abs() function

int main(){
	// variable declaration
	int speed1, speed2;

	// taking input
	scanf("%d%d", &speed1, &speed2);

	// logic 
	int difference = abs(speed1 - speed2); // NOTE the abs() function

	printf("%d", difference);
	
	return 0;
}