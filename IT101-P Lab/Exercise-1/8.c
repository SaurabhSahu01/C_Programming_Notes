#include <stdio.h>

int main()
{
    int a, b, result = 0;
    int i;

    // Read the two numbers from the user
    scanf("%d", &a);
    scanf("%d", &b);

    // Determine the sign of the result
    // XOR to determine if result should be negative
    int negative = (a < 0) ^ (b < 0);
    if (a < 0)
        a = -a;
    if (b < 0)
        b = -b;

    // Convert numbers to positive for the loop

    // Perform repeated addition

    // Convert numbers to positive for the loop

    // Perform repeated addition
    for (i = 0; i < b; i++)
    {

        result += a;
    }

    // Apply the sign to the result if needed
    if (negative)
        result = -result;

    // Print the result
    printf("%d", result);

    return 0;
}
