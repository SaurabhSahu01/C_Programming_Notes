#include<stdio.h>
// Function Prototypes
void bubbleSort(int [], int);
void swap(int *, int *);

int main(){
	int Row, Col;
	scanf("%d%d", &Row, &Col);

	// declare an array
	int arr[Row][Col];

	// taking user input
	for(int row = 0; row < Row; row++){
		for(int col = 0; col < Col; col++){
			scanf("%d", &arr[row][col]);
		}
	}

	// sort the matrix row wise
	for(int row = 0; row < Row; row++){
		bubbleSort(arr[row], Col);
	}

	// print the sorted matrix
	for(int row = 0; row < Row; row++){
		for(int col = 0; col < Col; col++){
			printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
	return 0;
}

// Function Definitions
void bubbleSort(int arr[], int size){
	for(int iteration = size-1; iteration > 0; iteration--){
		int swapped = 0;
		for(int i = 0; i < iteration; i++){
			if(arr[i] > arr[i+1]){
				swap(&arr[i], &arr[i+1]);
				swapped = 1;
			}
		}
		if(!swapped)
			break;
	}
}
void swap(int *a, int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}