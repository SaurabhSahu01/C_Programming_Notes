// Babylonian method to find the square root of any number

#include <stdio.h>
#include <math.h>
int main() {
	// declare variables here
	double num;
	
	printf("Enter a number : ");
	scanf("%lf", &num);
	if (num >= 0 ) {
		double epsilon = 0.00000001;
		double x0 = num/2; // initial guess

		double xn = (x0 + num/x0)/2;

		while(fabs(xn - x0) > epsilon){
            printf("Value of xn = %lf\n", xn);
			x0 = xn;
			xn = (x0 + num/x0)/2;
		}
		
		
		
		printf("The square root of %lf : %lf\n" ,  num, xn);
		printf("Using built-In function, sqrt(%f) : %f\n", num, sqrt(num));
	} else {
		printf("No square root to a negative number\n");
	}
    return 0;
}	