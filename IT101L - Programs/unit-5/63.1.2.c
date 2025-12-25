#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char str[100];
	scanf(" %[^\n]s", str);
	int len = strlen(str);

	for(int i = 0; i < len; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			// convert to uppercase
			str[i] = toupper(str[i]);
		}
		else if(str[i] >= 'A' && str[i] <= 'Z'){
			// convert to lowercase
			str[i] = tolower(str[i]);
		}
	}

	printf("%s", str);
	return 0;
}