#include<stdio.h>
#include<string.h>
int main(){
	char str[20];
	printf("String: ");
	scanf("%[^\n]s", str);

	int lengthOfString = strlen(str);

	int start = 0, end = lengthOfString - 1;
	int isPalindrome = 1;

	while(start < end){
		if(str[start] != str[end]){
			isPalindrome = 0;
			break;
		}
		start++;
		end--;
	}
	if(isPalindrome)
		printf("Palindrome\n");
	else
		printf("Not a palindrome\n");
	
	return 0;
}