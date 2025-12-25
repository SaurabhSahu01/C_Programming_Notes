#include<stdio.h>
#include<string.h>

int main(){
	char str[100];
	scanf("%s", str);

	int count1 = 0, count0 = 0;
	int len = strlen(str);
	
	for(int i = 0; i < len; i++){
		if(str[i] == '1')
			count1++;
		else 
			count0++;
	}

	if(count1 == 1 || count0 == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}