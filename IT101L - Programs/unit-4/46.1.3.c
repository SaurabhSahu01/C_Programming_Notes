#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	int arr[n];
	for(int i=0; i< n; i++){
		scanf("%d", &arr[i]);
	}

	int profit = 0;
    int isProfit = 0;
	int buyingDay = -1;
	int sellingDay = -1;
	for(int i = 0; i < n-1; i++){
        int print = 0;
		// we have profit 
		if(arr[i+1] - arr[i] > 0){
			if(profit == 0){
                isProfit = 1;
				buyingDay = i;
			}
            profit += arr[i+1] - arr[i];
		}
		else if(arr[i+1] - arr[i] < 0){
			// we have loss, we have to sell the stocks 
			if(buyingDay != -1){
				sellingDay = i;
                print = 1;
			}
            profit = 0;
		}
        if(i == n-2 && buyingDay > sellingDay){
            sellingDay = n-1;
            print = 1;
        }
        if(print){
            printf("(%d %d)", buyingDay, sellingDay);
            buyingDay = -1;
            sellingDay = -1;
        }
        print = 0;
	}
    if(!isProfit
    )
        printf("No Profit");
	return 0;
}