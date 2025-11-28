#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	// declare an array of size n*n
	int arr[n][n];

	// take user input
	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			scanf("%d", &arr[row][col]);
		}
	}

	// printing column by column and skipping the diagonal elements
	for(int col = 0; col < n; col++){
		for(int row = 0; row < n; row++){
			if(row == col)
				continue;
			printf("%d ", arr[row][col]);
		}
	}
	
	return 0;
}