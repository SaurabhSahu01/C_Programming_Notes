#include<stdio.h>

int main(){
	printf("Enter a string : ");
	char str[100], strCpy[100];
	scanf(" %[^\n]s", str);

	int i = 0;
	while(str[i] != '\0'){
		strCpy[i] = str[i];
		i++;
	}
	strCpy[i] = '\0';

	printf("The copied string = %s\n", strCpy);
	return 0;
}