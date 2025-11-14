// Mask the most significant digit


/**
 *  345 -> 45
 * 
 * 
 */

#include<stdio.h>

int main(){
	printf("Enter a number : ");
	int num;
	scanf("%d", &num);

	int mask = 1;
	while(!((num/mask) >= 0 && (num/mask) <= 9)){
		mask = mask*10;
	}
	printf("Result = %d\n", (num % mask));
	return 0;
}