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

	for(int i = 0; i < n; i++){
		printf("%d ", arr[i][i]);
	}
	
	return 0;
}