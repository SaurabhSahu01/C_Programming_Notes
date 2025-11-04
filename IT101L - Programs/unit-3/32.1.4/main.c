#include <stdio.h>
#include "functions.c"
int main() {
	int op, n;
	float x;
	printf("Enter n value : ");
	scanf("%d", &n);
	printf("Enter x value : ");
	scanf("%f", &x);
	//x = (x * 3.14) / 180;
	printf("Exponential result = %f\n", exponential(n, x));
    return 0;
}