int * allocateMemory(int n){
	int *ptr = (int *)calloc(n, sizeof(int));
	return ptr;
}
void read1(int *ptr, int n){
	for(int i = 0; i < n; i++){
		scanf("%d", (ptr + i));
	}
}

int sum(int *ptr, int n){
	int totalSum = 0;
	for(int i = 0; i < n; i++){
		totalSum += *(ptr + i);
	}
	return totalSum;
}