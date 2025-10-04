#include <stdio.h>

int main()
{

    // write your code here...
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
