#include<stdio.h>
#include<stdlib.h>

int main(){
	int avacado, dragon_fruit, coins, answer=0;
	scanf("%d %d %d", &avacado, &dragon_fruit, &coins);

	int difference = abs(avacado - dragon_fruit);

	if(difference <= coins){
		answer = 0;
	}
	else{
		if(avacado > dragon_fruit){
			dragon_fruit += coins;
		}
		else{
			avacado += coins;
		}
		answer = avacado - dragon_fruit;
	}
	printf("%d\n", answer);
	return 0;
}