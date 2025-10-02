#include<stdio.h>

int main(){
	// variable declaration
	int apple1, apple2, apple3;

	// taking inputs
	scanf("%d%d%d", &apple1, &apple2, &apple3);

	// logic 
	if(apple1 < apple2 && apple2 < apple3){
		printf("Fit into Budget\n");
	}
	else{
		printf("Doesn't fit into Budget\n");
	}
	return 0;
}
