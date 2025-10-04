#include <stdio.h>

int main()
{
    int num, i, is_prime = 1;

    scanf("%d", &num);

    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            is_prime = 0;
            break;
        }
    }
    if (is_prime)
    {
        printf("Prime\n");
    }
    else
    {
        printf("Not Prime\n");
    }

    return 0;
}
