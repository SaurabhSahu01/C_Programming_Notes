int gcdResult(int a, int b){
    int smaller = a < b ? a : b;
    int larger = a + b - smaller;
    while(smaller != 0){
        int rem = larger % smaller;
        larger = smaller;
        smaller = rem;
    }
    return larger;
}