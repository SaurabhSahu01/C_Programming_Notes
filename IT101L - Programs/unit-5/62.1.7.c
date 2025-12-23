#include<stdio.h>
#include<string.h>
int main(){
	char str1[50];
	char str2[30];
	 int position;
	printf("Main string: ");
	scanf(" %[^\n]s", str1);
	
    printf("Sub string: ");
	scanf(" %[^\n]s", str2);

	printf("Position: ");
	scanf("%d", &position);

	// concatenate the substring and the string after the position from main string
    strcat(str2, str1 + position);

	// keep copying str2 to str1, starting from the position given
    int i, j;
    for(i = position, j = 0; str2[j] != '\0'; i++, j++){
        str1[i] = str2[j];
    }
    str1[i] = '\0';
    printf("After insertion the main string: %s\n", str1);
	
    return 0;
}