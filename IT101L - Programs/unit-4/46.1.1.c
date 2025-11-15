#include<stdio.h>
#include<stdlib.h>
int main(){
	int size, absoluteDiff;
	scanf("%d %d", &size, &absoluteDiff);

	int arr[size];

	// user input to the array
	for(int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}


	// logic starts here
	int exists = 0; // false

	for(int i = 0; i < size - 1; i++){
		if(abs(arr[i] - arr[i+1]) <= absoluteDiff){
			exists = 1; // true
			break;
		}
	}

	exists ? printf("YES") : printf("NO");

	
	return 0;
}