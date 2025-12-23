#include<stdio.h>
#include<string.h>

int main(){
	printf("Enter lines of text (enter END to complete)\n");
	int characters = 0, words = 0, lines = 0;

	while(1){
		char line[100];
		fgets(line, 100, stdin);

		// check if the string is "END" or "END\n"
		if(strcmp("END", line) == 0 || strcmp("END\n", line) == 0){
			break;
		}

		// else count the words and characters and lines
		words++;
		for(int i = 0; line[i] != '\0'; i++){
			if(line[i] == ' ')
				words++;
			if(line[i] == '\n'){
				lines++;
				break;
			}
			characters++;
		}
	}
	printf("Character = %d, Words = %d, Lines = %d\n", characters, words, lines);
	return 0;
}