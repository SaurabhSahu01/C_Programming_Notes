#include<stdio.h>

void read1(int* ptr, int n) {
	for(int i = 0; i < n; i++){
		scanf("%d", &ptr[i]);
	}
}
void display(int* ptr, int n) {
	for(int i = 0; i < n; i++){
		printf("%d ", ptr[i]);
	}
	printf("\n");
}
void alternativeEleDisplay(int* ptr, int n) {
	for(int i = 0; i < n; i = i+2){
		printf("%d ", ptr[i]);
	}
	printf("\n");
}

void main() {
	int a[10], i, n;
	printf("Enter size of the array : ");
	scanf("%d", &n);
	printf("Enter %d elements : ", n);
	read1(a, n);
	printf("The given elements : ");
	display(a, n);
	printf("The alternative elements : ");
	alternativeEleDisplay(a, n);
}