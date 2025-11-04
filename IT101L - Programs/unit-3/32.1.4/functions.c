#include<math.h>
float exponential(int n, float x){
    long long factorial = 1;
    float exponentialSum = 1;

    for(int term = 1; term <= n; term++){
        factorial = factorial* term;
        double nthTerm = pow(x, term) / factorial;
        exponentialSum += nthTerm;
    }
    return exponentialSum;
}