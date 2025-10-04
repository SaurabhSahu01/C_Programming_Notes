#include <stdio.h>

int main()
{
    int rows;

    // Prompt for input
    printf("Enter rows: ");
    scanf("%d", &rows);

    // Input validation
    if (rows <= 0)
    {
        printf("Number of rows should be greater than zero.\n");
        return 0;
    }

    // Loop through each row
    for (int i = 1; i <= rows; i++)
    {
        // Print leading spaces for centering
        for (int space = 1; space <= rows - i; space++)
        {
            printf("   ");
        }

        // Print ascending numbers from 1 to i
        for (int num = 1; num <= i; num++)
        {
            printf("%d  ", num);
        }

        // Print descending numbers from i - 1 to 1
        for (int num = i - 1; num >= 1; num--)
        {
            printf("%d  ", num);
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}