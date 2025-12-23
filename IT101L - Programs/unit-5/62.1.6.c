#include<stdio.h>

int main(){
	char str1[50], str2[50];

	printf("string1 : ");
	scanf(" %[^\n]s", str1);
	printf("string2 : ");
	scanf(" %[^\n]s", str2);

	// logic
	int isEqual = 1;
	int i;
	for(i = 0; str1[i] != '\0' && str2[i] != '\0'; i++){
		if(str1[i] != str2[i])
			isEqual = 0;
	}
	if(str1[i] != '\0' || str2[i] != '\0')
		isEqual = 0;

	if(isEqual)
		printf("equal\n");
	else
		printf("not equal\n");
	
	return 0;
}