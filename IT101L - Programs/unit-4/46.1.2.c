#include<stdio.h>
void reverse(int [], int, int);
int main(){
    int n, k; // n -> size of array, k -> rotation of array to the right by k steps
    scanf("%d%d", &n, &k);

    // declare an array of size n
    int arr[n];

    // taking user input to the array
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // main logic
    k = k % n; // why?

    // partition : (0 to n-k-1) & (n-k to n-1)
    // reverse the first partition
    reverse(arr, 0, n-k-1);
    // reverser the second partition
    reverse(arr, n-k, n-1);
    // reverse the whole array
    reverse(arr, 0, n-1);

    // print the array
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}

void reverse(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}