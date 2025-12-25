#include<stdio.h>
#include<string.h>
int main(){
	int testcases;
	scanf("%d", &testcases);

	char str[testcases][20]; // array of strings

	// taking string input for "testcases" number of times
	for(int i = 0; i < testcases; i++){
		scanf(" %[^\n]s", str[i]);
	}

	// printing the ouput
	for(int i = 0; i < testcases; i++){
		int len = strlen(str[i]);
		int flag = 1;

		for(int index = 0; index < len - 2; index++){
			if(str[i][index] != str[i][index+2]){
				flag = 0; 
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else 
			printf("NO\n");
		
	}
	return 0;
}
