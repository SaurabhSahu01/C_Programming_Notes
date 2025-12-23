#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char **, char **);
int main(){
	int n;
	printf("Enter n value : ");
	scanf("%d", &n);

	// Method - 2 : Array of character pointers
	char * str[n];
	for(int i = 0; i < n; i++){
		str[i] = (char *)malloc(20*sizeof(char));
	}
	

	// taking string input
	printf("Enter %d strings : ", n);

	for(int i = 0; i < n; i++){
		scanf("%s", str[i]);
	}

	// print before sorting 
	printf("Before sorting : ");
	for(int i = 0; i < n; i++){
		printf("%s ", str[i]);
	}
	printf("\n");

	// sorting logic - Bubble Sort
	for(int i = n-1; i >= 0; i--){
		for(int j = 0; j < i; j++){
			if(strcmp(str[j], str[j+1]) > 0){
				swap(&str[j], &str[j+1]);
			}
		}
	}

	// print after sorting
	printf("After sorting : ");
	for(int i = 0; i < n; i++){
		printf("%s ", str[i]);
	}
	printf("\n");
	
	return 0;
}

void swap(char **str1, char **str2){
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}
