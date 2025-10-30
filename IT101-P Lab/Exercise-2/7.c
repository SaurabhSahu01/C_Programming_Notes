#include <stdio.h>

// Method 1
int main(){
    unsigned int num, set_bits_count = 0;
    scanf("%u", &num);

    unsigned int mask = 1;

    for(int i = 1; i <= 31; i++){
        if((num & mask) != 0){
            set_bits_count++;
        }
        mask = mask << 1;
    }

    if (num == 0){
        printf("All bits are unset\n");
    }
    else{
        printf("Number of set bits: %d\n", set_bits_count);
    }

    return 0;
}

// Method 2
int main(){

    unsigned int num, set_bits_count = 0;
    scanf("%u", &num);

    unsigned int temp = num;
    while (temp)
    {
        if (temp & 1)
            set_bits_count++;
        temp >>= 1;
    }

    if (num == 0)
    {
        printf("All bits are unset\n");
    }
    else
    {
        printf("Number of set bits: %d\n", set_bits_count);
    }

    return 0;
}
