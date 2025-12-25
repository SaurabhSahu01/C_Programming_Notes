void read1(int *ptr, int n){
	for(int i = 0; i < n; i++){
		scanf("%d", (ptr + i));
	}
}

void displayInReverse(int *ptr, int n){
	for(int i = n-1; i >= 0; i--){
		printf("%d ", *(ptr + i));
	}
}