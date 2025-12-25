#include<stdio.h>
#include<string.h>

int main(){
	char heystack[100];
	scanf(" %[^\n]s", heystack);
	char needle[50];
	scanf(" %[^\n]s", needle);

	char* found = strstr(heystack, needle);

	if(found == NULL){
		printf("Doesn't Exists\n");
	}
	else{
		printf("Exists\n");
	}
	return 0;
}