int sum(int a, int b){
    return a+b;
}
int sub(int a, int b){
    return a - b;
}
int mul(int a, int b){
    return a*b;
}
int div(int a, int b){
    if(b == 0){
        printf("Division by zero not possible!");
        return -1;
    }
    return a/b;
}