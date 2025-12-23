#include<stdio.h>

int main(){
	printf("enter string : ");
	char ch[30];
	scanf("%s", ch);

	printf("given string : %s\n", ch);

	// logic to convert uppercase to lowercase
	for(int i = 0; ch[i] != '\0'; i++){
		// check if the character is uppercase
		if(ch[i] >= 'A' && ch[i] <= 'Z'){
			ch[i] = ch[i] - 'A' + 'a';
		}
	}

	printf("lower case : %s\n", ch);
	return 0;
}