#include<stdio.h>
#include<string.h>
int isUpperOrLower(char);
int main(){
	char str[50];
	printf("Enter a string : ");
	scanf("%[^\n]s", str);

	int lower = 0, upper = 0;
	for(int i = 0; str[i] != '\0'; i++){
		int result = isUpperOrLower(str[i]);
		if(result == 1)
			lower++;
		else if(result == 0)
			upper++;
	}
	printf("Number of uppercase letters = %d\n", upper);
	printf("Number of lowercase letters = %d\n", lower);
	return 0;
}

int isUpperOrLower(char ch){
	if(ch >= 'a' && ch <= 'z')
		return 1; // 1 represents lowercase
	else if(ch >= 'A' && ch <= 'Z')
		return 0; // 0 represents uppercase
	return -1; // character not an alphabetic character
}