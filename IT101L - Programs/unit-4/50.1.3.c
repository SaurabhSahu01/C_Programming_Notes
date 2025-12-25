#include <stdio.h>
#include <stdlib.h>
void read1(int *, int);
void display(int *, int);
void main() {
	int *p, n, i;
	printf("Enter n value : ");
	scanf("%d", &n);
	p = (int *) calloc(n, sizeof (int));
	read1(p, n);
	printf("The given elements are : ");
	display(p, n);
	printf("\n");
}
void read1(int *ptr, int n) { // Write the correct code
	int i;
	printf("Enter %d values : ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", (ptr + i)); // Write the correct code
	}
}
void display(int *ptr, int n) { // Write the correct code
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", *(ptr + i)); // Write the correct code
	}
}