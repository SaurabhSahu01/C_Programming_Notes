#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
char binaryDecoding(char*, int, int);
int main(){
	int n;
	scanf("%d", &n);
	char str[n+1];
	scanf("%s", str);

	int numberOfCharacters = n/4;

	for(int i = 0; i < numberOfCharacters; i++){
		int startingIndex = 0 + 4*i;
		int endIndex = 3 + 4*i;
		printf("%c", binaryDecoding(str, startingIndex, endIndex));
	}
	return 0;
}

char binaryDecoding(char* str, int startIndex, int endIndex){
	int decimalEquivalent = 0;
	int power = 0;

	while(endIndex >= startIndex){
		int decimalValue = (str[endIndex] == '1');
		decimalEquivalent += (int)(decimalValue*pow(2, power));
		power++;
		endIndex--;
	}
	
	return (char)('a' + decimalEquivalent);
}