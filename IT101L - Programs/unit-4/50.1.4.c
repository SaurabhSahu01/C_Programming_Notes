void read1(int *ptr, int size){
	for(int i = 0; i < size; i++){
		scanf("%d", (ptr + i));
	}
}
void display(int *ptr, int size){
	for(int i = 0; i < size; i++){
		printf("%d ", *(ptr + i));
	}
}
