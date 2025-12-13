void swap(int *, int *);
void bubble_sort(int *arr, int numberOfElements){
	for(int i = numberOfElements-1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}

void swap(int* a, int* b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

void read1(int *ptr, int n){
	printf("Enter %d elements : ", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &ptr[i]);
	}
}

void display(int *ptr, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", ptr[i]);
	}
	printf("\n");
}

