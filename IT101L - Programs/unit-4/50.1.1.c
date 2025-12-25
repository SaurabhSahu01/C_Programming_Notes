#include <stdio.h>
#include <stdlib.h>
void main() {
	int *p, n, i;
	printf("Enter n value : ");
	// Read the valud of n
	scanf("%d", &n);
	p = (int *)malloc(n*sizeof(int));// Allocate memory;
	printf("Enter %d values : ", n);
	// Read the input elements
	for (int index = 0; index < n; index++ ) {
		scanf("%d", &p[index]);
	}
	printf("The given array elements are : ");
	// print the output
	for (int index = 0; index < n; index++ ) {
		printf("%d ", p[index] ); 
	}
}