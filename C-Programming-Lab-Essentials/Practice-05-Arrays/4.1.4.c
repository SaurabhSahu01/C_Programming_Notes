#include<stdio.h>

int main(){
	int Row, Col;
	scanf("%d%d", &Row, &Col);

	// array declaration
	int arr[Row][Col];

	// taking user input
	for(int row = 0; row < Row; row++){
		for(int col = 0; col < Col; col++){
			scanf("%d", &arr[row][col]);
		}
	}

	// printing the transpose of the matrix
	for(int col = 0; col < Col; col++){
		for(int row = 0; row < Row; row++){
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
	return 0;
}