#include<stdio.h>
// Include <limits.h> library to use the INT_MIN and INT_MAX
#include<limits.h>

int main(){
	printf("Enter how many values you want to read : ");
	int n;
	scanf("%d", &n);

	// array declaration
	int arr[n];

	// taking array input
	for(int i = 0; i < n; i++){
		printf("Enter the value of a[%d] : ", i);
		scanf("%d", &arr[i]);
	}

	// Main logic starts from here to find the largest and second largest element from an array
	int largest = INT_MIN;
	int secondLargest = INT_MIN;

	for(int i = 0; i < n; i++){
		// if there is any update in the largest element, then the previous largest element will become the second largest element
		if(arr[i] > largest){
			secondLargest = largest;
			largest = arr[i];
		}
		// check if the element is not larger than the largest element, but it's larger than the secondLargest element
		else if(arr[i] > secondLargest){
			// update the secondLargest element
			secondLargest = arr[i];
		}
	}

	printf("The largest element of the array = %d\n", largest);
	printf("The second largest element of the array = %d\n", secondLargest);
	
	return 0;
}