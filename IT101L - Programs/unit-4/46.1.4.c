#include<stdio.h>

// function declaration or function prototype
void swap(int *, int *);

int main(){
	int n;
	scanf("%d", &n);

	// array declaration
	int arr[n][n];

	// taking input to the array
	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			scanf("%d", &arr[row][col]);
		}
	}

	// Rotation of array by 90 degrees
	// step 1 : reverse the elements column wise
	for(int col = 0; col < n; col++){
		int startRow = 0; 
		int endRow = n-1;
		while(startRow < endRow){
			swap(&arr[startRow][col], &arr[endRow][col]);
			startRow++;
			endRow--;
		}
	}
	// step 2 : Take the transpose of the matrix
	for(int row = 0; row < n; row++){
		for(int col = 0; col < row; col++){
			swap(&arr[row][col], &arr[col][row]);
		}
	}

	// display the matrix
	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			printf("%d ", arr[row][col]);
		}
	}
	return 0;
}

void swap(int* a, int* b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}