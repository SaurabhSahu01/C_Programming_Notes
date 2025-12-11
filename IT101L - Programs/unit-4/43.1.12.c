#include<stdio.h>

int main(){
	printf("Enter the order of matrix : ");
	int n, m;
	scanf("%d%d", &n, &m);
	
	// array declaration
	int arr[n][m];
	
	// take user input
	printf("Enter %d elements : ", n*m);
	for(int row = 0; row < n; row++){
		for(int col = 0; col < m; col++){
			scanf("%d", &arr[row][col]);
		}
	}
	// flag to check if matrix is symmetric or not
	int isSymmetric = (n == m);
	
	// print the matrix
	printf("The given matrix is\n");
	for(int row = 0; row < n; row++){
		for(int col = 0; col < m; col++){
			if(isSymmetric && arr[row][col] != arr[col][row])
				isSymmetric = 0;
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
	
	// print the transpose of the matrix
	printf("Transpose of the given matrix is\n");
	for(int col = 0; col < m; col++){
		for(int row = 0; row < n; row++){
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}

	isSymmetric ? printf("The given matrix is symmetric matrix\n") : printf("The given matrix is not symmetric matrix\n");
	return 0;
}