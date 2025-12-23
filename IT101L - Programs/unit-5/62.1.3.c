#include<stdio.h>
#include<ctype.h>
int main(){
	char ch[50];
	printf("Enter a line of string : ");
	scanf("%[^\n]s", ch);

	int vowels = 0, consonants = 0, digits = 0, whitespace = 0;

	for(int i = 0; ch[i] != '\0'; i++){
		char lowerCase = tolower(ch[i]);
		// check for vowel
		if(lowerCase == 'a' || lowerCase == 'e' || lowerCase == 'i' || lowerCase == 'o' || lowerCase == 'u'){
			vowels++;
		}
		else if(lowerCase >= 'a' && lowerCase <= 'z' && lowerCase != 'a' && lowerCase != 'e' && lowerCase != 'i' && lowerCase != 'o' && lowerCase != 'u'){
			consonants++;
		}
		else if(lowerCase == ' ') whitespace++;
		else if(lowerCase >= '0' && lowerCase <= '9') digits++;
	}
	printf("Vowels = %d\n", vowels);
	printf("Consonants = %d\n", consonants);
	printf("Digits = %d\n", digits);
	printf("White spaces = %d\n", whitespace);
	return 0;
}