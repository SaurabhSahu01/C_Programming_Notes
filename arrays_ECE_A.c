


/*
Q.1. funtion to print the sum of all positive and negative 
    elements of an arraya
Q.2. Function to search an element in the array, 
    I/P : array, size, target, 
    O/P : first index of the target, if not then -1
    
Q.3. Function to delete an element
    I/P : array, size, target
    O/P : print the array with all the positions 
        marked as -1 where target was present

*/
#include <stdio.h>
#include<limits.h>
// function declaration
void printArray(int [], int);
void printReverseArray(int [], int);
void printEvenIndices(int [], int);
int maxElement(int [], int);
void printLargestSecondLargest(int [], int);
int main()
{
   int n;
   printf("Enter the size of array : ");
   scanf("%d", &n);
   
   // array declaration
   int arr[n];
   
   // array input from the user
   for(int i = 0; i < n; i++){
       printf("Enter the value of %d element : ", i+1);
       scanf("%d", &arr[i]);
   }
   
//   printArray(arr, n);
//   printReverseArray(arr, n);
    // printEvenIndices(arr, n);
    // int max = maxElement(arr, n);
    // printf("The largest element is : %d", max);
    
    printLargestSecondLargest(arr, n);

    return 0;
}

void printArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printReverseArray(int arr[], int size){
    for(int i = size - 1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printEvenIndices(int arr[], int size){
    printf("Printing even-indexed elements : \n");
    for(int i = 0; i < size; i += 2){
        printf("%d ", arr[i]);
    }
}

int maxElement(int arr[], int size){
    int max = INT_MIN; 
    
    for(int i = 0; i < size; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    
    return max;
}

void printLargestSecondLargest(int arr[], int size){
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    
    for(int i = 0; i < size; i++){
        if(arr[i] > largest){
            secondLargest = largest;
            largest = arr[i];
        }
        else if(arr[i] > secondLargest){
            secondLargest = arr[i];
        }
    }
    
    printf("Largest = %d\n", largest);
    printf("Second Largest = %d\n", secondLargest);
}










