#include<stdio.h>
#include<string.h>

int main(){
	printf("Enter a string : ");
	char str[30];
	scanf("%[^\n]s", str);

	int stringLength = strlen(str);
	int start = 0, end = stringLength - 1;
	while(start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	printf("Reverse string : %s\n", str);
	return 0;
}