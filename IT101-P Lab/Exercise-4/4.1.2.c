#include <stdio.h>

int max(int a, int b){
	return a > b ? a : b;
}

// Recursive function to find the largest number
int findLargest(int arr[], int n) {
    //base case
    if(n == 1){
		return arr[n-1];
	}
    // Recursively find the largest in the rest of the array
	int largest = findLargest(arr, n-1  );
    // Compare and return the largest
    return max(largest, arr[n-1]);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", findLargest(arr, n));
    return 0;
}