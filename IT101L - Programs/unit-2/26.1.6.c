// Reference : Euclidean method to find GCD 

#include<stdio.h>

int main(){
	int num1, num2;
	printf("Enter two integer numbers : ");
	scanf("%d%d", &num1, &num2);

	int smaller = (num1 < num2) ? num1 : num2;
	int larger = num1 + num2 - smaller;

	while(smaller){
		int remainder = larger % smaller;
		larger = smaller;
		smaller = remainder;
	}
	printf("GCD of %d and %d : %d\n", num1, num2, larger);
	return 0;
}