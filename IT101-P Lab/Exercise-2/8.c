#include<stdio.h>
#include<math.h>

/**
 *  CAUTION : The method 1 is the ideal method to implement, but CODETANTRA is giving output mismatch for the method 1
 * 
 *  NOTE : In the MSE exam, you have to do with method 2 only!!!!! 
 * 
 */

// Method 1 

int main(){
    int n; // n number of inputs for which we have to calculate the distinct number of primes
    scanf("%d", &n);

    while(n--){
        int num; // number for which we have to actually calculate the distinct number of primes
        scanf("%d", &num);

        // logic to find the number of distinct number of primes
        int squareRoot = sqrt(num); // Ask Yourself: why are we storing the squre root in a different variable ?
        int distinctPrimes = 0; 
        for(int i = 0; i <= squareRoot; i++){
            if(num % i == 0){
                distinctPrimes++;
                while(num % i == 0){
                    num /= 10;
                }
            }
        }
        // after the above operations, if the number is still greater than 1 then the number is prime itself
        if(num > 1)
            distinctPrimes++;

        printf("%d\n", distinctPrimes);
    }
    return 0;
}


// Method 2

int main(){
	int n;
	scanf("%d", &n);

	int num[n]; // declare an array of size n

	// take the input in the array
	for(int i = 0;  i < n; i++){
		scanf("%d", &num[i]);
	}

	// logic to calculate the number of distinct primes
	for(int i = 0; i < n; i++){
		int squareRoot = sqrt(num[i]);
		int distinctPrimes = 0;
		for(int n = 2; n <= squareRoot; n++){
			if(num[i] % n == 0){
				distinctPrimes++;
				while(num[i] % n == 0){
					num[i] = num[i]/n;
				}
			}
		}
		// if the num > 1, the number remaining is a prime itself
		if(num[i] > 1)
			distinctPrimes++;

		// update the original array
		num[i] = distinctPrimes;
	}

	// print the result
	for(int i = 0; i < n; i++){
		printf("%d\n", num[i]);
	}

	return 0;
}
