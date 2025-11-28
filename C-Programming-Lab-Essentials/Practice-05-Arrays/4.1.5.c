#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int arr[n][n];

	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			scanf("%d", &arr[row][col]);
		}
	}

	for(int row = 0; row < n; row++){
		for(int col = 0; col < n; col++){
			if(col < row)
				printf("0 ");
			else 
				printf("%d ", arr[row][col]);
		}
		printf("\n");
	}
	return 0;
}