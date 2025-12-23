#include<stdio.h>
#include<string.h>

int main(){
	char str[50];
	char ch;
	printf("Enter a string : ");
	scanf("%[^\n]s", str);
	printf("Enter the character : ");
	scanf(" %c", &ch);

	int occurence = 0;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == ch)
			occurence++;
	}

	if(occurence > 0)
		printf("Occurences of '%c' = %d\n", ch, occurence);
	else
		printf("'%c' is not present in %s\n", ch, str);
	return 0;
}