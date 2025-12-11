#include<stdio.h>

int main(){
	printf("Enter array size : ");
	int n;
	scanf("%d", &n);

	int arr[n];

	printf("Enter %d array elements : ", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	printf("After eliminating duplicates, the array is : ");
	for(int ptr = 0; ptr < n; ptr++){
        int currentElement = arr[ptr];
        if(currentElement != -1){
            printf("%d ", currentElement);
        }
        else
            continue;
        for(int itr = ptr + 1; itr < n; itr++){
            if(arr[itr] == currentElement){
                arr[itr] = -1;
            }
        }
    }
	printf("\n");
	return 0;
}