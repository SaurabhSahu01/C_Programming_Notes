#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  findMediandifferentSize(int A[], int ALen, int B[], int BLen) {
	int finalSize = ALen + BLen;
	int finalArray[finalSize];

	int ptr = 0, ptr1 = 0, ptr2 = 0;

	while(ptr1 < ALen && ptr2 < BLen){
		if(A[ptr1] < B[ptr2]){
			finalArray[ptr] = A[ptr1];
			ptr1++;
			ptr++;
		}
		else{
			finalArray[ptr] = B[ptr2];
			ptr2++;
			ptr++;
		}
	}
	if(ptr1 == ALen){
		for(int i = ptr2; i < BLen; i++){
			finalArray[ptr] = B[i];
			ptr++;
		}
	}
	else{
		for(int i = ptr1; i < ALen; i++){
			finalArray[ptr] = A[i];
			ptr++;
		}
	}
	int median = 0;
	// find the median
	if(finalSize % 2 == 0){
		median = (finalArray[finalSize/2] + finalArray[finalSize/2 - 1]) / 2;
	}
	else{
		median = finalArray[finalSize/2];
	}

	return median;
}

int readIntArray(char *argsArray, int arr[]) {
	int col = 0;
	char *token = strtok(argsArray, ",");
	while (token != NULL) {
		arr[col] = atoi(token);
		token = strtok(NULL, ",");
		col++;
	}
	return col;
}
int main(int argc, char *argv[]) {
	int A[strlen(argv[1])];
	int B[strlen(argv[2])];
	int ALen = readIntArray(argv[1], A);
	int BLen = readIntArray(argv[2], B);
	printf("%d\n",  findMediandifferentSize(A, ALen, B, BLen));
	return 0;
}