#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int i, j, space, num;

    // Upper half including the middle row
    for (i = 1; i <= n; i++)
    {
        space = n - i;
        num = 2 * i - 1;

        // Print leading spaces
        for (j = 0; j < space; j++)
        {
            printf("  ");
        }

        // Print numbers
        for (j = 1; j <= num; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    // Lower half
    for (i = n - 1; i >= 1; i--)
    {
        space = n - i;
        num = 2 * i - 1;

        // Print leading spaces
        for (j = 0; j < space; j++)
        {
            printf("  ");
        }

        // Print numbers
        for (j = 1; j <= num; j++)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}
