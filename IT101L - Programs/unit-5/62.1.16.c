#include<stdio.h>
#include<string.h>

int main(){
	char heystack[100], needle[20];
	printf("Enter the sentence : ");
	scanf(" %[^\n]s", heystack);
	printf("Enter the string to be searched : ");
	scanf(" %[^\n]s", needle);

	char* found = strstr(heystack, needle);

	if(found != NULL){
		int index = found - heystack;
		printf("String found in the sentence at the position : %d\n", index);
	}
	else{
		printf("-1\n");
	}
	
	return 0;
}