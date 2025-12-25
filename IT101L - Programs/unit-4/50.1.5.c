int* allocateMemory(int n){
	int *ptr = (int *)malloc(n*sizeof(int));
	return ptr;
}
void read1(int *ptr, int size){
	for(int i = 0; i < size; i++){
		scanf("%d", (ptr + i));
	}
}

int sum(int *ptr, int size){
	int totalSum = 0;
	for(int i = 0; i < size; i++){
		totalSum += *(ptr + i);
	}
	return totalSum;
}



