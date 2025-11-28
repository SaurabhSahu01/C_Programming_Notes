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

	// printing the matrix
	for(int row = 0; row < Row; row++){
		for(int col = 0; col < Col; col++){
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
	return 0;
}