#include<stdio.h>
int stringLength(char *);
int main(){
	char str1[200], str2[100];
	printf("string1 : ");
	scanf(" %[^\n]s", str1);
	printf("string2 : ");
	scanf(" %[^\n]s", str2);

	// we will concatenate str2 to str1 and store in str1 only
	int str1Length = stringLength(str1);
	int str2Length = stringLength(str2);
	int i, j;
	for(i = str1Length, j = 0; str2[j] != '\0'; i++, j++){
		str1[i] = str2[j];
	}
	str1[i] = '\0';


	printf("concatenated string = %s\n", str1);
	return 0;
}

int stringLength(char* str){
	int i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return i;
}