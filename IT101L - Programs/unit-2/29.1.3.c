#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int count2s = 0, count5s = 0;
	for(int i = 1; i <= n; i++){
		int temp = i;
		if(temp % 2 == 0){
			while(temp % 2 == 0){
				count2s++;
				temp = temp/2;
			}
		}
		if(temp % 5 == 0){
			while(temp % 5 == 0){
				count5s++;
				temp = temp/5;
			}
		}
	}
	int answer = count2s < count5s ? count2s : count5s;
	printf("%d\n", answer);
	return 0;
}