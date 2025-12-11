#include<stdio.h>

int main(){
	printf("Enter the size of binary number : ");
	int n;
	scanf("%d", &n);

	// declare an array of size n
	int arr[n];

	// take user input
	printf("Enter %d bit binary number : ", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	// main logic
	int oneEncountered = 0;
	for(int i = n-1; i >= 0; i--){
		if(!oneEncountered && arr[i] == 1){
			oneEncountered = 1;
			continue;
		}
		if(oneEncountered){
			arr[i] ^= 1;
		}
	}

	// print the 2's complement
	printf("2's complement is : ");
	for(int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}