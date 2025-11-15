// Method 1 : Brute-Force approach / Naive approach -> works for smaller size array, codetantra par kaam krega

#include<stdio.h>
#include<limits.h>
int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int sum = 0;
    int maxSum = INT_MIN;
    // all the subarrays starting with index i
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            sum += arr[j];
            maxSum = sum > maxSum ? sum : maxSum;
        }
        sum = 0;
    }

    printf("MaxSum of subarray = %d", maxSum);
    return 0;
}

// Method - 2 : Sliding window approach - we will discuss in the class