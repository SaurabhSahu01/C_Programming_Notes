#include <stdio.h>
#include "functions.c"
int main() {
	int a, b;
	printf("Enter two numbers : ");
	scanf("%d%d" , &a, &b);
	largest(a, b);
    return 0;
}