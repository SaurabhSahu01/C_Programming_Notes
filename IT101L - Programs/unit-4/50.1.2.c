#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
void main() {
	int *p, i, n, max, min;
	printf("Enter how many values you want to read : ");
	scanf("%d", &n);
	p = (int *)malloc(n * sizeof(int)); // Allocate heap memory
	printf("Enter %d elements : ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &p[i]); // Fill the code in scanf()
	}
	max = p[0]; // Complete the statement
	min = p[0]; // Complete the statement
	for (i = 1; i < n; i++) {
		if(p[i] > max) { // Write the condition part
			max = p[i]; // Complete the statement
		}
		if(p[i] < min) { // Write the condition part
			min = p[i]; // Complete the statement
		}
	}
	printf("The maximum element of the array = %d\n", max);
	printf("The minimum element of the array = %d\n", min);
}