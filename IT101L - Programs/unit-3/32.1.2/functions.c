void decimalToBinary(unsigned num){
    unsigned int temp = num;
    int binaryEquivalent[32];

    for(int i = 0; i < 32; i++){
        binaryEquivalent[i] = -1;
    }

    // logic to convert decimal value to binary
    int counter = 31;
    while(temp != 0){
        int rem = temp % 2;
        binaryEquivalent[counter--] = rem;
        temp = temp/2;
    }
    
    // print the binary equivalent
    printf("The binary number of decimal %d is : ", num);
    for(int i = 0; i < 32; i++){
        if(binaryEquivalent[i] == -1)
            continue;
        printf("%d", binaryEquivalent[i]);
    }
}