#include <stdio.h>

// Method 1
int main(){
    int n;
    scanf("%d", &n);

    int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            sum += j;
        }
    }
    printf("%d\n", sum);
    return 0;
}

// Method 2
int main(){
    int n;
    scanf("%d", &n);

    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += (i*(i+1))/2;
    }
    printf("%d\n", sum);
    return 0;
}

// Method 3
int main(){
    int n;
    scanf("%d", &n);
    int sum = (n*(n+1)*(n+2))/6;
    printf("%d\n", sum);
    return 0;
}