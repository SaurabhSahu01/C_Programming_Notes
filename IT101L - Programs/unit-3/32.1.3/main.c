#include <stdio.h>
#include "functions.c"
int main() {
	int op, n;
	float x;
	printf("Enter number of terms : ");
	scanf("%d", &n);
	printf("Enter number of degrees : ");
	scanf("%f", &x);
	x = (x * 3.14) / 180;
	printf("Sine value = %f\n", sine(n, x));
	printf("Cosine value = %f\n", cosine(n, x));
	printf("Tangent value = %f\n" , sine(n, x) / cosine(n, x));
    return 0;
}