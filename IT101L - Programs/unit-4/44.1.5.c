#include <stdio.h>
void insertion_sort(int [], int);
void read1(int [], int);
void display(int [], int);
void main() {
	int a[20], n, i;
	printf("Enter n value : ");
	scanf("%d", &n);
	read1(a, n);
	printf("Elements before sorting : ");
	display(a, n);
	insertion_sort(a, n);
	printf("Elements after sorting : ");
	display(a, n);
}

// IMPORTANT : Remember this Algorithm
// Animation Video Link : https://youtu.be/JU767SDMDvA?si=zHEcdlvLLteftpV4
void insertion_sort(int *ptr, int numberOfElements) {
	 /*
    Insertion Sort works by dividing the array into two parts:
    - The left part is always sorted.
    - The right part is unsorted.

    In each iteration, one element from the unsorted part is picked
    and inserted into its correct position in the sorted left part.
    This process continues until the entire array is sorted.
    */

    // Start from the second element, as a single element is already sorted
    for (int i = 1; i < numberOfElements; i++) {

        // Store the current element to be inserted
        int chosenElement = ptr[i];

        // j points to the last index of the sorted left portion
        int j = i - 1;

        // Shift elements of the sorted part that are greater than
        // chosenElement one position to the right
        while (j >= 0 && ptr[j] > chosenElement) {
            ptr[j + 1] = ptr[j];
            j--;
        }

        // Insert the chosen element at its correct position
        ptr[j + 1] = chosenElement;
    }
}

void read1(int *ptr, int numberOfElements){
	printf("Enter %d elements : ", numberOfElements);
	for(int i = 0; i < numberOfElements; i++){
		scanf("%d", &ptr[i]);
	}
}

void display(int y[10], int n) {
	int j;
	for (j = 0; j < n; j++) {
		printf("%d ", y[j]);
	}
	printf("\n");
}