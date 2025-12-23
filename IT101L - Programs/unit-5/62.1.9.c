#include<stdio.h>

int main(){
	char str[50];
	int position;
	char ch;
	printf("Enter a string : ");
	scanf("%[^\n]s", str);
	printf("Enter the position : ");
	scanf("%d", &position);
	printf("Enter the character to replace : ");
	scanf(" %c", &ch);

	// logic
	str[position] = ch;

	printf("After replacement the string is : %s\n", str);
	return 0;
}