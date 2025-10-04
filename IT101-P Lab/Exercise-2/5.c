#include <stdio.h>
#include <math.h>
void main()
{
    // decalre variables here
    int n, i;
    float degree, x, term, sine = 0;
    const float PI = 3.14;

    printf("Enter the value of n : ");
    scanf("%d", &n);
    printf("Enter degrees : ");
    scanf("%f", &degree);
    // write code here
    x = degree * (PI / 180); // Convert degrees to radians
    for (i = 0; i < n; i++)
    {
        int sign = (i % 2 == 0) ? 1 : -1;
        int power = 2 * i + 1;

        // Calculate x^power
        float numerator = 1;
        for (int j = 1; j <= power; j++)
            numerator *= x;

        // Calculate power!
        float denominator = 1;
        for (int j = 1; j <= power; j++)
            denominator *= j;

        term = sign * (numerator / denominator);
        sine += term;
    }

    printf("The sine value sin(%f) = %f\n", degree, sine);
    printf("The sine value using built-in sin(%f) = %f\n", degree, sin(x));
}