#include<stdio.h>
// function declaration
void printArray(int [], int);
void printEvenArray(int [], int);
void printReverse(int [], int );
int firstIndex(int [], int, int);
int main(){
    // take the size from the user
    printf("Enter the size of the array : ");
    int n;
    scanf("%d", &n);

    // declare the array
    int arr[n];

    // take the input from the user in the array
    printf("Enter the array elements \n");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // function call
    //printArray(arr, n);
    //printEvenArray(arr, n);
    //printReverse(arr, n);
    printf("Enter the target to search : ");
    int target;
    scanf("%d", &target);

    printf("The found index is : %d", firstIndex(arr, n, target));
    return 0;
}

// 1. write a function to print all the elements of an array
void printArray(int arr[100], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

// 2. write a function to print all the even-indexed element of an array
void printEvenArray(int arr[100], int size){
    for(int i = 0; i < size; i += 2){
        printf("%d ", arr[i]);
    }
}

// 3. write a function to print all the odd-indexed element of an array -- HomeWork

// 4. write a function to print all the elements in reverse order
void printReverse(int arr[100], int size){
    for(int i = size - 1; i >= 0; i--){
        printf("%d ", arr[i]);
    }
}

// 5. write a function to find the first occurence of the target
// Input : array, size of array, target value 
// Expected output : return the index of the target value

int firstIndex(int arr[], int size, int target){
    int found = -1; // out of bound index
    for(int i = 0; i < size; i++){
        if(arr[i] == target){
            found = i;
            break;
        }
    }
    return found;
}
