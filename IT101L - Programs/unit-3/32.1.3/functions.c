#include<math.h>
#define PI 3.14159
float sine(int n, float x){
    long long int factorial = 1;
    float sineSum = 0;
    int sign = 1;

    for(int i = 1; i <= n; i++){
        int power = 2 * i - 1;
        if(i != 1){
            factorial = factorial * (power-1) * (power);
        }
        double term = (pow(x, power))/factorial;
        sineSum += sign*term;
        sign *= -1;
    }
    return sineSum;
}

float cosine(int n, float x){
    long long int factorial = 1;
    float cosineSum = 0;
    int sign = 1;

    for(int i = 1; i <= n; i++){
        int power = 2 * i - 2;
        if(i != 1){
            factorial = factorial * (power-1) * (power);
        }
        double term = pow(x, 2*i - 2) / factorial;
        cosineSum += sign*term;
        sign *= -1;
    }
    return cosineSum;
}