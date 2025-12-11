#include<stdio.h>

int main(){
	printf("Enter the order of the matrix : ");
	int n;
	scanf("%d", &n);

	// array declaration
	int arr[n][n];

	// take input
	printf("Enter %d elements : ", n*n);

	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			scanf("%d", &arr[row][col]);
		}
	}

	// print matrix and even and odd sum 
	int evenSum = 0, oddSum = 0;
	printf("The given matrix\n");
	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			printf("%d ", arr[row][col]);
			if(arr[row][col] % 2 == 0){
				evenSum += arr[row][col];
			}
			else{
				oddSum += arr[row][col];
			}
		}
		printf("\n");
	}

	// diagonal sum
	int diagonalSum = 0;
	for(int i = 0; i < n; i++){
		diagonalSum += arr[i][i] + arr[i][n - i - 1];
	}

	if(n % 2 != 0){
		diagonalSum -= arr[n/2][n/2];
	}

	printf("The sum of diagonal elements = %d\n", diagonalSum);
	printf("The sum of even elements = %d\n", evenSum);
	printf("The sum of odd elements = %d\n", oddSum);

	return 0;
}