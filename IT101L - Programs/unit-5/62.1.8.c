#include<stdio.h>
#include<string.h>
int main(){
    char str1[30];
	printf("String: ");
	scanf("%[^\n]s", str1);
    int position;
    int numberOfChars;
	printf("Position: ");
	scanf("%d", &position);
	printf("No of characters you want to delete: ");
	scanf("%d", &numberOfChars);

	// logic
    char* str2 = str1 + position + numberOfChars;
    int i, j;
    for(i = position, j = 0; str2[j] != '\0'; i++, j++){
        str1[i] = str2[j];
    }
    str1[i] = '\0';
	if(position < 0 || numberOfChars <= 0)
		printf("Deletion is not performed\n");
	else
	    printf("After deletion : %s\n", str1);
    return 0;
}