#include<stdio.h>
#include<string.h>

int main(){
	printf("Enter two strings : ");
	char str1[30], str2[30], copy[30];
	scanf("%s", str1);
	scanf("%s", str2);

	printf("The length of %s : %zu\n", str1, strlen(str1));
	
	printf("The copied string of %s : %s\n", str1, strcpy(copy, str1));

	int comparisonResult = strcmp(str1, str2);
	if(comparisonResult > 0){
		printf("%s is greater than %s\n", str1, str2);
	}
	else if(comparisonResult < 0){
		printf("%s is less than %s\n", str1, str2);
	}
	else{
		printf("Both strings are equal\n");
	}

	printf("The concatenated string : %s\n", strcat(str1, str2));
	
	return 0;
}