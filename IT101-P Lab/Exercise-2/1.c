// Type Content here...
#include <stdio.h>
void main()
{
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
    {
        float num1, num2;
        scanf("%f%f", &num1, &num2);
        printf("Sum: %.2f\n", num1 + num2);
        break;
    }
    case 2:
    {
        float num1, num2;
        scanf("%f%f", &num1, &num2);
        printf("Difference: %.2f\n", num1 - num2);
        break;
    }
    case 3:
    {
        float num1, num2;
        scanf("%f%f", &num1, &num2);
        printf("Product: %.2f\n", num1 * num2);
        break;
    }
    case 4:
    {
        float num1, num2;
        scanf("%f%f", &num1, &num2);
        if (num2 != 0)
        {
            printf("Quotient: %.2f\n", num1 / num2);
        }
        else
        {
            printf("Division by zero is not allowed\n");
        }
        break;
    }
    case 5:
    {
        int num1, num2;
        scanf("%d%d", &num1, &num2);
        int c = num1 < num2 ? num1 : num2;
        while (c != 0)
        {

            if (num1 % c == 0 && num2 % c == 0)
            {
                printf("HCF: %d\n", c);
                break;
            }
            c--;
        }
    }
    break;
    case 6:
    {
        int p, q;
        scanf("%d%d", &p, &q);
        int c = p > q ? p : q;
        while (1)
        {
            if (c % p == 0 && c % q == 0)
            {
                printf("LCM: %d\n", c);
                break;
            }
            c++;
        }
    }
    break;
    default:
        printf("Invalid choice\n");
    }
}
